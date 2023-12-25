#include <iostream>
#include <figure.hpp>

// point implementation
point::point(int x, int y) : circle(x, y, 0) {}

void point::draw() {
    std::cout << "point@(" 
        << center_x << ", " 
        << center_y << ")";
}

float point::area() {
    return 0.0f;
}