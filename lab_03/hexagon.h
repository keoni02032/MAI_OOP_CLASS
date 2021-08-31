#ifndef D_HEXAGON_H_
#define D_HEXAGON_H_

#include <iostream>
#include "figure.h"

struct hexagon : figure
{
	hexagon(std::istream& is);
	
	point center() const override;
	void print(std::ostream& os) const override;
	double area() const override;
private:
	point a1, a2, a3, a4, a5, a6;
};

#endif