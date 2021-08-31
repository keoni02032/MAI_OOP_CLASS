#ifndef OOP7_FACTORY_HPP
#define OOP7_FACTORY_HPP

#include <memory>
#include <iostream>
#include <fstream>
#include "hexagon.hpp"
#include "rhombus.hpp"
#include "pentagon.hpp"
#include <string>

struct factory {
    std::shared_ptr<figure> FigureCreate(std::istream& is);

    std::shared_ptr<figure> FigureCreateFile(std::ifstream& is);

};


#endif