cmake_minimum_required(VERSION 3.29)
project(PA3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PA3
        main.cpp
        Map.cpp
        Map.h
        Queue.cpp
        Queue.h
        RoutePlanner.cpp
        RoutePlanner.h
        Stack.cpp
        Stack.h)
