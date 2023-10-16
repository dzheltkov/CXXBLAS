#ifndef CXXBLAS_LEVEL2_HPP
#define CXXBLAS_LEVEL2_HPP
namespace BLAS
{
    template <class DataType>
        void gemv(const char &transpose,
                  const CXXBLAS_INT &m, const CXXBLAS_INT &n,
                  const DataType &alpha,
                  const DataType *A, const CXXBLAS_INT &ldA,
                  const DataType *x, const CXXBLAS_INT &incx,
                  const DataType &beta,
                  DataType *y, const CXXBLAS_INT &incy);

    template <class DataType>
        void gerc(const CXXBLAS_INT &m, const CXXBLAS_INT &n,
                  const DataType &alpha,
                  const DataType *x, const CXXBLAS_INT &incx,
                  const DataType *y, const CXXBLAS_INT &incy,
                  DataType *A, const CXXBLAS_INT &ldA);

    template <class DataType>
        void geru(const CXXBLAS_INT &m, const CXXBLAS_INT &n,
                  const DataType &alpha,
                  const DataType *x, const CXXBLAS_INT &incx,
                  const DataType *y, const CXXBLAS_INT &incy,
                  DataType *A, const CXXBLAS_INT &ldA);

    template <class DataType>
        void tpsv(const char &UpperLower,
                  const char &transpose,
                  const char &diagonal,
                  const CXXBLAS_INT &n,
                  const DataType *A,
                  DataType *x, const CXXBLAS_INT &incx);

    template <class DataType>
        void trsv(const char &UpperLower,
                  const char &transpose,
                  const char &diagonal,
                  const CXXBLAS_INT &n,
                  const DataType *A, const CXXBLAS_INT &ldA,
                  DataType *x, const CXXBLAS_INT &incx);
}

#include "Level2/gemv.hpp"
#include "Level2/gerc.hpp"
#include "Level2/geru.hpp"
#include "Level2/tpsv.hpp"
#include "Level2/trsv.hpp"
#endif
