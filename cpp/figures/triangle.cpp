#include <iostream>
#include <cmath>
#include <figure.hpp>
#include <cassert>

// point implementation
triangle::triangle(int x, int y, float a, float b, float c) : a(a), b(b), c(c) {
    assert(a + b > c); //The sum of sides a and b must be greater than side c
    assert(a + c > b); //The sum of sides a and c must be greater than side b
    assert(b + c > a); //The sum of sides b and c must be greater than side a
    center_x = x;
    center_y = y;
}

void triangle::draw() {
    std::cout << "triangle@(" 
        << center_x << ", " 
        << center_y << ") " << "with sides: "
        "a (" << a << ") b (" << b << ") c (" << c << ")";
}

float triangle::area() {
    float e1 = a + b + c;
    float e2 = (-1 * a) + b + c;
    float e3 = a - b + c;
    float e4 = a + b - c;
    float the_root = sqrtf(e1 + e2 + e3 + e4);
    return (1.0f / 4.0f) * the_root;
}