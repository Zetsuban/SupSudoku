cmake_minimum_required(VERSION 3.13)
project(SupSudoku)

set(CMAKE_CXX_STANDARD 17)

add_executable(SupSudoku main.cpp sudokuGen.cpp sudokuGen.h)