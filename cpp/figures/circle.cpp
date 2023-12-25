#include <iostream>
#include <figure.hpp>

# define PI 3.14159265358979323846

// circle implementation
circle::circle(int x, int y, float r) : radius(r) {
    center_x = x;
    center_y = y;
}

void circle::draw() {
    std::cout << "circle@(" 
        << center_x << ", " 
        << center_y << ") with radius " 
        << radius;
}

float circle::area() {
    return PI * radius * radius;
}