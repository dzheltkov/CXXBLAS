#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

extern "C"
{
    void sdot_stackreturn(float &,
                          const CXXBLAS_INT &,
                          const float *, const CXXBLAS_INT &,
                          const float *, const CXXBLAS_INT &);

    void ddot_stackreturn(double &,
                          const CXXBLAS_INT &,
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
        float res;
        sdot_stackreturn(res, n, x, incx, y, incy);
        return res;
    }

    double dotu(const CXXBLAS_INT &n,
                const double *x, const CXXBLAS_INT &incx,
                const double *y, const CXXBLAS_INT &incy)
    {
        double res;
        ddot_stackreturn(res, n, x, incx, y, incy);
        return res;
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
