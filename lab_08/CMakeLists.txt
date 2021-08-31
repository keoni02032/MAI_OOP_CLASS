cmake_minimum_required(VERSION 3.5.1)
project(lab8)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g3 -Wextra -pthread")

add_executable(lab8 main.cpp point.cpp pentagon.cpp hexagon.cpp rhombus.cpp)