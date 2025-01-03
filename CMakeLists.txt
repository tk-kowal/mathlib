cmake_minimum_required(VERSION 3.31)
project(lamath VERSION 1.0)
include(FetchContent)
include(GoogleTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY build/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY build/out)


FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
FetchContent_MakeAvailable(googletest)

# Build Tests
file(GLOB_RECURSE TESTS "test/*.cc")

add_library(lamath INTERFACE)
target_include_directories(lamath INTERFACE ${CMAKE_SOURCE_DIR}/lamath)

add_executable(
    lamath_tests
    ${TESTS}
)

target_link_libraries(
    lamath_tests
    PUBLIC
    GTest::gtest_main
    PRIVATE
    lamath
)

gtest_discover_tests(lamath_tests)