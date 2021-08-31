#ifndef D_FIGURE_H_
#define D_FIGURE_H_

#include <iostream>

#include "point.h"

struct figure {
	//добавить проверку на коректность
	virtual point center() const = 0;
	virtual void print(std::ostream& os) const = 0;
	virtual double area() const = 0; // вычисление прощади

	virtual ~figure() {}
};

#endif