#include <iostream>
#include <cmath>

#include "complex1.h"

int main()
{
    complex a;
    complex b;
    a.read(std::cin);
    b.read(std::cin);
    a.write(std::cout);
    std::cout << "\n";
    b.write(std::cout);
    std::cout << "\n";
    a.add(b).write(std::cout);
    std::cout << "\n";
    a.sub(b).write(std::cout);
    std::cout << "\n";
    a.mul(b).write(std::cout);
    std::cout << "\n";
    a.div(b).write(std::cout);
    std::cout << "\n";
    if (a.equ(b) == 1) {
    	std::cout << "yes";
    } else {
    	std::cout << "no";
    }
    std::cout << std::endl;
    a.con1().write(std::cout);
    std::cout << "\n";
    b.con1().write(std::cout);
    std::cout << "\n";
    if (a.modul(b) == 0) {
        std::cout << "a = b";
    } else if (a.modul(b) == -1) {
        std::cout << "a > b";
    } else {
        std::cout << "a < b";
    }
    std::cout << "\n";

    return 0;
}