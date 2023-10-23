option(CXXBLAS_ASAN "Use sanitizers" OFF)
option(CXXBLAS_FCHECK "Use Fortran checks" OFF)
option(CXXBLAS_TEMPLATES "Enable templates to work with arbitrary datatypes" OFF)
option(CXXBLAS_BLAS "Use BLAS as backend for standard datatypes" ON)
option(CXXBLAS_64BIT "Use 64 bit integers for BLAS" OFF)

if (CXXBLAS_64BIT)
    set(CXXBLAS_INT int64_t)
    if (CXXBLAS_BLAS)
        set(BLA_SIZEOF_INTEGER 8)
    endif()
else()
    set(CXXBLAS_INT int32_t)
    if (CXXBLAS_BLAS)
        set(BLA_SIZEOF_INTEGER 4)
    endif()
endif()

if(NOT CXXBLAS_TEMPLATES AND NOT CXXBLAS_BLAS)
  message(
    FATAL_ERROR
    "At least one of the options CXXBLAS_TEMPLATES or CXXBLAS_BLAS should be set"
  )
endif()
