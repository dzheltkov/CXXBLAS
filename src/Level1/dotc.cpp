#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define sdot BLAS_GLOBAL(sdot,SDOT)
#define ddot BLAS_GLOBAL(ddot,DDOT)

extern "C"
{
    float sdot(const CXXBLAS_INT &,
                const float *, const CXXBLAS_INT &,
                const float *, const CXXBLAS_INT &);

    double ddot(const CXXBLAS_INT &,
                 const double *, const CXXBLAS_INT &,
                 const double *, const CXXBLAS_INT &);

    void cdotc_stackreturn(std::complex<float> &,
                           const CXXBLAS_INT &,
                           const std::complex<float> *, const CXXBLAS_INT &,
                           const std::complex<float> *, const CXXBLAS_INT &);

    void zdotc_stackreturn(std::complex<double> &,
                           const CXXBLAS_INT &,
                           const std::complex<double> *, const CXXBLAS_INT &,
                           const std::complex<double> *, const CXXBLAS_INT &);
}

namespace BLAS
{
    float dotc(const CXXBLAS_INT &n,
               const float *x, const CXXBLAS_INT &incx,
               const float *y, const CXXBLAS_INT &incy)
    {
        return sdot(n, x, incx, y, incy);
    }

    double dotc(const CXXBLAS_INT &n,
                const double *x, const CXXBLAS_INT &incx,
                const double *y, const CXXBLAS_INT &incy)
    {
        return ddot(n, x, incx, y, incy);
    }

    std::complex<float> dotc(const CXXBLAS_INT &n,
                             const std::complex<float> *x, const CXXBLAS_INT &incx,
                             const std::complex<float> *y, const CXXBLAS_INT &incy)
    {
        std::complex<float> res;
        cdotc_stackreturn(res, n, x, incx, y, incy);
        return res;
    }

    std::complex<double> dotc(const CXXBLAS_INT &n,
                              const std::complex<double> *x, const CXXBLAS_INT &incx,
                              const std::complex<double> *y, const CXXBLAS_INT &incy)
    {
        std::complex<double> res;
        zdotc_stackreturn(res, n, x, incx, y, incy);
        return res;
    }
}
