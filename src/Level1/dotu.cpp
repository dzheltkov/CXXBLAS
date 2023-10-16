#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define sdotu BLAS_GLOBAL(sdotu,SDOTU)
#define ddotu BLAS_GLOBAL(ddotu,DDOTU)

extern "C"
{
    float sdotu(const CXXBLAS_INT &,
                const float *, const CXXBLAS_INT &,
                const float *, const CXXBLAS_INT &);

    double ddotu(const CXXBLAS_INT &,
                 const double *, const CXXBLAS_INT &,
                 const double *, const CXXBLAS_INT &);

    void cdotu_stackreturn(std::complex<float> &,
                           const CXXBLAS_INT &,
                           const std::complex<float> *, const CXXBLAS_INT &,
                           const std::complex<float> *, const CXXBLAS_INT &);

    void zdotu_stackreturn(std::complex<double> &,
                           const CXXBLAS_INT &,
                           const std::complex<double> *, const CXXBLAS_INT &,
                           const std::complex<double> *, const CXXBLAS_INT &);
}

namespace BLAS
{
    float dotu(const CXXBLAS_INT &n,
               const float *x, const CXXBLAS_INT &incx,
               const float *y, const CXXBLAS_INT &incy)
    {
        return sdotu(n, x, incx, y, incy);
    }

    double dotu(const CXXBLAS_INT &n,
                const double *x, const CXXBLAS_INT &incx,
                const double *y, const CXXBLAS_INT &incy)
    {
        return ddotu(n, x, incx, y, incy);
    }

    std::complex<float> dotu(const CXXBLAS_INT &n,
                             const std::complex<float> *x, const CXXBLAS_INT &incx,
                             const std::complex<float> *y, const CXXBLAS_INT &incy)
    {
        std::complex<float> res;
        cdotu_stackreturn(res, n, x, incx, y, incy);
        return res;
    }

    std::complex<double> dotu(const CXXBLAS_INT &n,
                              const std::complex<double> *x, const CXXBLAS_INT &incx,
                              const std::complex<double> *y, const CXXBLAS_INT &incy)
    {
        std::complex<double> res;
        zdotu_stackreturn(res, n, x, incx, y, incy);
        return res;
    }
}
