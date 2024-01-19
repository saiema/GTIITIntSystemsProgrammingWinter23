#include <classes_perm.hpp>
#include <iostream>

derived_private::derived_private() :
    base(0, 0, 0) {}

derived_private::derived_private(int pfield_value, int prtfield_value, int privfield_value) : 
    base(pfield_value, prtfield_value, privfield_value) {}

derived_private::derived_private(derived_private& other) : derived_private(other.public_field, other.protected_field, 0) {
    set_private_value(other.get_private_value());
}

derived_private::~derived_private() {
    std::cout << "Derived private destructor" << std::endl;
}

int derived_private::get_public_value() {
    return public_field;
}

int derived_private::get_protected_value() {
    return protected_field;
}

int derived_private::get_private_value() {
    return base::get_private_value();
}

int derived_private::set_public_value(int new_value) {
    int old_value = public_field;
    public_field = new_value;
    return old_value;
}

int derived_private::set_protected_value(int new_value) {
    int old_value = protected_field;
    protected_field = new_value;
    return old_value;
}

int derived_private::set_private_value(int new_value) {
    return base::set_private_value(new_value);
}