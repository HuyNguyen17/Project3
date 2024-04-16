cmake_minimum_required(VERSION 3.25)
project(Project3)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(Project3
        src/game.cpp
        src/game.h
        src/graph.cpp
        src/graph.h
        src/main.cpp)
