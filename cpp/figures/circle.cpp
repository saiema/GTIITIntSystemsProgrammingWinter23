#include <iostream>
#include <figure.hpp>

// circle implementation
circle::circle(int x, int y, int r)
    // init: call to attribute constructors
    : center_x(x), center_y(y), radius(r)
    {}

void circle::draw() {
    std::cout << "drawing circle..." << std::endl;
}