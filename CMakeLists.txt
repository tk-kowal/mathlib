cmake_minimum_required(VERSION 3.31)
project(mathlib VERSION 1.0)
include(FetchContent)
include(GoogleTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY build/out)

# Library
add_library(mathlib INTERFACE)
target_include_directories(mathlib INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(TARGETS mathlib EXPORT mathlibConfig)
install(DIRECTORY include/ DESTINATION include/mathlib)
install(EXPORT mathlibConfig
    FILE mathlibConfig.cmake
    NAMESPACE tml::
    DESTINATION lib/cmake/mathlib
)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
    EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(googletest)

# Tests
file(GLOB_RECURSE TESTS "test/**/*.cc")

add_executable(
    mathlib_tests
    ${TESTS}
)

target_link_libraries(
    mathlib_tests
    PUBLIC
    GTest::gtest_main
    PRIVATE
    mathlib
)

target_include_directories(
    mathlib_tests
    PRIVATE
    test
)

gtest_discover_tests(mathlib_tests)

add_custom_target(
    runtests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS mathlib_tests
    COMMENT "Building and running tests"
)
