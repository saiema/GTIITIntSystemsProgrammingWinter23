#ifndef MY_CLASS_A
#define MY_CLASS_A

#include <iostream>

class my_class_a {

    public:
        my_class_a();
        my_class_a(int arg_a);
        my_class_a(int arg_a, int arg_b);
        my_class_a(const my_class_a &other);
        ~my_class_a();
        int a(void);
        int b(void);

    private:
        int field_a;
        int field_b;

};

#endif