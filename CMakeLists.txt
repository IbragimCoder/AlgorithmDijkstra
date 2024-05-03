cmake_minimum_required(VERSION 3.26)
project(AlgorithmDijkstra)

set(CMAKE_CXX_STANDARD 20)

add_executable(AlgorithmDijkstra main.cpp
        Graph.cpp
        Graph.h)
