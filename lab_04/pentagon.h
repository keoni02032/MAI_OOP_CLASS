#ifndef D_PENTAGON_H_
#define D_PENTAGON_H_ 1

#include <algorithm>
#include <iostream>

#include "vertex.h"

template<class T>
struct pentagon {
public:
    pentagon(std::istream& is);

    vertex<double> center() const;
    double area() const;
    double perimeter() const;
    void print() const;
private:
    vertex<T> a1, a2, a3, a4, a5;
};


template <class T>
pentagon<T>::pentagon(std::istream& is) {
    is >> a1 >> a2 >> a3 >> a4 >> a5;
}

template <class T>
vertex<double> pentagon<T>::center() const {
    vertex<double> p;
    p.x = (a1.x + a2.x + a3.x + a4.x + a5.x) / 5;
    p.y = (a1.y + a2.y + a3.y + a4.y + a5.y) / 5;
    return p;
}

template <class T>
double pentagon<T>::area() const {
    const T s1 = 0.5 * abs((a2.x - a1.x) * (a3.y - a1.y) - (a3.x - a1.x) * (a2.y - a1.y));
    const T s2 = 0.5 * abs((a3.x - a1.x) * (a4.y - a1.y) - (a4.x - a1.x) * (a3.y - a1.y));
    const T s3 = 0.5 * abs((a4.x - a1.x) * (a5.y - a1.y) - (a5.x - a1.x) * (a4.y - a1.y));
    return s1 + s2 + s3;
}

template <class T>
double pentagon<T>::perimeter() const {
    const T str1 = sqrt((a2.x - a1.x) * (a2.x - a1.x) + (a2.y - a1.y) * (a2.y - a1.y));
    const T str2 = sqrt((a3.x - a2.x) * (a3.x - a2.x) + (a3.y - a2.y) * (a3.y - a2.y));
    const T str3 = sqrt((a4.x - a3.x) * (a4.x - a3.x) + (a4.y - a3.y) * (a4.y - a3.y));
    const T str4 = sqrt((a5.x - a4.x) * (a5.x - a4.x) + (a5.y - a4.y) * (a5.y - a4.y));
    const T str5 = sqrt((a1.x - a5.x) * (a1.x - a5.x) + (a1.y - a5.y) * (a1.y - a5.y));
    return str1 + str2 + str3 + str4 + str5;
}

template <class T>
void pentagon<T>::print() const {
    std::cout << a1 << ' ' << a2 << ' ' << a3 << ' ' << a4 << ' ' << a5 << '\n';
}

#endif