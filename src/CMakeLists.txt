project(src)

include_directories(.)
add_executable(kensington main.cpp node.cpp)
add_subdirectory(UTs)
