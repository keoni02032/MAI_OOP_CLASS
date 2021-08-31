#ifndef OOP_PENTAGON_HPP
#define OOP_PENTAGON_HPP

#include "figure.hpp"

struct pentagon : figure{
private:
    point a1,a2,a3,a4,a5;
public:
    point center() const override;
    void print(std::ostream&) const  override;
    void printFile(std::ofstream&) const  override;
    double area() const override;
    pentagon() = default;
    pentagon(std::istream& is);
    pentagon(std::ifstream& is);
};

#endif