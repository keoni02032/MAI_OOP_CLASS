#ifndef D_SUB_HPP_
#define D_SUB_HPP_ 1

#include <memory>
#include <vector>
#include "figure.hpp"
#include "rhombus.hpp"
#include "pentagon.hpp"
#include "hexagon.hpp"

class sub {
public:
	virtual void Print(std::vector<std::shared_ptr<figure>>& v) = 0;
};

#endif // D_SUB_HPP_