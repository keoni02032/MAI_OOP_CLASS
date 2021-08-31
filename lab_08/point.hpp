#ifndef D_POINT_HPP_
#define D_POINT_HPP_

#include <iostream>

struct point {
	double x, y;
};

std::istream& operator>> (std::istream& is, point& p);
std::ostream& operator<< (std::ostream& os, const point& p);
point operator+ (point p1, point p2);
point& operator/ (point& p, int num);

#endif