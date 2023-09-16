cmake_minimum_required(VERSION 3.16)
project(jones_pa1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)

add_executable(jones_pa1 wrapper.cpp main.cpp)