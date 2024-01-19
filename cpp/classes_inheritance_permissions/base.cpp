#include <classes_perm.hpp>
#include <iostream>

base::base() :
    public_field(0), protected_field(0), private_field(0) {}

base::base(int pfield_value, int prtfield_value, int privfield_value) : 
    public_field(pfield_value), protected_field(prtfield_value), private_field(privfield_value) {}

base::base(base& other) : base(other.public_field, other.protected_field, other.private_field) {}

base::~base() {
    std::cout << "Base destructor" << std::endl;
}

int base::get_public_value() {
    return public_field;
}

int base::get_protected_value() {
    return protected_field;
}

int base::get_private_value() {
    return private_field;
}

int base::set_public_value(int new_value) {
    int old_value = public_field;
    public_field = new_value;
    return old_value;
}

int base::set_protected_value(int new_value) {
    int old_value = protected_field;
    protected_field = new_value;
    return old_value;
}

int base::set_private_value(int new_value) {
    int old_value = private_field;
    private_field = new_value;
    return old_value;
}