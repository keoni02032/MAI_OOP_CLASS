#include <iostream>
#include <cmath>
#include <sstream>

#include "complex.hpp"

int main()
{
    complex f, g, c;
    std::cin >> f;
    std::cin >> g;
    std::cout << f << '\n';
    std::cout << g << '\n';
    c = f + g;
    std::cout << c << '\n';
    c = f - g;
    std::cout << c << '\n';
    c = f * g;
    std::cout << c << '\n';
    c = f / g;
    std::cout << c << '\n';
    if (f == g) {
    	std::cout << "yes";
    } else {
    	std::cout << "no";
    }
    std::cout << std::endl;
    c = f.conj();
    std::cout << c << '\n';
    c = g.conj();
    std::cout << c << '\n';
    if (f.compare_by_abs(g) == 0) {
        std::cout << "a = b";
    } else if (f.compare_by_abs(g) == -1) {
        std::cout << "a > b";
    } else {
        std::cout << "a < b";
    }
    std::cout << "\n";
    c = 2_xn;
    std::cout << c << "\n";

    return 0;
}