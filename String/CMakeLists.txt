cmake_minimum_required(VERSION 3.2)
project(string)

set(CMAKE_COMPILER_CXX)
set(CMAKE_CXX_FLAGS "-Wall")

find_package(unity)

include_directories(include)

add_library(${PROJECT_NAME} src/string.c)

add_executable(${PROJECT_NAME}_test test/string_test.c)
target_link_libraries(${PROJECT_NAME}_test unity ${PROJECT_NAME})
