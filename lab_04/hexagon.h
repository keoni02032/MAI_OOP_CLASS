#ifndef D_HEXAGON_H_
#define D_HEXAGON_H_ 1

#include <algorithm>
#include <iostream>

#include "vertex.h"

template<class T>
struct hexagon {
public:
    hexagon (std::istream& is);

    vertex<double> center() const;
    double area() const;
    double perimeter() const;
    void print() const;
private:
    vertex<T> a1, a2, a3, a4, a5, a6;
};

template <class T>
hexagon<T>::hexagon(std::istream& is) {
    is >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
}

template <class T>
vertex<double> hexagon<T>::center() const {
    vertex<T> p;
    p.x = (a1.x + a2.x + a3.x + a4.x + a5.x + a6.x) / 6;
    p.y = (a1.y + a2.y + a3.y + a4.y + a5.y + a6.y) / 6;
    return p;
}

template <class T>
double hexagon<T>::area() const {
    const T s1 = 0.5 * abs((a2.x - a1.x) * (a3.y - a1.y) - (a3.x - a1.x) * (a2.y - a1.y));
    const T s2 = 0.5 * abs((a3.x - a1.x) * (a4.y - a1.y) - (a4.x - a1.x) * (a3.y - a1.y));
    const T s3 = 0.5 * abs((a4.x - a1.x) * (a5.y - a1.y) - (a5.x - a1.x) * (a4.y - a1.y));
    const T s4 = 0.5 * abs((a5.x - a1.x) * (a6.y - a1.y) - (a6.x - a1.x) * (a5.y - a1.y));
    return s1 + s2 + s3 + s4;
}

template <class T>
double hexagon<T>::perimeter() const {
    const T str1 = sqrt((a2.x - a1.x) * (a2.x - a1.x) + (a2.y - a1.y) * (a2.y - a1.y));
    const T str2 = sqrt((a3.x - a2.x) * (a3.x - a2.x) + (a3.y - a2.y) * (a3.y - a2.y));
    const T str3 = sqrt((a4.x - a3.x) * (a4.x - a3.x) + (a4.y - a3.y) * (a4.y - a3.y));
    const T str4 = sqrt((a5.x - a4.x) * (a5.x - a4.x) + (a5.y - a4.y) * (a5.y - a4.y));
    const T str5 = sqrt((a6.x - a5.x) * (a6.x - a5.x) + (a6.y - a5.y) * (a6.y - a5.y));
    const T str6 = sqrt((a1.x - a6.x) * (a1.x - a6.x) + (a1.y - a6.y) * (a1.y - a6.y));
    return str1 + str2 + str3 + str4 + str5 + str6;
}

template <class T>
void hexagon<T>::print() const {
    std::cout << a1 << ' ' << a2 << ' ' << a3 << ' ' << a4 << ' ' << a5 << ' ' << a6 << '\n';
}

#endif