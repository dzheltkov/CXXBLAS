#ifndef CXXBLAS_LEVEL2_H
#define CXXBLAS_LEVEL2_H
namespace BLAS
{
    // Float variants of BLAS functions

    void gemv(const char &transpose,
              const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const float &alpha,
              const float *A, const CXXBLAS_INT &ldA,
              const float *x, const CXXBLAS_INT &incx,
              const float &beta,
              float *y, const CXXBLAS_INT &incy);

    void gerc(const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const float &alpha,
              const float *x, const CXXBLAS_INT &incx,
              const float *y, const CXXBLAS_INT &incy,
              float *A, const CXXBLAS_INT &ldA);

    void geru(const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const float &alpha,
              const float *x, const CXXBLAS_INT &incx,
              const float *y, const CXXBLAS_INT &incy,
              float *A, const CXXBLAS_INT &ldA);

    void tpsv(const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const float *A,
              float *x, const CXXBLAS_INT &incx);

    void trsv(const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const float *A, const CXXBLAS_INT &ldA,
              float *x, const CXXBLAS_INT &incx);



    // Double variants of BLAS functions

    void gemv(const char &transpose,
              const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const double &alpha,
              const double *A, const CXXBLAS_INT &ldA,
              const double *x, const CXXBLAS_INT &incx,
              const double &beta,
              double *y, const CXXBLAS_INT &incy);

    void gerc(const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const double &alpha,
              const double *x, const CXXBLAS_INT &incx,
              const double *y, const CXXBLAS_INT &incy,
              double *A, const CXXBLAS_INT &ldA);

    void geru(const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const double &alpha,
              const double *x, const CXXBLAS_INT &incx,
              const double *y, const CXXBLAS_INT &incy,
              double *A, const CXXBLAS_INT &ldA);

    void tpsv(const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const double *A,
              double *x, const CXXBLAS_INT &incx);

    void trsv(const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const double *A, const CXXBLAS_INT &ldA,
              double *x, const CXXBLAS_INT &incx);



    // std::complex<float> variants of BLAS functions

    void gemv(const char &transpose,
              const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const std::complex<float> &alpha,
              const std::complex<float> *A, const CXXBLAS_INT &ldA,
              const std::complex<float> *x, const CXXBLAS_INT &incx,
              const std::complex<float> &beta,
              std::complex<float> *y, const CXXBLAS_INT &incy);

    void gerc(const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const std::complex<float> &alpha,
              const std::complex<float> *x, const CXXBLAS_INT &incx,
              const std::complex<float> *y, const CXXBLAS_INT &incy,
              std::complex<float> *A, const CXXBLAS_INT &ldA);

    void geru(const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const std::complex<float> &alpha,
              const std::complex<float> *x, const CXXBLAS_INT &incx,
              const std::complex<float> *y, const CXXBLAS_INT &incy,
              std::complex<float> *A, const CXXBLAS_INT &ldA);

    void tpsv(const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const std::complex<float> *A,
              std::complex<float> *x, const CXXBLAS_INT &incx);

    void trsv(const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const std::complex<float> *A, const CXXBLAS_INT &ldA,
              std::complex<float> *x, const CXXBLAS_INT &incx);



    // std::complex<double> variants of BLAS functions

    void gemv(const char &transpose,
              const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const std::complex<double> &alpha,
              const std::complex<double> *A, const CXXBLAS_INT &ldA,
              const std::complex<double> *x, const CXXBLAS_INT &incx,
              const std::complex<double> &beta,
              std::complex<double> *y, const CXXBLAS_INT &incy);

    void gerc(const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const std::complex<double> &alpha,
              const std::complex<double> *x, const CXXBLAS_INT &incx,
              const std::complex<double> *y, const CXXBLAS_INT &incy,
              std::complex<double> *A, const CXXBLAS_INT &ldA);

    void geru(const CXXBLAS_INT &m, const CXXBLAS_INT &n,
              const std::complex<double> &alpha,
              const std::complex<double> *x, const CXXBLAS_INT &incx,
              const std::complex<double> *y, const CXXBLAS_INT &incy,
              std::complex<double> *A, const CXXBLAS_INT &ldA);

    void tpsv(const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const std::complex<double> *A,
              std::complex<double> *x, const CXXBLAS_INT &incx);

    void trsv(const char &UpperLower,
              const char &transpose,
              const char &diagonal,
              const CXXBLAS_INT &n,
              const std::complex<double> *A, const CXXBLAS_INT &ldA,
              std::complex<double> *x, const CXXBLAS_INT &incx);
}
#endif
