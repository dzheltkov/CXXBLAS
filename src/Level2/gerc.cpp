#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define sger BLAS_GLOBAL(sgerc,SGER)
#define dger BLAS_GLOBAL(dgerc,DGER)
#define cgerc BLAS_GLOBAL(cgerc,CGERC)
#define zgerc BLAS_GLOBAL(zgerc,ZGERC)

extern "C"
{
    void sger(const CXXBLAS_INT &,
              const CXXBLAS_INT &,
              const float &,
              const float *, const CXXBLAS_INT &,
              const float *, const CXXBLAS_INT &,
              float *, const CXXBLAS_INT &);

    void dger(const CXXBLAS_INT &,
              const CXXBLAS_INT &,
              const double &,
              const double *, const CXXBLAS_INT &,
              const double *, const CXXBLAS_INT &,
              double *, const CXXBLAS_INT &);

    void cgerc(const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const std::complex<float> &,
               const std::complex<float> *, const CXXBLAS_INT &,
               const std::complex<float> *, const CXXBLAS_INT &,
               std::complex<float> *, const CXXBLAS_INT &);

    void zgerc(const CXXBLAS_INT &,
               const CXXBLAS_INT &,
               const std::complex<double> &,
               const std::complex<double> *, const CXXBLAS_INT &,
               const std::complex<double> *, const CXXBLAS_INT &,
               std::complex<double> *, const CXXBLAS_INT &);
}

namespace BLAS
{
    void gerc(const CXXBLAS_INT &m,
              const CXXBLAS_INT &n,
              const float &alpha,
              const float *x, const CXXBLAS_INT &incx,
              const float *y, const CXXBLAS_INT &incy,
              float *A, const CXXBLAS_INT &ldA)
    {
        sger(m, n, alpha, x, incx, y, incy, A, ldA);
    }

    void gerc(const CXXBLAS_INT &m,
              const CXXBLAS_INT &n,
              const double &alpha,
              const double *x, const CXXBLAS_INT &incx,
              const double *y, const CXXBLAS_INT &incy,
              double *A, const CXXBLAS_INT &ldA)
    {
        dger(m, n, alpha, x, incx, y, incy, A, ldA);
    }

    void gerc(const CXXBLAS_INT &m,
              const CXXBLAS_INT &n,
              const std::complex<float> &alpha,
              const std::complex<float> *x, const CXXBLAS_INT &incx,
              const std::complex<float> *y, const CXXBLAS_INT &incy,
              std::complex<float> *A, const CXXBLAS_INT &ldA)
    {
        cgerc(m, n, alpha, x, incx, y, incy, A, ldA);
    }

    void gerc(const CXXBLAS_INT &m,
              const CXXBLAS_INT &n,
              const std::complex<double> &alpha,
              const std::complex<double> *x, const CXXBLAS_INT &incx,
              const std::complex<double> *y, const CXXBLAS_INT &incy,
              std::complex<double> *A, const CXXBLAS_INT &ldA)
    {
        zgerc(m, n, alpha, x, incx, y, incy, A, ldA);
    }
}
