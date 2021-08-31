#include "complex.hpp"

std::ostream& operator << (std::ostream& os, complex& o) 
{  
    os << o.a << ' ' << o.b;  
    return os;
} 

std::istream& operator >> (std::istream& is, complex& o) {
    is >> o.a >> o.b;

    return is;
}

complex complex::operator+ (const complex &o) const {
    complex result;
    result.a = a + o.a;
    result.b = b + o.b;
    return result;
}

complex complex::operator- (const complex &o) const {
    complex result;
    result.a = a - o.a;
    result.b = b - o.b;
    return result;
}

complex complex::operator* (const complex &o) const {
    complex result;
    result.a = a * o.a - b * o.b;
    result.b = a * o.b + b * o.a;
    return result;
}

complex complex::operator/ (const complex &o) const {
    complex result;
    result.a = (a * o.a + b * o.b) / (a * a + b * b);
    result.b = (b * o.a - a * o.b) / (a * a + b * b);
    return result;
}

complex& complex::operator*= (unsigned long long num) {
    
    a = a * num;
    b = b * num;
    return *this;
}

bool complex::operator== (const complex &o) const {
    if ((a == o.a) && (b == o.b)) {
        return true;
    }
    return false;
}

complex operator"" _xn(unsigned long long first) {
    complex result(1, 2);
    result *= first;
    return result;
}

complex complex::conj() const {
    complex result;
    result.a = a;
    result.b = -b;
    return result;
}

int complex::compare_by_abs(const complex & o) const {
    double c, d;
    c = sqrt((a * a) + (b * b));
    d = sqrt((o.a * o.a) + (o.b * o.b));
    if (c == d) {
        return 0;
    } else if (c > d) {
        return -1;
    }
    return 1;
}
