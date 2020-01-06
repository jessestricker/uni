cmake_minimum_required(VERSION 3.13)
project(uni)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(uni
        include/uni/code_point.hpp src/code_point.cpp)
target_include_directories(uni PRIVATE include/uni)
target_include_directories(uni INTERFACE include)

add_executable(uni-test test/main.cpp
        test/code_point.cpp)
target_include_directories(uni-test PRIVATE vendor)
target_link_libraries(uni-test PRIVATE uni)
