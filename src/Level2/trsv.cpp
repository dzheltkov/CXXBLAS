#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define strsv BLAS_GLOBAL(strsv,STRSV)
#define dtrsv BLAS_GLOBAL(dtrsv,DTRSV)
#define ctrsv BLAS_GLOBAL(ctrsv,CTRSV)
#define ztrsv BLAS_GLOBAL(ztrsv,ZTRSV)

extern "C"
{
    void strsv(const char &,
               const char &,
               const char &,
               const CXXBLAS_INT &,
               const float *, const CXXBLAS_INT &,
               float *, const CXXBLAS_INT &);

    void dtrsv(const char &,
               const char &,
               const char &,
               const CXXBLAS_INT &,
               const double *, const CXXBLAS_INT &,
               double *, const CXXBLAS_INT &);

    void ctrsv(const char &,
               const char &,
               const char &,
               const CXXBLAS_INT &,
               const std::complex<float> *, const CXXBLAS_INT &,
               std::complex<float> *, const CXXBLAS_INT &);

    void ztrsv(const char &,
               const char &,
               const char &,
               const CXXBLAS_INT &,
               const std::complex<double> *, const CXXBLAS_INT &,
               std::complex<double> *, const CXXBLAS_INT &);

}

namespace BLAS
{
    void trsv(const char &UpLo,
              const char &trans,
              const char &Diag,
              const CXXBLAS_INT &n,
              const float *Ap, const CXXBLAS_INT &ldA,
              float *x, const CXXBLAS_INT &incx)
    {
        char Trans = trans;
        if (Trans == 'C' || Trans == 'c') {
            Trans = 'T';
        }
        strsv(UpLo, Trans, Diag, n, Ap, ldA, x, incx);
    }

    void trsv(const char &UpLo,
              const char &trans,
              const char &Diag,
              const CXXBLAS_INT &n,
              const double *Ap, const CXXBLAS_INT &ldA,
              double *x, const CXXBLAS_INT &incx)
    {
        char Trans = trans;
        if (Trans == 'C' || Trans == 'c') {
            Trans = 'T';
        }
        dtrsv(UpLo, Trans, Diag, n, Ap, ldA, x, incx);
    }

    void trsv(const char &UpLo,
              const char &Trans,
              const char &Diag,
              const CXXBLAS_INT &n,
              const std::complex<float> *Ap, const CXXBLAS_INT &ldA,
              std::complex<float> *x, const CXXBLAS_INT &incx)
    {
        ctrsv(UpLo, Trans, Diag, n, Ap, ldA, x, incx);
    }

    void trsv(const char &UpLo,
              const char &Trans,
              const char &Diag,
              const CXXBLAS_INT &n,
              const std::complex<double> *Ap, const CXXBLAS_INT &ldA,
              std::complex<double> *x, const CXXBLAS_INT &incx)
    {
        ztrsv(UpLo, Trans, Diag, n, Ap, ldA, x, incx);
    }
}
