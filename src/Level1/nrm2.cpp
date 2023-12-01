#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

extern "C"
{
    void snrm2_stackreturn(float &,
                           const CXXBLAS_INT &,
                           const float *, const CXXBLAS_INT &);

    void dnrm2_stackreturn(double &,
                           const CXXBLAS_INT &,
                           const double *, const CXXBLAS_INT &);

    void scnrm2_stackreturn(float &,
                            const CXXBLAS_INT &,
                            const std::complex<float> *, const CXXBLAS_INT &);

    void dznrm2_stackreturn(double &,
                            const CXXBLAS_INT &,
                            const std::complex<double> *, const CXXBLAS_INT &);
}

namespace BLAS
{
    float nrm2(const CXXBLAS_INT &n,
               const float *x, const CXXBLAS_INT &incx)
    {
        float res;
        snrm2_stackreturn(res, n, x, incx);
        return res;
    }

    double nrm2(const CXXBLAS_INT &n,
                const double *x, const CXXBLAS_INT &incx)
    {
        double res;
        dnrm2_stackreturn(res, n, x, incx);
        return res;
    }

    float nrm2(const CXXBLAS_INT &n,
               const std::complex<float> *x, const CXXBLAS_INT &incx)
    {
        float res;
        scnrm2_stackreturn(res, n, x, incx);
        return res;
    }

    double nrm2(const CXXBLAS_INT &n,
                const std::complex<double> *x, const CXXBLAS_INT &incx)
    {
        double res;
        dznrm2_stackreturn(res, n, x, incx);
        return res;
    }
}
