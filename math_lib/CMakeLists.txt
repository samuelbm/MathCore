cmake_minimum_required(VERSION 3.10)
project(matrix CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add GoogleTest
add_subdirectory(../third_party/googletest googletest_build)

# Library definitions
add_library(math_utils_lib src/math_utils.cpp)
target_include_directories(math_utils_lib PUBLIC include)

# Executable definitions
add_executable(example examples/examples.cpp)
target_link_libraries(example PRIVATE math_utils_lib)

add_executable(test_math_utils tests/test_math_utils.cpp)
target_include_directories(test_math_utils PRIVATE include)
target_link_libraries(test_math_utils PRIVATE math_utils_lib gtest gtest_main)

# Testing setup
enable_testing()
add_test(NAME MathUtilsTest COMMAND test_math_utils)