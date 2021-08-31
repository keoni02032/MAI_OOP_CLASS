#ifndef OOP_01_COMPLEX_H
#define OOP_01_COMPLEX_H

#include <iostream>
#include <cmath>

class complex {
public:
    complex();
    
    void read(std::istream& is);
    void write(std::ostream& os) const;

    complex add(const complex& o) const;
    complex sub(const complex & o) const;
    complex mul(const complex & o) const;
    complex div(const complex & o) const;
    bool equ(const complex & o) const;
    complex con1() const;
    int modul(const complex & o) const;
private:
    double array[2];
};

#endif