// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppEigen.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// cpp_convolve
Rcpp::NumericVector cpp_convolve(Rcpp::NumericVector xa, Rcpp::NumericVector xb);
RcppExport SEXP _CVXR_cpp_convolve(SEXP xaSEXP, SEXP xbSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type xa(xaSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type xb(xbSEXP);
    rcpp_result_gen = Rcpp::wrap(cpp_convolve(xa, xb));
    return rcpp_result_gen;
END_RCPP
}
// multiply_dgCMatrix_vector
void multiply_dgCMatrix_vector(Rcpp::S4 A, Rcpp::NumericVector c_part);
RcppExport SEXP _CVXR_multiply_dgCMatrix_vector(SEXP ASEXP, SEXP c_partSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::S4 >::type A(ASEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type c_part(c_partSEXP);
    multiply_dgCMatrix_vector(A, c_part);
    return R_NilValue;
END_RCPP
}
// sweep_in_place
void sweep_in_place(Rcpp::NumericMatrix P, Rcpp::NumericVector c_part);
RcppExport SEXP _CVXR_sweep_in_place(SEXP PSEXP, SEXP c_partSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< Rcpp::NumericMatrix >::type P(PSEXP);
    Rcpp::traits::input_parameter< Rcpp::NumericVector >::type c_part(c_partSEXP);
    sweep_in_place(P, c_part);
    return R_NilValue;
END_RCPP
}
// upper_tri_to_full
Eigen::SparseMatrix<double> upper_tri_to_full(int n);
RcppExport SEXP _CVXR_upper_tri_to_full(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(upper_tri_to_full(n));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_CVXR_cpp_convolve", (DL_FUNC) &_CVXR_cpp_convolve, 2},
    {"_CVXR_multiply_dgCMatrix_vector", (DL_FUNC) &_CVXR_multiply_dgCMatrix_vector, 2},
    {"_CVXR_sweep_in_place", (DL_FUNC) &_CVXR_sweep_in_place, 2},
    {"_CVXR_upper_tri_to_full", (DL_FUNC) &_CVXR_upper_tri_to_full, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_CVXR(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
