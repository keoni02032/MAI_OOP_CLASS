#ifndef D_PENTAGON_HPP_
#define D_PENTAGON_HPP_

#include <iostream>
#include "figure.hpp"

struct pentagon : public figure
{
	pentagon(std::istream& is);
		
	point center() const override;
	void print(std::ostream& os) const override;
	double area() const override;
private:
	point a1, a2, a3, a4, a5;
};

#endif