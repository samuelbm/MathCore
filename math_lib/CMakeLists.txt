cmake_minimum_required(VERSION 3.10)
project(MathCore CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) 

include_directories(include)
include_directories(third_party/googletest/googletest/include)

add_library(matrix_lib src/matrix.cpp)
add_library(matrix_utils_lib src/matrix_utils.cpp)

add_executable(example examples/examples.cpp)
target_link_libraries(example matrix_lib matrix_utils_lib)

add_subdirectory(third_party/googletest googletest_build)


add_executable(test_matrix tests/test_matrix.cpp)
target_link_libraries(test_matrix matrix_lib gtest gtest_main)

enable_testing()
add_test(NAME MatrixCTest COMMAND test_matrix)