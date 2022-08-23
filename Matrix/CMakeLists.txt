cmake_minimum_required(VERSION 3.2)
project(matrix)

set(CMAKE_CXX_COMPILER)
set(CMAKE_CXX_FLAGS "-Wall")

add_subdirectory(/usr/src/gtest ${PROJECT_BINARY_DIR}/gtest)

include_directories(include ${gtest_SOURCE_DIR})

add_library(matrix src/base.cpp src/diagonal.cpp src/triangular.cpp)

enable_testing()

add_executable(matrix_diagonal_test test/matrix_diagonal_test.cpp)
target_link_libraries(matrix_diagonal_test gtest gtest_main matrix)
add_test(matrix_diagonal_test matrix_diagonal_test)