#include <classes_perm.hpp>
#include <iostream>

derived_protected::derived_protected() :
    base(0, 0, 0) {}

derived_protected::derived_protected(int pfield_value, int prtfield_value, int privfield_value) : 
    base(pfield_value, prtfield_value, privfield_value) {}

derived_protected::derived_protected(derived_protected& other) : derived_protected(other.public_field, other.protected_field, 0) {
    set_private_value(other.get_private_value());
}

derived_protected::~derived_protected() {
    std::cout << "Derived protected destructor" << std::endl;
}

int derived_protected::get_public_value() {
    return public_field;
}

int derived_protected::get_protected_value() {
    return protected_field;
}

int derived_protected::get_private_value() {
    return base::get_private_value();
}

int derived_protected::set_public_value(int new_value) {
    int old_value = public_field;
    public_field = new_value;
    return old_value;
}

int derived_protected::set_protected_value(int new_value) {
    int old_value = protected_field;
    protected_field = new_value;
    return old_value;
}

int derived_protected::set_private_value(int new_value) {
    return base::set_private_value(new_value);
}