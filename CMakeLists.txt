cmake_minimum_required(VERSION 3.15)
project(KaraSu)

set(CMAKE_CXX_STANDARD 17)

add_executable(KaraSu main.cpp graph.cpp graph.hpp coloring.cpp coloring.hpp IO_data.cpp IO_data.hpp)