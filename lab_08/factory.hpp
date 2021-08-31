#ifndef D_FACTORY_HPP_
#define D_FACTORY_HPP_

#include <iostream>
#include <string>
#include <memory>
#include "figure.hpp"
#include "pentagon.hpp"
#include "hexagon.hpp"
#include "rhombus.hpp"

class factory {
public:
	std::shared_ptr<figure> FigureCreate(std::istream& is) {
		int command;
		std::cin >> command;
		if (command == 3) {
			std::cout << "hexagon:\n";
			std::shared_ptr<figure> f(new hexagon(is));
			return f;
		} else if (command == 2) {
			std::cout << "pentagon:\n";
			std::shared_ptr<figure> f(new pentagon(is));
			return f;
		} else if (command == 1) {
			std::cout << "rhombus:\n";
			std::shared_ptr<figure> f(new rhombus(is));
			return f;
		} else {
			throw std::logic_error("ERROR\n");
		}
	}
};

#endif //D_FACTORY_HPP_