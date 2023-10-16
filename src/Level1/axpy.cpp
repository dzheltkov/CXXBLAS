#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define saxpy BLAS_GLOBAL(saxpy,SAXPY)
#define daxpy BLAS_GLOBAL(daxpy,DAXPY)
#define caxpy BLAS_GLOBAL(caxpy,CAXPY)
#define zaxpy BLAS_GLOBAL(zaxpy,ZAXPY)

extern "C"
{
    void saxpy(const CXXBLAS_INT &,
               const float &,
               const float *, const CXXBLAS_INT &,
               float *, const CXXBLAS_INT &);

    void daxpy(const CXXBLAS_INT &,
               const double &,
               const double *, const CXXBLAS_INT &,
               double *, const CXXBLAS_INT &);

    void caxpy(const CXXBLAS_INT &,
               const std::complex<float> &,
               const std::complex<float> *, const CXXBLAS_INT &,
               std::complex<float> *, const CXXBLAS_INT &);

    void zaxpy(const CXXBLAS_INT &,
               const std::complex<double> &,
               const std::complex<double> *, const CXXBLAS_INT &,
               std::complex<double> *, const CXXBLAS_INT &);
}

namespace BLAS
{
    void axpy(const CXXBLAS_INT &n,
              const float &alpha,
              const float *x, const CXXBLAS_INT &incx,
              float *y, const CXXBLAS_INT &incy)
    {
        saxpy(n, alpha, x, incx, y, incy);
    }

    void axpy(const CXXBLAS_INT &n,
              const double &alpha,
              const double *x, const CXXBLAS_INT &incx,
              double *y, const CXXBLAS_INT &incy)
    {
        daxpy(n, alpha, x, incx, y, incy);
    }

    void axpy(const CXXBLAS_INT &n,
              const std::complex<float> &alpha,
              const std::complex<float> *x, const CXXBLAS_INT &incx,
              std::complex<float> *y, const CXXBLAS_INT &incy)
    {
        caxpy(n, alpha, x, incx, y, incy);
    }

    void axpy(const CXXBLAS_INT &n,
              const std::complex<double> &alpha,
              const std::complex<double> *x, const CXXBLAS_INT &incx,
              std::complex<double> *y, const CXXBLAS_INT &incy)
    {
        zaxpy(n, alpha, x, incx, y, incy);
    }
}
