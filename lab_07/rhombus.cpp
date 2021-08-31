#include <iostream>
#include <cmath>

#include "rhombus.hpp"

rhombus::rhombus(std::istream& is) {
	is >> a1 >> a2 >> a3 >> a4;
	double str1, str2, str3, str4;
	str1 = sqrt((a1.x - a2.x) * (a1.x - a2.x) + (a1.y - a2.y) * (a1.y - a2.y));
	str2 = sqrt((a2.x - a3.x) * (a2.x - a3.x) + (a2.y - a3.y) * (a2.y - a3.y));
	str3 = sqrt((a3.x - a4.x) * (a3.x - a4.x) + (a3.y - a4.y) * (a3.y - a4.y));
	str4 = sqrt((a4.x - a1.x) * (a4.x - a1.x) + (a4.y - a1.y) * (a4.y - a1.y));
	if (str1 != str2 || str2 != str3 || str3 != str4) {
		throw std::logic_error("Is not rhombus");
	}
}

rhombus::rhombus(const point& a1, const point& a2, const point& a3, const point& a4) {
	double str1, str2, str3, str4;
	str1 = sqrt((a1.x - a2.x) * (a1.x - a2.x) + (a1.y - a2.y) * (a1.y - a2.y));
	str2 = sqrt((a2.x - a3.x) * (a2.x - a3.x) + (a2.y - a3.y) * (a2.y - a3.y));
	str3 = sqrt((a3.x - a4.x) * (a3.x - a4.x) + (a3.y - a4.y) * (a3.y - a4.y));
	str4 = sqrt((a4.x - a1.x) * (a4.x - a1.x) + (a4.y - a1.y) * (a4.y - a1.y));
	if (str1 != str2 || str2 != str3 || str3 != str4) {
		throw std::logic_error("Is not rhombus");
	}
}

point rhombus::center() const {
	double x, y;
	x = (a1.x + a2.x + a3.x + a4.x) / 4;
	y = (a1.y + a2.y + a3.y + a4.y) / 4;
	point p(x, y);
	return p;
}

void rhombus::print(std::ostream& os) const {
    os << "rhombus\n" << a1 << "\n" << a2 << "\n" << a3 << "\n" << a4 << '\n';
}

double rhombus::area() const {
	point v_1;
	v_1.x = a1.x - a3.x;
	v_1.y = a1.y - a3.y;
	point v_2;
	v_2.x = a2.x - a4.x;
	v_2.y = a2.y - a4.y;
	double result = 0.5 * (sqrt(v_1.x * v_1.x + v_1.y * v_1.y) * sqrt(v_2.x * v_2.x + v_2.y * v_2.y));
	return result;
}

void rhombus::printFile(std::ofstream &of) const {
    of << "rhombus\n" << a1 << "\n" << a2 << "\n" << a3 << "\n" << a4 << '\n';
}

rhombus::rhombus(std::ifstream& is) {
    is >> a1 >> a2 >> a3 >> a4;
}