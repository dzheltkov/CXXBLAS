enable_language(C)
enable_language(Fortran)
include(FortranCInterface)
FortranCInterface_VERIFY(CXX)
find_package(BLAS REQUIRED)
FortranCInterface_HEADER(mangleinclude/BLASFortranMangle.h MACRO_NAMESPACE "BLAS_")

add_library(cxxblas BLAS_compatability.f90
                    Level1/axpy.cpp
                    Level1/copy.cpp
                    Level1/dotc.cpp
                    Level1/dotu.cpp
                    Level1/nrm2.cpp
                    Level1/rot.cpp
                    Level1/rscal.cpp
                    Level1/scal.cpp
                    Level1/swap.cpp
                    Level2/gemv.cpp
                    Level2/gerc.cpp
                    Level2/geru.cpp
                    Level2/tpsv.cpp
                    Level2/trsv.cpp
                    Level3/gemm.cpp
                    Level3/trsm.cpp
)

target_include_directories(cxxblas PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/mangleinclude)
target_link_libraries(cxxblas PUBLIC BLAS::BLAS)
