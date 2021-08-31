cmake_minimum_required(VERSION 3.5)

project(lab2)

add_executable(lab2
  main.cpp
  complex.cpp
)

set_property(TARGET lab2 PROPERTY CXX_STANDART 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
