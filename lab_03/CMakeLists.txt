cmake_minimum_required(VERSION 3.5)

project(lab1)

add_executable(lab1
  main.cpp
  point.cpp
  pentagon.cpp
  hexagon.cpp
  rhombus.cpp

)

set_property(TARGET lab1 PROPERTY CXX_STANDART 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
