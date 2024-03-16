cmake_minimum_required(VERSION 3.28)
project(OOPproj1)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOPproj1 main.cpp
        IntSet.cpp
        IntSet.h)



set(CMAKE_CXX_FLAGS "-Wall -Wextra -g -fsanitize=leak")