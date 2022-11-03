cmake_minimum_required(VERSION 3.23)
project(Matrix_channel)

set(CMAKE_CXX_STANDARD 17)

add_executable(Matrix_channel main.cpp Matrix.cpp Matrix.h buffered_channel.cpp buffered_channel.h)
