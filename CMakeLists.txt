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

# Library
add_library(lamath INTERFACE)
target_include_directories(lamath INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/lamath>
    $<INSTALL_INTERFACE:include/lamath>
)

install(TARGETS lamath EXPORT lamathConfig)
install(DIRECTORY lamath/ DESTINATION include/lamath)
install(EXPORT lamathConfig
    FILE lamathConfig.cmake
    NAMESPACE lamath::
    DESTINATION lib/cmake/lamath
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

target_include_directories(
    lamath_tests
    PRIVATE
    test
)

gtest_discover_tests(lamath_tests)

add_custom_target(
    runtests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS lamath_tests
    COMMENT "Building and running tests"
)
