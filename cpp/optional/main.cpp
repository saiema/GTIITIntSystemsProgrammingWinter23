#include <iostream>
#include "optional.hpp"

int main() {
    int value = 42;
    optional<int> * just_int = new just<int>(value);
    optional<int> * no_int = new nothing<int>();
    just_int->print();
    std::cout << std::endl;
}