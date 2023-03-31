cmake_minimum_required(VERSION 3.5)
project(project VERSION 1.0.1)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-g -Og -Wall -pedantic -O3")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_library(structBackpack SHARED ${CMAKE_CURRENT_SOURCE_DIR}structBackpack.cpp)
add_library(structItem SHARED ${CMAKE_CURRENT_SOURCE_DIR}structItem.cpp)

add_executable(branchAndBound branchAndBound.cpp)
