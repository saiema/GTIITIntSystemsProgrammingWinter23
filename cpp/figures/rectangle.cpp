#include <iostream>
#include <figure.hpp>

// rectangle implementation
// constructor
rectangle::rectangle(int x, int y, float width, float height)
    : width(width), height(height) {
        center_x = x;
        center_y = y;
}

// methods
void rectangle::draw() {
    std::cout << "rectangle@(" 
        << center_x << ", " 
        << center_y << ") with width " 
        << width << " and height "
        << height;
}

float rectangle::area() {
    return width * height;
}