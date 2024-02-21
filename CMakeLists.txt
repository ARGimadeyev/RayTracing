cmake_minimum_required(VERSION 3.27)
project(RayTracing)

set(CMAKE_CXX_STANDARD 14)

add_executable(RayTracing
        main.cpp
        Output/Output.h
        Output/Output.cpp
        geom/geom.cpp)
