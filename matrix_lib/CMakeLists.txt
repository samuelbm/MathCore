cmake_minimum_required(VERSION 3.10)
project(matrix CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Add GoogleTest
add_subdirectory(../third_party/googletest googletest_build)

# Library definitions
add_library(math_lib ../math_lib/src/math_utils.cpp)
target_include_directories(math_lib PUBLIC ../math_lib/include)

add_library(matrix_lib src/matrix.cpp)
target_include_directories(matrix_lib PUBLIC include)
target_link_libraries(matrix_lib PRIVATE math_lib)

add_library(linear_algebra_lib src/linear_algebra.cpp)
target_include_directories(linear_algebra_lib PUBLIC include)
# target_link_libraries(linear_algebra_lib PRIVATE math_lib)

add_library(matrix_utils_lib src/matrix_utils.cpp)
target_include_directories(matrix_utils_lib PUBLIC include)

# Executable definitions
add_executable(example examples/examples.cpp)
target_include_directories(example PRIVATE include ../math_lib/include)
target_link_libraries(example PRIVATE math_lib matrix_lib matrix_utils_lib)

add_executable(test_matrix tests/test_matrix.cpp)
target_include_directories(test_matrix PRIVATE include ../math_lib/include)
target_link_libraries(test_matrix PRIVATE matrix_lib gtest gtest_main)

add_executable(test_linear_algebra tests/test_linear_algebra.cpp)
target_include_directories(test_linear_algebra PRIVATE include)
target_link_libraries(test_linear_algebra PRIVATE matrix_lib linear_algebra_lib gtest gtest_main)

# Testing setup
enable_testing()
add_test(NAME MatrixCTest COMMAND test_matrix)