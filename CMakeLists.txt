cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 11)
project(CXXBLAS VERSION 0.1 DESCRIPTION "C++ interface to BLAS functions" LANGUAGES CXX)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
    FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) \
and run CMake from there."
  )
endif()


option(CXXBLAS_ASAN "Use sanitizers" OFF)
option(CXXBLAS_FCHECK "Use Fortran checks" OFF)
option(CXXBLAS_TEMPLATES "Enable templates to work with arbitrary datatypes" OFF)
option(CXXBLAS_BLAS "Use BLAS as backend for standard datatypes" ON)
option(CXXBLAS_64BIT "Use 64 bit integers for BLAS" OFF)

if (CXXBLAS_64BIT)
    set(CXXBLAS_INT int64_t)
    set(BLA_SIZEOF_INTEGER 8)
else()
    set(CXXBLAS_INT int32_t)
    set(BLA_SIZEOF_INTEGER 8)
endif()

if(NOT CXXBLAS_TEMPLATES AND NOT CXXBLAS_BLAS)
  message(
    FATAL_ERROR
    "At least one of the options CXXBLAS_TEMPLATES or CXXBLAS_BLAS should be set"
  )
endif()

if (NOT CMAKE_BUILD_TYPE) # if CMAKE_BUILD_TYPE is undefined
    set(CMAKE_BUILD_TYPE Release) # set it to Release
endif()

include(GNUInstallDirs)


if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS_DEBUG "-Og -g -Wall -Wextra -pedantic")
    if (USE_ASAN)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize-recover")
    endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel" OR CMAKE_CXX_COMPILER_ID STREQUAL "IntelLLVM")
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -Wall")
endif()

if (CMAKE_Fortran_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_Fortran_FLAGS_DEBUG "-Og -g -Wall -Wextra -pedantic")
    if (USE_ASAN)
        set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -fsanitize=address -fsanitize-recover")
    endif()
    if (USE_FCHECK)
        set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -fcheck=all")
    endif()
elseif (CMAKE_Fortran_COMPILER_ID STREQUAL "Intel" OR CMAKE_Fortran_COMPILER_ID STREQUAL "IntelLLVM")
    set(CMAKE_Fortran_FLAGS_DEBUG "-O0 -g -warn all")
    if (USE_FCHECK)
        set(CMAKE_Fortran_FLAGS "${CMAKE_Fortran_FLAGS} -check all")
    endif()
endif()

if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_C_FLAGS_DEBUG "-Og -g -Wall -Wextra -pedantic")
    if (USE_ASAN)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fsanitize-recover")
    endif()
elseif (CMAKE_C_COMPILER_ID STREQUAL "Intel" OR CMAKE_C_COMPILER_ID STREQUAL "IntelLLVM")
    set(CMAKE_C_FLAGS_DEBUG "-O0 -g -Wall")
endif()

configure_file(CXXBLAS_config.h.in ${PROJECT_BINARY_DIR}/include/CXXBLAS_config.h)

if (CXXBLAS_BLAS)
    enable_language(C)
    enable_language(Fortran)
    include(FortranCInterface)
    FortranCInterface_VERIFY(CXX)
    find_package(BLAS REQUIRED)
    FortranCInterface_HEADER(mangleinclude/BLASFortranMangle.h MACRO_NAMESPACE "BLAS_")

    add_library(cxxblas src/BLAS_compatability.f90
                        src/Level1/axpy.cpp
                        src/Level1/copy.cpp
                        src/Level1/dotc.cpp
                        src/Level1/dotu.cpp
                        src/Level1/nrm2.cpp
                        src/Level1/rot.cpp
                        src/Level1/rscal.cpp
                        src/Level1/scal.cpp
                        src/Level1/swap.cpp
                        src/Level2/gemv.cpp
                        src/Level2/gerc.cpp
                        src/Level2/geru.cpp
                        src/Level2/tpsv.cpp
                        src/Level2/trsv.cpp
                        src/Level3/gemm.cpp
                        src/Level3/trsm.cpp
                    )

    target_include_directories(cxxblas PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/mangleinclude)
    target_link_libraries(cxxblas PUBLIC BLAS::BLAS)
endif()

if (CXXBLAS_TEMPLATES)
    find_package(OpenMP COMPONENTS CXX REQUIRED)
    if (NOT CXXBLAS_BLAS)
        add_library(cxxblas INTERFACE)
    endif()
    target_link_libraries(cxxblas OpenMP::OpenMP_CXX)
endif()


target_include_directories(cxxblas PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                          $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
                                          $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_compile_definitions(cxxblas PRIVATE $<$<CONFIG:Debug>:DEBUG>)
add_library(BLAS::BLAS_CXX ALIAS cxxblas)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY "${PROJECT_BINARY_DIR}/include/" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(
        TARGETS cxxblas
        EXPORT CXXBLASTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

set(CXXBLAS_CMAKE_PACKAGE_INSTALL_SUBDIR "share/CXXBLAS/cmake")

install(
        EXPORT CXXBLASTargets
        NAMESPACE ::
        DESTINATION ${CXXBLAS_CMAKE_PACKAGE_INSTALL_SUBDIR})

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
                                 CXXBLASConfigVersion.cmake
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY SameMinorVersion)

configure_package_config_file(
                              "${PROJECT_SOURCE_DIR}/cmake/CXXBLASConfig.cmake.in" CXXBLASConfig.cmake
                              INSTALL_DESTINATION ${CXXBLAS_CMAKE_PACKAGE_INSTALL_SUBDIR})

install(FILES "${PROJECT_BINARY_DIR}/CXXBLASConfig.cmake"
              "${PROJECT_BINARY_DIR}/CXXBLASConfigVersion.cmake"
        DESTINATION ${CXXBLAS_CMAKE_PACKAGE_INSTALL_SUBDIR})

