#include <iostream>
#include <classes.hpp>

my_class_a::my_class_a() {
    std::cout << "Empty constructor" << std::endl;
}

my_class_a::my_class_a(int arg_a) : field_a(arg_a), field_b(0) {
    std::cout << "One argument constructor" << std::endl;
}

my_class_a::my_class_a(int arg_a, int arg_b) : field_a(arg_a), field_b(arg_b) {
    std::cout << "Two arguments constructor" << std::endl;
}

my_class_a::my_class_a(const my_class_a &other) : field_a(other.field_a), field_b(other.field_b) {
    std::cout << "Copy constructor" << std::endl;
}

my_class_a::~my_class_a() {
    std::cout << "Destructor" << std::endl;
}

int my_class_a::a(void) {
    return field_a;
}

int my_class_a::b(void) {
    return field_b;
}