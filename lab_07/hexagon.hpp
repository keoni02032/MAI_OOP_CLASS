#ifndef D_HEXAGON_HPP_
#define D_HEXAGON_HPP_

#include <iostream>
#include "figure.hpp"

struct hexagon : figure
{
	point center() const override ;
    void print(std::ostream&) const  override ;
    void printFile(std::ofstream&) const  override ;
    double area() const override ;
    hexagon() = default;
    hexagon(std::istream& is);
    hexagon(std::ifstream& is);
private:
	point a1, a2, a3, a4, a5, a6;
};

#endif