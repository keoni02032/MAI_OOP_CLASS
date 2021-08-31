#include "rhombus.h"
#include "pentagon.h"
#include "hexagon.h"
#include "templates.h"

int main() {
    int input;

    while (true) {
        std::cout << "0: Exit" << std::endl;
        std::cout << "1: Fake figure demonstration" << std::endl;
        std::cout << "2: Array figure demonstration" << std::endl;
        std::cout << "3: Real figure demonstration" << std::endl;

        std::cin >> input;

        if (input == 0) {
            break;
        }

        if (input > 3) {
            std::cout << "Invalid input" << std::endl;
        }

        switch (input) {
            case 1: {
                std::cout << "Fake rhombus (float):" << std::endl;
                std::tuple<vertex<float>, vertex<float>, vertex<float>, vertex<float>>
                        fakerhombus{{0, 0}, {0, 1}, {1, 1}, {1, 0}};
                std::cout << "Coordinates: ";
                print(fakerhombus);
                std::cout << std::endl;
                std::cout << "center: " << center(fakerhombus) << std::endl;
                std::cout << "area: " << area(fakerhombus) << std::endl;
                std::cout << "perimeter:" << perimeter(fakerhombus) << std::endl << std::endl;

                std::cout << "Fake pentagon (int):" << std::endl;
                std::tuple<vertex<int>, vertex<int>, vertex<int>, vertex<int>, vertex<int>>
                        fakepentagon{{0, 2}, {2, 4}, {4, 4}, {4, 2}, {2, 0}};
                std::cout << "Coordinates: ";
                print(fakepentagon);
                std::cout << std::endl;
                std::cout << "center: " << center(fakepentagon) << std::endl;
                std::cout << "area: " << area(fakepentagon) << std::endl;
                std::cout << "perimeter:" << perimeter(fakepentagon) << std::endl << std::endl;

                std::cout << "Fake hexagon (double):" << std::endl;
                std::tuple<vertex<double>, vertex<double>, vertex<double>, vertex<double>, vertex<double>, vertex<double>>
                        fakehexagon{{0, 5}, {1, 5}, {2, 5}, {2, 0}, {1, 0}, {0, 0}};
                std::cout << "Coordinates: ";
                print(fakehexagon);
                std::cout << std::endl;
                std::cout << "center: " << center(fakehexagon) << std::endl;
                std::cout << "area: " << area(fakehexagon) << std::endl;
                std::cout << "perimeter:" << perimeter(fakehexagon) << std::endl << std::endl;
            break;
            }

            case 2: {
                std::cout << "Array rhombus (double):" << std::endl;
                std::array<vertex<double>, 4>
                        array_rhombus{{{0, 0}, {0, 1}, {1, 1}, {1, 0}}};
                std::cout << "Coordinates: ";
                print(array_rhombus);
                std::cout << std::endl;
                std::cout << "center: " << center(array_rhombus) << std::endl;
                std::cout << "area: " << area(array_rhombus) << std::endl;
                std::cout << "perimeter: " << perimeter(array_rhombus) << std::endl << std::endl;

                std::cout << "Array hexagon (float):" << std::endl;
                std::array<vertex<float>, 6>
                        array_hexagon{{{-1, 1}, {1, 2}, {3, 2}, {3, -1}, {1, -2}, {-1, -1}}};
                std::cout << "Coordinates: ";
                print(array_hexagon);
                std::cout << std::endl;
                std::cout << "center: " << center(array_hexagon) << std::endl;
                std::cout << "area: " << area(array_hexagon) << std::endl;
                std::cout << "perimeter: " << perimeter(array_hexagon) << std::endl << std::endl;
            break;
            }

            case 3: {
                int realID;

                std::cout << "Input real figure id:" << std::endl;
                std::cout << "1: rhombus" << std::endl;
                std::cout << "2: pentagon" << std::endl;
                std::cout << "3: hexagon" << std::endl;
                
                std::cin >> realID;

                switch (realID) {
                    case 1: {
                        std::cout << "Input 4 coordinates in a sequence" << std::endl;
                        rhombus<float> realrhombus(std::cin);
                        std::cout << "Coordinates: ";
                        print(realrhombus);
                        std::cout << std::endl;
                        std::cout << "center: " << center(realrhombus) << std::endl;
                        std::cout << "area: " << area(realrhombus) << std::endl;
                        std::cout << "perimeter: " << perimeter(realrhombus) << std::endl << std::endl;
                    break;
                    }

                    case 2: {
                        std::cout << "Input 5 coordinates in a sequence" << std::endl;
                        pentagon<double> realpentagon(std::cin);
                        std::cout << "Coordinates: ";
                        print(realpentagon);
                        std::cout << std::endl;
                        std::cout << "center: " << center(realpentagon) << std::endl;
                        std::cout << "area: " << area(realpentagon) << std::endl;
                        std::cout << "perimeter: " << perimeter(realpentagon) << std::endl << std::endl;
                    break;
                    }

                    case 3: {
                        std::cout << "Input 6 coordinates in a sequence" << std::endl;
                        hexagon<double> realhexagon(std::cin);
                        std::cout << "Coordinates: ";
                        print(realhexagon);
                        std::cout << std::endl;
                        std::cout << "center: " << center(realhexagon) << std::endl;
                        std::cout << "area: " << area(realhexagon) << std::endl;
                        std::cout << "perimeter: " << perimeter(realhexagon) << std::endl << std::endl;
                    break;
                    }
                }
            break;
            }
        }
    }
    return 0;
}