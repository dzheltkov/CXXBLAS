#ifndef CXXBLAS_LEVEL1_H
#define CXXBLAS_LEVEL1_H

namespace BLAS
{
    // Float variants of BLAS functions

    void axpy(const CXXBLAS_INT &n,
              const float &alpha,
              const float *x, const CXXBLAS_INT &incx,
              float *y, const CXXBLAS_INT &incy);

    void copy(const CXXBLAS_INT &n,
              const float *x, const CXXBLAS_INT &incx,
              float *y, const CXXBLAS_INT &incy);

    float dotc(const CXXBLAS_INT &n,
               const float *x, const CXXBLAS_INT &incx,
               const float *y, const CXXBLAS_INT &incy);

    float dotu(const CXXBLAS_INT &n,
               const float *x, const CXXBLAS_INT &incx,
               const float *y, const CXXBLAS_INT &incy);

    float nrm2(const CXXBLAS_INT &n,
               const float *x, const CXXBLAS_INT &incx);

    void rot(const CXXBLAS_INT &n,
             float *x, const CXXBLAS_INT &incx,
             float *y, const CXXBLAS_INT &incy,
             const float &c, const float &s);

    void rscal(const CXXBLAS_INT &n,
               const float &alpha,
               float *x, const CXXBLAS_INT &incx);

    void scal(const CXXBLAS_INT &n,
              const float &alpha,
              float *x, const CXXBLAS_INT &incx);

    void swap(const CXXBLAS_INT &n,
              float *x, const CXXBLAS_INT &incx,
              float *y, const CXXBLAS_INT &incy);



    // Double variants of BLAS functions

    void axpy(const CXXBLAS_INT &n,
              const double &alpha,
              const double *x, const CXXBLAS_INT &incx,
              double *y, const CXXBLAS_INT &incy);

    void copy(const CXXBLAS_INT &n,
              const double *x, const CXXBLAS_INT &incx,
              double *y, const CXXBLAS_INT &incy);

    double dotc(const CXXBLAS_INT &n,
                const double *x, const CXXBLAS_INT &incx,
                const double *y, const CXXBLAS_INT &incy);

    double dotu(const CXXBLAS_INT &n,
                const double *x, const CXXBLAS_INT &incx,
                const double *y, const CXXBLAS_INT &incy);

    double nrm2(const CXXBLAS_INT &n,
                const double *x, const CXXBLAS_INT &incx);

    void rot(const CXXBLAS_INT &n,
             double *x, const CXXBLAS_INT &incx,
             double *y, const CXXBLAS_INT &incy,
             const double &c, const double &s);

    void rscal(const CXXBLAS_INT &n,
               const double &alpha,
               double *x, const CXXBLAS_INT &incx);

    void scal(const CXXBLAS_INT &n,
              const double &alpha,
              double *x, const CXXBLAS_INT &incx);

    void swap(const CXXBLAS_INT &n,
              double *x, const CXXBLAS_INT &incx,
              double *y, const CXXBLAS_INT &incy);



    // std::complex<float> variants of BLAS functions

    void axpy(const CXXBLAS_INT &n,
              const std::complex<float> &alpha,
              const std::complex<float> *x, const CXXBLAS_INT &incx,
              std::complex<float> *y, const CXXBLAS_INT &incy);

    void copy(const CXXBLAS_INT &n,
              const std::complex<float> *x, const CXXBLAS_INT &incx,
              std::complex<float> *y, const CXXBLAS_INT &incy);

    std::complex<float> dotc(const CXXBLAS_INT &n,
                             const std::complex<float> *x, const CXXBLAS_INT &incx,
                             const std::complex<float> *y, const CXXBLAS_INT &incy);

    std::complex<float> dotu(const CXXBLAS_INT &n,
                             const std::complex<float> *x, const CXXBLAS_INT &incx,
                             const std::complex<float> *y, const CXXBLAS_INT &incy);

    float nrm2(const CXXBLAS_INT &n,
               const std::complex<float> *x, const CXXBLAS_INT &incx);

    void rot(const CXXBLAS_INT &n,
             std::complex<float> *x, const CXXBLAS_INT &incx,
             std::complex<float> *y, const CXXBLAS_INT &incy,
             const float &c, const std::complex<float> &s);

    void rscal(const CXXBLAS_INT &n,
               const float &alpha,
               std::complex<float> *x, const CXXBLAS_INT &incx);

    void scal(const CXXBLAS_INT &n,
              const std::complex<float> &alpha,
              std::complex<float> *x, const CXXBLAS_INT &incx);

    void swap(const CXXBLAS_INT &n,
              std::complex<float> *x, const CXXBLAS_INT &incx,
              std::complex<float> *y, const CXXBLAS_INT &incy);



    // std::complex<double> variants of BLAS functions

    void axpy(const CXXBLAS_INT &n,
              const std::complex<double> &alpha,
              const std::complex<double> *x, const CXXBLAS_INT &incx,
              std::complex<double> *y, const CXXBLAS_INT &incy);

    void copy(const CXXBLAS_INT &n,
              const std::complex<double> *x, const CXXBLAS_INT &incx,
              std::complex<double> *y, const CXXBLAS_INT &incy);

    std::complex<double> dotc(const CXXBLAS_INT &n,
                              const std::complex<double> *x, const CXXBLAS_INT &incx,
                              const std::complex<double> *y, const CXXBLAS_INT &incy);

    std::complex<double> dotu(const CXXBLAS_INT &n,
                              const std::complex<double> *x, const CXXBLAS_INT &incx,
                              const std::complex<double> *y, const CXXBLAS_INT &incy);

    double nrm2(const CXXBLAS_INT &n,
                const std::complex<double> *x, const CXXBLAS_INT &incx);

    void rot(const CXXBLAS_INT &n,
             std::complex<double> *x, const CXXBLAS_INT &incx,
             std::complex<double> *y, const CXXBLAS_INT &incy,
             const double &c, const std::complex<double> &s);

    void rscal(const CXXBLAS_INT &n,
               const double &alpha,
               std::complex<double> *x, const CXXBLAS_INT &incx);

    void scal(const CXXBLAS_INT &n,
              const std::complex<double> &alpha,
              std::complex<double> *x, const CXXBLAS_INT &incx);

    void swap(const CXXBLAS_INT &n,
              std::complex<double> *x, const CXXBLAS_INT &incx,
              std::complex<double> *y, const CXXBLAS_INT &incy);
}
#endif
