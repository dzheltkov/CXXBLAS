#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define scopy BLAS_GLOBAL(scopy,SCOPY)
#define dcopy BLAS_GLOBAL(dcopy,DCOPY)
#define ccopy BLAS_GLOBAL(ccopy,CCOPY)
#define zcopy BLAS_GLOBAL(zcopy,ZCOPY)

extern "C"
{
    void scopy(const CXXBLAS_INT &,
               const float *, const CXXBLAS_INT &,
               float *, const CXXBLAS_INT &);

    void dcopy(const CXXBLAS_INT &,
               const double *, const CXXBLAS_INT &,
               double *, const CXXBLAS_INT &);

    void ccopy(const CXXBLAS_INT &,
               const std::complex<float> *, const CXXBLAS_INT &,
               std::complex<float> *, const CXXBLAS_INT &);

    void zcopy(const CXXBLAS_INT &,
               const std::complex<double> *, const CXXBLAS_INT &,
               std::complex<double> *, const CXXBLAS_INT &);
}

namespace BLAS
{
    void copy(const CXXBLAS_INT &n,
              const float *x, const CXXBLAS_INT &incx,
              float *y, const CXXBLAS_INT &incy)
    {
        scopy(n, x, incx, y, incy);
    }

    void copy(const CXXBLAS_INT &n,
              const double *x, const CXXBLAS_INT &incx,
              double *y, const CXXBLAS_INT &incy)
    {
        dcopy(n, x, incx, y, incy);
    }

    void copy(const CXXBLAS_INT &n,
              const std::complex<float> *x, const CXXBLAS_INT &incx,
              std::complex<float> *y, const CXXBLAS_INT &incy)
    {
        ccopy(n, x, incx, y, incy);
    }

    void copy(const CXXBLAS_INT &n,
              const std::complex<double> *x, const CXXBLAS_INT &incx,
              std::complex<double> *y, const CXXBLAS_INT &incy)
    {
        zcopy(n, x, incx, y, incy);
    }
}
