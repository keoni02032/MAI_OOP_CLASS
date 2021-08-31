#include "point.hpp"

std::istream& operator>> (std::istream& is, point& p) {
	return is >> p.x >> p.y;
}

std::ostream& operator<< (std::ostream& os, const point& p) {
    return os << p.x << " " << p.y; 
}


point operator+ (point p1, point p2) {
	point p;
	p.x = p1.x + p2.x;
	p.y = p1.y + p2.y;
	return p;
}

point& operator/ (point& p, int num) {
	p.x = p.x / num;
	p.y = p.y / num;
	return p;
}