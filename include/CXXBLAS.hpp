#ifndef CXXBLAS_HPP
#define CXXBLAS_HPP
#include <complex>
#include "CXXBLAS_config.h"

#ifdef CXXBLAS_BLAS
#include "CXXBLAS/Level1.h"
#include "CXXBLAS/Level2.h"
#include "CXXBLAS/Level3.h"
#endif

#ifdef CXXBLAS_TEMPLATES
#include "CXXBLAS/Level1.hpp"
#include "CXXBLAS/Level2.hpp"
#include "CXXBLAS/Level3.hpp"
#endif
#endif
