#include <BLASFortranMangle.h>
#include "CXXBLAS_config.h"
#include <complex>

#define stpsv BLAS_GLOBAL(stpsv,STPSV)
#define dtpsv BLAS_GLOBAL(dtpsv,DTPSV)
#define ctpsv BLAS_GLOBAL(ctpsv,CTPSV)
#define ztpsv BLAS_GLOBAL(ztpsv,ZTPSV)

extern "C"
{
    void stpsv(const char &,
               const char &,
               const char &,
               const CXXBLAS_INT &,
               const float *,
               float *, const CXXBLAS_INT &);

    void dtpsv(const char &,
               const char &,
               const char &,
               const CXXBLAS_INT &,
               const double *,
               double *, const CXXBLAS_INT &);

    void ctpsv(const char &,
               const char &,
               const char &,
               const CXXBLAS_INT &,
               const std::complex<float> *,
               std::complex<float> *, const CXXBLAS_INT &);

    void ztpsv(const char &,
               const char &,
               const char &,
               const CXXBLAS_INT &,
               const std::complex<double> *,
               std::complex<double> *, const CXXBLAS_INT &);

}

namespace BLAS
{
    void tpsv(const char &UpLo,
              const char &trans,
              const char &Diag,
              const CXXBLAS_INT &n,
              const float *Ap,
              float *x, const CXXBLAS_INT &incx)
    {
        char Trans = trans;
        if (Trans == 'C' || Trans == 'c') {
            Trans = 'T';
        }
        stpsv(UpLo, Trans, Diag, n, Ap, x, incx);
    }

    void tpsv(const char &UpLo,
              const char &trans,
              const char &Diag,
              const CXXBLAS_INT &n,
              const double *Ap,
              double *x, const CXXBLAS_INT &incx)
    {
        char Trans = trans;
        if (Trans == 'C' || Trans == 'c') {
            Trans = 'T';
        }
        dtpsv(UpLo, Trans, Diag, n, Ap, x, incx);
    }

    void tpsv(const char &UpLo,
              const char &Trans,
              const char &Diag,
              const CXXBLAS_INT &n,
              const std::complex<float> *Ap,
              std::complex<float> *x, const CXXBLAS_INT &incx)
    {
        ctpsv(UpLo, Trans, Diag, n, Ap, x, incx);
    }

    void tpsv(const char &UpLo,
              const char &Trans,
              const char &Diag,
              const CXXBLAS_INT &n,
              const std::complex<double> *Ap,
              std::complex<double> *x, const CXXBLAS_INT &incx)
    {
        ztpsv(UpLo, Trans, Diag, n, Ap, x, incx);
    }
}
