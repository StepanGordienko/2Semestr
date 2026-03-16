cmake_minimum_required(VERSION 3.26)
project(lab3f)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab3f lab3f.cpp)
add_executable(Book.hpp Book.cpp)
add_library(Bookshelf.hpp Bookshelf.cpp)