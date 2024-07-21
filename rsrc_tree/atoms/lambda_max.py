## CVXPY SOURCE: cvxpy/atoms/lambda_max.py
#'
#' The LambdaMax class.
#'
#' The maximum eigenvalue of a matrix, \eqn{\lambda_{\max}(A)}.
#'
#' @slot A An \linkS4class{Expression} or numeric matrix.
#' @name LambdaMax-class
#' @aliases LambdaMax
#' @rdname LambdaMax-class
.LambdaMax <- setClass("LambdaMax", representation(A = "ConstValORExpr"), contains = "Atom")

#' @param A An \linkS4class{Expression} or numeric matrix.
#' @rdname LambdaMax-class
LambdaMax <- function(A) { .LambdaMax(A = A) }

setMethod("initialize", "LambdaMax", function(.Object, ..., A) {
  .Object@A <- A
  callNextMethod(.Object, ..., atom_args = list(.Object@A))
})

#' @param object A \linkS4class{LambdaMax} object.
#' @param values A list of arguments to the atom.
#' @describeIn LambdaMax The largest eigenvalue of \code{A}. Requires that \code{A} be symmetric.
setMethod("to_numeric", "LambdaMax", function(object, values) {
  # if(any(t(values[[1]]) != values[[1]]))
  #  stop("LambdaMax called on a non-symmetric matrix")
  max(eigen(values[[1]], only.values = TRUE)$values)
})

#' @describeIn LambdaMax Returns the constraints describing the domain of the atom.
setMethod(".domain", "LambdaMax", function(object) { list(Conj(t(object@args[[1]])) == object@args[[1]]) })

#' @describeIn LambdaMax Gives the (sub/super)gradient of the atom with respect to each argument. Matrix expressions are vectorized, so the gradient is a matrix.
setMethod(".grad", "LambdaMax", function(object, values) {
  r <- base::eigen(values[[1]], only.values = FALSE)   # Eigenvalues returned in decreasing order.
  v <- r$vectors  # eigenvectors
  w <- r$values   # eigenvalues

  d <- rep(0, length(w))
  d[1] <- 1
  d <- diag(d)
  D <- v %*% d %*% t(v)
  list(Matrix(as.vector(D), sparse = TRUE))
})

#' @describeIn LambdaMax Check that \code{A} is square.
setMethod("validate_args", "LambdaMax", function(object) {
  if(ndim(object@args[[1]]) != 2 || nrow(object@args[[1]]) != ncol(object@args[[1]]))
    stop("The argument to LambdaMax must resolve to a square matrix")
})

#' @describeIn LambdaMax The atom is a scalar.
setMethod("dim_from_args", "LambdaMax", function(object) { c(1,1) })

#' @describeIn LambdaMax The sign of the atom is unknown.
setMethod("sign_from_args", "LambdaMax", function(object) { c(FALSE, FALSE) })

#' @describeIn LambdaMax The atom is convex.
setMethod("is_atom_convex", "LambdaMax", function(object) { TRUE })

#' @describeIn LambdaMax The atom is not concave.
setMethod("is_atom_concave", "LambdaMax", function(object) { FALSE })

#' @param idx An index into the atom.
#' @describeIn LambdaMax The atom is not monotonic in any argument.
setMethod("is_incr", "LambdaMax", function(object, idx) { FALSE })

#' @describeIn LambdaMax The atom is not monotonic in any argument.
setMethod("is_decr", "LambdaMax", function(object, idx) { FALSE })
