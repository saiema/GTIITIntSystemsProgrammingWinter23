#include <iostream>
#include <figure.hpp>

// rectangle implementation
// constructor
rectangle::rectangle(int x, int y, int w, int h)
    // init: call to attribute constructors
    : center_x(x), center_y(y), width(w), height(h)
    {}

// methods
void rectangle::draw() {
    std::cout << "drawing rectangle..." << std::endl;
}