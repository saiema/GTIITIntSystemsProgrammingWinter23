#include <iostream>
#include <classes_perm.hpp>

int main() {
    base b;
    derived_public dpub;
    derived_protected dprot;
    derived_private dpriv;
    std::cout << b.public_field << std::endl;
    std::cout << dpub.public_field << std::endl;
    std::cout << dprot.public_field << std::endl;
}