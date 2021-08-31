#ifndef OOP7_FIGURE_HPP
#define OOP7_FIGURE_HPP
#include <iostream>
#include "point.hpp"
#include <fstream>

struct figure {
    virtual point center() const = 0;
    virtual void print(std::ostream&) const = 0 ;
    virtual void printFile(std::ofstream&) const = 0 ;
    virtual double area() const = 0;
    virtual ~figure() = default;
};

#endif