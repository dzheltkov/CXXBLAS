include(GNUInstallDirs)
target_include_directories(cxxblas PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                                          $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
                                          $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/include/" DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

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
                                 ${CMAKE_CURRENT_BINARY_DIR}/CXXBLASConfigVersion.cmake
                                 VERSION ${PROJECT_VERSION}
                                 COMPATIBILITY SameMinorVersion)

configure_package_config_file(
                              "${PROJECT_SOURCE_DIR}/cmake/CXXBLASConfig.cmake.in" ${CMAKE_CURRENT_BINARY_DIR}/CXXBLASConfig.cmake
                              INSTALL_DESTINATION ${CXXBLAS_CMAKE_PACKAGE_INSTALL_SUBDIR})

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/CXXBLASConfig.cmake"
              "${CMAKE_CURRENT_BINARY_DIR}/CXXBLASConfigVersion.cmake"
        DESTINATION ${CXXBLAS_CMAKE_PACKAGE_INSTALL_SUBDIR})
