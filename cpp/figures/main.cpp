#include <iostream>
#include <figure.hpp>

int main() {
    circle c = circle(100,100,50);
    rectangle r = rectangle(200,200,25,30);
    // no dynamic dispatching needed here
    c.draw();
    r.draw();

    // two figures in an array
    figure * v[] = {&c, &r};
    for (int i = 0; i < 2; i++) {
        // dynamic dispatching here
        v[i]->draw();
    }
}
