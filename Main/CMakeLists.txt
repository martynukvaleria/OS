cmake_minimum_required(VERSION 3.23)
project(Main)

set(CMAKE_CXX_STANDARD 20)

include_directories(../Vector)
include_directories(../Numbers)
find_library(VECTOR_LIB libVector.so ../Vector/cmake-build-debug)
find_library(NUM_LIB libNumbers.a ../Numbers/cmake-build-debug)

add_executable(Main main.cpp)

target_link_libraries(${PROJECT_NAME} ${VECTOR_LIB})
target_link_libraries(${PROJECT_NAME} ${NUM_LIB})
