cmake_minimum_required(VERSION 3.10.2)

project(lab7)

add_executable(lab7
    main.cpp point.hpp point.cpp rhombus.cpp rhombus.hpp pentagon.cpp pentagon.hpp hexagon.cpp hexagon.hpp figure.hpp command.hpp editor.hpp document.hpp factory.hpp command.cpp editor.cpp document.cpp factory.cpp)

set_property(TARGET lab7 PROPERTY CXX_STANDARD 17)