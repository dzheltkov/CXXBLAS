#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define snrm2 BLAS_GLOBAL(snrm2,SNRM2)
#define dnrm2 BLAS_GLOBAL(dnrm2,DNRM2)
#define scnrm2 BLAS_GLOBAL(scnrm2,SCNRM2)
#define dznrm2 BLAS_GLOBAL(dznrm2,DZNRM2)

extern "C"
{
    float snrm2(const CXXBLAS_INT &,
                const float *, const CXXBLAS_INT &);

    double dnrm2(const CXXBLAS_INT &,
                 const double *, const CXXBLAS_INT &);

    float scnrm2(const CXXBLAS_INT &,
                const std::complex<float> *, const CXXBLAS_INT &);

    double dznrm2(const CXXBLAS_INT &,
                 const std::complex<double> *, const CXXBLAS_INT &);
}

namespace BLAS
{
    float nrm2(const CXXBLAS_INT &n,
               const float *x, const CXXBLAS_INT &incx)
    {
        return snrm2(n, x, incx);
    }

    double nrm2(const CXXBLAS_INT &n,
                const double *x, const CXXBLAS_INT &incx)
    {
        return dnrm2(n, x, incx);
    }

    float nrm2(const CXXBLAS_INT &n,
               const std::complex<float> *x, const CXXBLAS_INT &incx)
    {
        return scnrm2(n, x, incx);
    }

    double nrm2(const CXXBLAS_INT &n,
                const std::complex<double> *x, const CXXBLAS_INT &incx)
    {
        return dznrm2(n, x, incx);
    }
}
