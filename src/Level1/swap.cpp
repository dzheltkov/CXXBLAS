#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define sswap BLAS_GLOBAL(sswap,SSWAP)
#define dswap BLAS_GLOBAL(dswap,DSWAP)
#define cswap BLAS_GLOBAL(cswap,CSWAP)
#define zswap BLAS_GLOBAL(zswap,ZSWAP)

extern "C"
{
    void sswap(const CXXBLAS_INT &,
               float *, const CXXBLAS_INT &,
               float *, const CXXBLAS_INT &);

    void dswap(const CXXBLAS_INT &,
               double *, const CXXBLAS_INT &,
               double *, const CXXBLAS_INT &);

    void cswap(const CXXBLAS_INT &,
               std::complex<float> *, const CXXBLAS_INT &,
               std::complex<float> *, const CXXBLAS_INT &);

    void zswap(const CXXBLAS_INT &,
               std::complex<double> *, const CXXBLAS_INT &,
               std::complex<double> *, const CXXBLAS_INT &);
}

namespace BLAS
{
    void swap(const CXXBLAS_INT &n,
              float *x, const CXXBLAS_INT &incx,
              float *y, const CXXBLAS_INT &incy)
    {
        sswap(n, x, incx, y, incy);
    }

    void swap(const CXXBLAS_INT &n,
              double *x, const CXXBLAS_INT &incx,
              double *y, const CXXBLAS_INT &incy)
    {
        dswap(n, x, incx, y, incy);
    }

    void swap(const CXXBLAS_INT &n,
              std::complex<float> *x, const CXXBLAS_INT &incx,
              std::complex<float> *y, const CXXBLAS_INT &incy)
    {
        cswap(n, x, incx, y, incy);
    }

    void swap(const CXXBLAS_INT &n,
              std::complex<double> *x, const CXXBLAS_INT &incx,
              std::complex<double> *y, const CXXBLAS_INT &incy)
    {
        zswap(n, x, incx, y, incy);
    }
}
