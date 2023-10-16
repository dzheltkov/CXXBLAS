#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define srot BLAS_GLOBAL(srot,SROT)
#define drot BLAS_GLOBAL(drot,DROT)
#define crot BLAS_GLOBAL(crot,CROT)
#define zrot BLAS_GLOBAL(zrot,ZROT)

extern "C"
{
    void srot(const CXXBLAS_INT &,
              float *, const CXXBLAS_INT &,
              float *, const CXXBLAS_INT &,
              const float &, const float &);

    void drot(const CXXBLAS_INT &,
              double *, const CXXBLAS_INT &,
              double *, const CXXBLAS_INT &,
              const double &, const double &);

    void crot(const CXXBLAS_INT &,
              std::complex<float> *, const CXXBLAS_INT &,
              std::complex<float> *, const CXXBLAS_INT &,
              const float &, const std::complex<float> &);

    void zrot(const CXXBLAS_INT &,
              std::complex<double> *, const CXXBLAS_INT &,
              std::complex<double> *, const CXXBLAS_INT &,
              const double &, const std::complex<double> &);
}

namespace BLAS
{
    void rot(const CXXBLAS_INT &n,
             float *x, const CXXBLAS_INT &incx,
             float *y, const CXXBLAS_INT &incy,
             const float &c, const float &s)
    {
        srot(n, x, incx, y, incy, c, s);
    }

    void rot(const CXXBLAS_INT &n,
             double *x, const CXXBLAS_INT &incx,
             double *y, const CXXBLAS_INT &incy,
             const double &c, const double &s)
    {
        drot(n, x, incx, y, incy, c, s);
    }

    void rot(const CXXBLAS_INT &n,
             std::complex<float> *x, const CXXBLAS_INT &incx,
             std::complex<float> *y, const CXXBLAS_INT &incy,
             const float &c, const std::complex<float> &s)
    {
        crot(n, x, incx, y, incy, c, s);
    }

    void rot(const CXXBLAS_INT &n,
             std::complex<double> *x, const CXXBLAS_INT &incx,
             std::complex<double> *y, const CXXBLAS_INT &incy,
             const double &c, const std::complex<double> &s)
    {
        zrot(n, x, incx, y, incy, c, s);
    }
}
