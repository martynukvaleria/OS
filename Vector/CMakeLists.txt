cmake_minimum_required(VERSION 3.23)
project(Vector)

set(CMAKE_CXX_STANDARD 20)

add_library(Vector SHARED Vector.cpp)

include_directories(../Numbers)

find_library(ST_LIB libNumbers.a ../Numbers/cmake-build-debug)

target_link_libraries(${PROJECT_NAME} ${ST_LIB})