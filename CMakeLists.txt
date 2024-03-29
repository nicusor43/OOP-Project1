cmake_minimum_required(VERSION 3.28)
project(OOPproj1)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOPproj1
        main.cpp
        IntSet.cpp
        IntSet.h
        test/IntSetTest.cpp
        test/IntSetTest.h
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++20 -pedantic-errors -Werror -Wno-unused-variable -Wno-unused-parameter -Wno-unused-but-set-variable -Wno-unused-function -Wno-unused-but-set-parameter -Wno-unused-local-typedefs -Wno-unused-private-field -Wno-unused-const-variable -Wno-unused-value -fsanitize=address -g")