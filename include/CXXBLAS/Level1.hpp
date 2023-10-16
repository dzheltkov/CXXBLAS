#ifndef CXXBLAS_LEVEL1_HPP
#define CXXBLAS_LEVEL1_HPP
#include <type_traits>
#include <cmath>

namespace BLAS
{
    template <class DataType>
        void axpy(const CXXBLAS_INT &n,
                  const DataType &alpha,
                  const DataType *x, const CXXBLAS_INT &incx,
                  DataType *y, const CXXBLAS_INT &incy);

    template <class DataType>
        void copy(const CXXBLAS_INT &n,
                  const DataType *x, const CXXBLAS_INT &incx,
                  DataType *y, const CXXBLAS_INT &incy);

    template <class DataType>
        DataType dotc(const CXXBLAS_INT &n,
                  const DataType *x, const CXXBLAS_INT &incx,
                  const DataType *y, const CXXBLAS_INT &incy);

    template <class DataType>
        DataType dotu(const CXXBLAS_INT &n,
                  const DataType *x, const CXXBLAS_INT &incx,
                  const DataType *y, const CXXBLAS_INT &incy);

    template <class DataType>
        decltype(std::abs(DataType())) nrm2(const CXXBLAS_INT &n,
                                            const DataType *x, const CXXBLAS_INT &incx);

    template <class DataType>
        void rot(const CXXBLAS_INT &n,
                 DataType *x, const CXXBLAS_INT &incx,
                 DataType *y, const CXXBLAS_INT &incy,
                 const decltype(std::abs(DataType())) &c, const DataType &s);

    template <class DataType>
        void rscal(const CXXBLAS_INT &n,
                   const decltype(std::abs(DataType())) &alpha,
                   DataType *x, const CXXBLAS_INT &incx);

    template <class DataType>
        void scal(const CXXBLAS_INT &n,
                  const DataType &alpha,
                  DataType *x, const CXXBLAS_INT &incx);

    template <class DataType>
        void swap(const CXXBLAS_INT &n,
                  DataType *x, const CXXBLAS_INT &incx,
                  DataType *y, const CXXBLAS_INT &incy);
}

// Level1 BLAS functions implementations
#include "Level1/axpy.hpp"
#include "Level1/copy.hpp"
#include "Level1/dotc.hpp"
#include "Level1/dotu.hpp"
#include "Level1/nrm2.hpp"
#include "Level1/rot.hpp"
#include "Level1/rscal.hpp"
#include "Level1/scal.hpp"
#include "Level1/swap.hpp"
#endif
