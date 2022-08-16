cmake_minimum_required(VERSION 3.2)
project(Array)

find_package(unity REQUIRED)

set(CMAKE_CXX_COMPILER)
set(CMAKE_CXX_FLAGS "-Wall")

add_subdirectory(/usr/src/gtest ${PROJECT_BINARY_DIR}/gtest)

include_directories(include)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_library(${PROJECT_NAME} src/array.c)

add_executable(${PROJECT_NAME}_driver src/driver.c)
target_link_libraries(${PROJECT_NAME}_driver ${PROJECT_NAME})

add_executable(${PROJECT_NAME}_driver_cpp src/driver.cpp)


enable_testing()

add_executable(array_test test/array_test.c)
target_link_libraries(array_test ${PROJECT_NAME} unity)

add_executable(array_test_cpp test/array_test.cpp)
target_link_libraries(array_test_cpp gtest gtest_main)
add_test(array_test_cpp array_test_cpp)