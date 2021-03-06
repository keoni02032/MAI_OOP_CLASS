#include <iostream>
#include <cmath>

#include "pentagon.h"

pentagon::pentagon(std::istream& is) {
	is >> a1 >> a2 >> a3 >> a4 >> a5;
}

point pentagon::center() const {
	point result;
	result = a1 + a2 + a3 + a4 + a5;
	result = result / 5;
	return result;
}

void pentagon::print(std::ostream & os) const {
	os << "a1 = " << a1 << " a2 = " << a2 << " a3 = " << a3 << " a4 = " << a4 << " a5 = " << a5 << "\n";
}

double pentagon::area() const {
	double s1 = (a2.x * a3.y - a1.x * a3.y - a2.x * a1.y - a3.x * a2.y + a1.x * a2.y + a1.y * a3.x) / 2;
	double s2 = (a3.x * a4.y - a1.x * a4.y - a3.x * a1.y - a4.x * a3.y + a1.x * a3.y + a1.y * a4.x) / 2;
	double s3 = (a4.x * a5.y - a1.x * a5.y - a4.x * a1.y - a5.x * a4.y + a1.x * a4.y + a1.y * a5.x) / 2;
	double result = s1 + s2 + s3;
	if (result >= 0) {
		return result;
	} else {
		return -result;
	}
}