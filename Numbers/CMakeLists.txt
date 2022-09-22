cmake_minimum_required(VERSION 3.23)
project(Numbers)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-fPIC)
add_library(Numbers numbers.cpp)
