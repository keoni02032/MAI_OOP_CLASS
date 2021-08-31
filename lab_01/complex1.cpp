#include "complex1.h"

void complex::read(std::istream& is) {
    for (int i = 0; i < 2; ++i) {
        is >> array[i];
    }
}

void complex::write(std::ostream& os) const {
    for (int i = 0; i < 2; ++i) {
        os << array[i] << " ";
    }
}

complex::complex() {
    array[0] = 0;
    array[1] = 0;    
}

complex complex::add(const complex& o) const {
    complex result;
    for (int i = 0; i < 2; ++i) {
        result.array[i] = array[i] + o.array[i];
    }

    return result;
}

complex complex::sub(const complex& o) const {
    complex result;
    for (int i = 0; i < 2; ++i) {
        result.array[i] = array[i] - o.array[i];
    }

    return result;
}

complex complex::mul(const complex & o) const {
    complex result;
    result.array[0] = (array[0] * o.array[0]) - (array[1] * o.array[1]);
    result.array[1] = (array[0] * o.array[1]) + (array[1] * o.array[0]);
    return result;
}

complex complex::div(const complex & o) const {
    complex result;
    result.array[0] = ((array[0] * o.array[0]) + (array[1] * o.array[1])) / ((o.array[1] * o.array[1]) + (o.array[0]) * o.array[0]);
    result.array[1] = ((array[1] * o.array[0]) - (array[0] * o.array[1])) / ((o.array[0] * o.array[0]) + (o.array[1]) * o.array[1]);
    return result;
}

bool complex::equ(const complex & o) const {
    if ((array[0] == o.array[0]) && (array[1] == o.array[1])) {
        return 1;
    }
    return 0;
}

complex complex::con1() const {
    complex result;
    result.array[0] = array[0];
    result.array[1] = -array[1];
    return result;
}

int complex::modul(const complex & o) const {
    double a, b;
    a = sqrt((array[0] * array[0]) + (array[1] * array[1]));
    b = sqrt((o.array[0] * o.array[0]) + (o.array[1] * o.array[1]));
    if (a == b) {
        return 0;
    } else if (a > b) {
        return -1;
    }
    return 1;
}
