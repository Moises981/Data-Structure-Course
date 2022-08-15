cmake_minimum_required(VERSION 3.2)
project(Array)

find_package(unity)

set(CMAKE_C_COMPILER)
set(CMAKE_C_FLAGS "-Wall")

include_directories(include)

add_library(${PROJECT_NAME} src/array.c)

enable_testing()
add_executable(array_test test/array_test.c)
target_link_libraries(array_test ${PROJECT_NAME} unity)
add_test(array_test array_test)