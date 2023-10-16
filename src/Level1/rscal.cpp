#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define sscal BLAS_GLOBAL(sscal,SSCAL)
#define dscal BLAS_GLOBAL(dscal,DSCAL)
#define csscal BLAS_GLOBAL(csscal,CSSCAL)
#define zdscal BLAS_GLOBAL(zdscal,ZDSCAL)

extern "C"
{
    void sscal(const CXXBLAS_INT &,
               const float &,
               float *, const CXXBLAS_INT &);

    void dscal(const CXXBLAS_INT &,
               const double &,
               double *, const CXXBLAS_INT &);

    void csscal(const CXXBLAS_INT &,
                const float &,
                std::complex<float> *, const CXXBLAS_INT &);

    void zdscal(const CXXBLAS_INT &,
                const double &,
                std::complex<double> *, const CXXBLAS_INT &);
}

namespace BLAS
{
    void rscal(const CXXBLAS_INT &n,
               const float &alpha,
               float *x, const CXXBLAS_INT &incx)
    {
        sscal(n, alpha, x, incx);
    }

    void rscal(const CXXBLAS_INT &n,
               const double &alpha,
               double *x, const CXXBLAS_INT &incx)
    {
        dscal(n, alpha, x, incx);
    }

    void rscal(const CXXBLAS_INT &n,
               const float &alpha,
               std::complex<float> *x, const CXXBLAS_INT &incx)
    {
        csscal(n, alpha, x, incx);
    }

    void rscal(const CXXBLAS_INT &n,
               const double &alpha,
               std::complex<double> *x, const CXXBLAS_INT &incx)
    {
        zdscal(n, alpha, x, incx);
    }
}
