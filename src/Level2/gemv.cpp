#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define sgemv BLAS_GLOBAL(sgemv,SGEMV)
#define dgemv BLAS_GLOBAL(dgemv,DGEMV)
#define cgemv BLAS_GLOBAL(cgemv,CGEMV)
#define zgemv BLAS_GLOBAL(zgemv,ZGEMV)

extern "C"
{
    void sgemv(const char &,
               const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const float &,
               const float *, const CXXBLAS_INT &,
               const float *, const CXXBLAS_INT &,
               const float &,
               float *, const CXXBLAS_INT &);

    void dgemv(const char &,
               const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const double &,
               const double *, const CXXBLAS_INT &,
               const double *, const CXXBLAS_INT &,
               const double &,
               double *, const CXXBLAS_INT &);

    void cgemv(const char &,
               const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const std::complex<float> &,
               const std::complex<float> *, const CXXBLAS_INT &,
               const std::complex<float> *, const CXXBLAS_INT &,
               const std::complex<float> &,
               std::complex<float> *, const CXXBLAS_INT &);

    void zgemv(const char &,
               const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const std::complex<double> &,
               const std::complex<double> *, const CXXBLAS_INT &,
               const std::complex<double> *, const CXXBLAS_INT &,
               const std::complex<double> &,
               std::complex<double> *, const CXXBLAS_INT &);
}

namespace BLAS
{
    void gemv(const char &trans,
              const CXXBLAS_INT &m,
              const CXXBLAS_INT &n,
              const float &alpha,
              const float *A, const CXXBLAS_INT &ldA,
              const float *x, const CXXBLAS_INT &incx,
              const float &beta,
              float *y, const CXXBLAS_INT &incy)
    {
        char Trans = trans;
        if (Trans == 'C' || Trans == 'c') {
            Trans = 'T';
        }
        sgemv(Trans, m, n, alpha, A, ldA, x, incx, beta, y, incy);
    }

    void gemv(const char &trans,
              const CXXBLAS_INT &m,
              const CXXBLAS_INT &n,
              const double &alpha,
              const double *A, const CXXBLAS_INT &ldA,
              const double *x, const CXXBLAS_INT &incx,
              const double &beta,
              double *y, const CXXBLAS_INT &incy)
    {
        char Trans = trans;
        if (Trans == 'C' || Trans == 'c') {
            Trans = 'T';
        }
        dgemv(Trans, m, n, alpha, A, ldA, x, incx, beta, y, incy);
    }

    void gemv(const char &T,
              const CXXBLAS_INT &m,
              const CXXBLAS_INT &n,
              const std::complex<float> &alpha,
              const std::complex<float> *A, const CXXBLAS_INT &ldA,
              const std::complex<float> *x, const CXXBLAS_INT &incx,
              const std::complex<float> &beta,
              std::complex<float> *y, const CXXBLAS_INT &incy)
    {
        cgemv(T, m, n, alpha, A, ldA, x, incx, beta, y, incy);
    }

    void gemv(const char &T,
              const CXXBLAS_INT &m,
              const CXXBLAS_INT &n,
              const std::complex<double> &alpha,
              const std::complex<double> *A, const CXXBLAS_INT &ldA,
              const std::complex<double> *x, const CXXBLAS_INT &incx,
              const std::complex<double> &beta,
              std::complex<double> *y, const CXXBLAS_INT &incy)
    {
        zgemv(T, m, n, alpha, A, ldA, x, incx, beta, y, incy);
    }
}
