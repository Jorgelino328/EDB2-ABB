cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(EDB2-ABB)

include_directories(include)

add_executable(
    EDB2-ABB
    src/main.cpp
)

target_include_directories(
    EDB2-ABB PUBLIC
    include
)