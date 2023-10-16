#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define sscal BLAS_GLOBAL(sscal,SSCAL)
#define dscal BLAS_GLOBAL(dscal,DSCAL)
#define cscal BLAS_GLOBAL(cscal,CSCAL)
#define zscal BLAS_GLOBAL(zscal,ZSCAL)

extern "C"
{
    void sscal(const CXXBLAS_INT &,
               const float &,
               float *, const CXXBLAS_INT &);

    void dscal(const CXXBLAS_INT &,
               const double &,
               double *, const CXXBLAS_INT &);

    void cscal(const CXXBLAS_INT &,
               const std::complex<float> &,
               std::complex<float> *, const CXXBLAS_INT &);

    void zscal(const CXXBLAS_INT &,
               const std::complex<double> &,
               std::complex<double> *, const CXXBLAS_INT &);
}

namespace BLAS
{
    void scal(const CXXBLAS_INT &n,
              const float &alpha,
              float *x, const CXXBLAS_INT &incx)
    {
        sscal(n, alpha, x, incx);
    }

    void scal(const CXXBLAS_INT &n,
              const double &alpha,
              double *x, const CXXBLAS_INT &incx)
    {
        dscal(n, alpha, x, incx);
    }

    void scal(const CXXBLAS_INT &n,
              const std::complex<float> &alpha,
              std::complex<float> *x, const CXXBLAS_INT &incx)
    {
        cscal(n, alpha, x, incx);
    }

    void scal(const CXXBLAS_INT &n,
              const std::complex<double> &alpha,
              std::complex<double> *x, const CXXBLAS_INT &incx)
    {
        zscal(n, alpha, x, incx);
    }
}
