cmake_minimum_required(VERSION 3.15)
project(spellslib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(spellslib INTERFACE)

target_include_directories(spellslib INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_compile_definitions(spellslib INTERFACE
    SPELLSLIB_VERSION="1.0.1"
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/spellslibConfigVersion.cmake"
    VERSION 1.0.1
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/spellslibConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/spellslibConfig.cmake"
    INSTALL_DESTINATION lib/cmake/spellslib
)

install(TARGETS spellslib EXPORT spellslibTargets)
install(EXPORT spellslibTargets
    FILE spellslibTargets.cmake
    NAMESPACE spellslib::
    DESTINATION lib/cmake/spellslib
)
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/spellslibConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/spellslibConfigVersion.cmake"
    DESTINATION lib/cmake/spellslib
)
install(DIRECTORY include/ DESTINATION include)

enable_testing()
add_subdirectory(tests)
