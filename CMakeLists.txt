project(kensington)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "--std=c++14 -g")
set(CMAKE_CXX_CLANG_TIDY "/usr/bin/clang-tidy" "-checks=*,-fuschia*")

enable_testing()
add_subdirectory(src)

