project(kensington)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "--std=c++14 -g")
enable_testing()
add_subdirectory(src)

