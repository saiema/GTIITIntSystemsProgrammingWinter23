#include <iostream>
#include <classes.hpp>


void test_my_class() {
    my_class_a a;
    my_class_a b(1);
    my_class_a c(1, 2);
    my_class_a d = c;
}

int main(void) {
    test_my_class();
}