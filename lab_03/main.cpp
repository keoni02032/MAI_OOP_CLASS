#include <iostream>
#include <vector>

#include "figure.h"
#include "point.h"

#include "pentagon.h"
#include "hexagon.h"
#include "rhombus.h"

int main() {
    std::vector<figure*> figures;
    for (;;) {
        int command;
        std::cin >> command;
        if (command == 0) {
            break;
        } else if (command == 1) {
            int figure_type;
            std::cin >> figure_type;
            figure* ptr;
            if (figure_type == 0) {
                ptr = new rhombus(std::cin);
            } else if (figure_type == 1) {
                ptr = new pentagon(std::cin);
            }  else {
	            ptr = new hexagon(std::cin);
            }
            figures.push_back(ptr);
        } else if (command == 2) {
            int id;
            std::cin >> id;
            delete figures[id];
            figures.erase(figures.begin() + id);
            std::cout << std::endl;
        } else if (command == 3) {
            std::cout << "Centers:\n";
            for (figure* ptr: figures) {
                //std::cout << ptr->center() << std::endl;
                point p = ptr->center();
                std::cout << p << "\n" << std::endl;
            }
        } else if (command == 4) {
            std::cout << "Areas:\n";
            for (figure* ptr: figures) {
                std::cout << ptr->area() << std::endl << std::endl;
            }
        } else if (command == 5) {
            std::cout << "Figures:\n";
            for (figure* ptr: figures) {
                ptr->print(std::cout);
                std::cout << std::endl;
            }
        }
    }
    //for (figure* ptr: figures) {
      //  delete ptr;
    //}
    for (size_t i = 0; i < figures.size(); ++i) {
        delete figures[i];
    }
}