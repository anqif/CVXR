load_all()
suppressWarnings(library(CVXR, warn.conflicts=FALSE))

beta <- Variable(nonneg = TRUE)
objective <- Minimize(beta^2)
prob <- Problem(objective)
result <- solve(prob, verbose = TRUE)
