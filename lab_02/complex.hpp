#ifndef OOP_01_COMPLEX_HPP
#define OOP_01_COMPLEX_HPP

#include <iostream>
#include <cmath>
#include <sstream>

class complex {
public:
    complex() {
        a = 0;
        b = 0;
    }
    complex(double a, double b) : a(a), b(b)
    {}

    friend std::istream& operator >> (std::istream&, complex& o); 
    friend std::ostream& operator << (std::ostream&, complex& o);

    complex operator+ (const complex &o) const;
    complex operator- (const complex &o) const;
    complex operator* (const complex &o) const;
    complex operator/ (const complex &o) const;
    complex& operator*= (unsigned long long num);
    bool operator== (const complex &o) const;

    complex conj() const;
    int compare_by_abs(const complex & o) const;
private:
    double a, b;
};

complex operator""_xn(unsigned long long first);

#endif