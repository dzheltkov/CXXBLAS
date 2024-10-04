#ifndef CXXBLAS_LEVEL3_H
#define CXXBLAS_LEVEL3_H
namespace BLAS
{
    // Float variants of BLAS functions

    void gemm(const char &TransA,
              const char &TransB,
              const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const CXXBLAS_INT &k,
              const float &alpha,
              const float *A, const CXXBLAS_INT &ldA,
              const float *B, const CXXBLAS_INT &ldB,
              const float &beta,
              float *C, const CXXBLAS_INT &ldC);

    void trsm(const char &Side,
              const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &m,
              const float *A, const CXXBLAS_INT &ldA,
              float *B, const CXXBLAS_INT &ldB);

    void trmm(const char &Side,
              const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &m,
              const float *A, const CXXBLAS_INT &ldA,
              float *B, const CXXBLAS_INT &ldB);

    void herk(const char &UpperLower,
              const char &transpose,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &k,
              const float &alpha,
              const float *A, const CXXBLAS_INT &ldA,
              const float &beta,
              float *C, const CXXBLAS_INT &ldC);


    // Double variants of BLAS functions

    void gemm(const char &TransA,
              const char &TransB,
              const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const CXXBLAS_INT &k,
              const double &alpha,
              const double *A, const CXXBLAS_INT &ldA,
              const double *B, const CXXBLAS_INT &ldB,
              const double &beta,
              double *C, const CXXBLAS_INT &ldC);

    void trsm(const char &Side,
              const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &m,
              const double *A, const CXXBLAS_INT &ldA,
              double *B, const CXXBLAS_INT &ldB);

    void trmm(const char &Side,
              const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &m,
              const double *A, const CXXBLAS_INT &ldA,
              double *B, const CXXBLAS_INT &ldB);

    void herk(const char &UpperLower,
              const char &transpose,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &k,
              const double &alpha,
              const double *A, const CXXBLAS_INT &ldA,
              const double &beta,
              double *C, const CXXBLAS_INT &ldC);



    // std::complex<float> variants of BLAS functions

    void gemm(const char &TransA,
              const char &TransB,
              const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const CXXBLAS_INT &k,
              const std::complex<float> &alpha,
              const std::complex<float> *A, const CXXBLAS_INT &ldA,
              const std::complex<float> *B, const CXXBLAS_INT &ldB,
              const std::complex<float> &beta,
              std::complex<float> *C, const CXXBLAS_INT &ldC);

    void trsm(const char &Side,
              const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &m,
              const std::complex<float> *A, const CXXBLAS_INT &ldA,
              std::complex<float> *B, const CXXBLAS_INT &ldB);

    void trmm(const char &Side,
              const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &m,
              const std::complex<float> *A, const CXXBLAS_INT &ldA,
              std::complex<float> *B, const CXXBLAS_INT &ldB);

    void herk(const char &UpperLower,
              const char &transpose,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &k,
              const float &alpha,
              const std::complex<float> *A, const CXXBLAS_INT &ldA,
              const float &beta,
              std::complex<float> *C, const CXXBLAS_INT &ldC);



    // std::complex<double> variants of BLAS functions

    void gemm(const char &TransA,
              const char &TransB,
              const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const CXXBLAS_INT &k,
              const std::complex<double> &alpha,
              const std::complex<double> *A, const CXXBLAS_INT &ldA,
              const std::complex<double> *B, const CXXBLAS_INT &ldB,
              const std::complex<double> &beta,
              std::complex<double> *C, const CXXBLAS_INT &ldC);

    void trsm(const char &Side,
              const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &m,
              const std::complex<double> *A, const CXXBLAS_INT &ldA,
              std::complex<double> *B, const CXXBLAS_INT &ldB);

    void trmm(const char &Side,
              const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &m,
              const std::complex<double> *A, const CXXBLAS_INT &ldA,
              std::complex<double> *B, const CXXBLAS_INT &ldB);

    void herk(const char &UpperLower,
              const char &transpose,
              const CXXBLAS_INT &n,
              const CXXBLAS_INT &k,
              const double &alpha,
              const std::complex<double> *A, const CXXBLAS_INT &ldA,
              const double &beta,
              std::complex<double> *C, const CXXBLAS_INT &ldC);
}
#endif
