#ifndef D_FIGURE_HPP_
#define D_FIGURE_HPP_

#include <iostream>

#include "point.hpp"

struct figure {
	virtual point center() const = 0;
	virtual void print(std::ostream& os) const = 0;
	virtual double area() const = 0;

	virtual ~figure() {}
};

#endif