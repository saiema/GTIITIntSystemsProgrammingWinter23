#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
class node {

    public:
        node(T value) : field_value(value) {}

        node(T value, node<T> * next) : field_value(value), field_next(next) {}

        node(node<T>& other) : field_value(other.value), field_next(other.next) {}

        ~node() {
            std::cout << "Node destructor" << std::endl;
        }

        T value() {
            return field_value;
        }

        node<T> * next() {
            return field_next;
        }

        void set_next(node<T> * next) {
            field_next = next;
        }

    private:
        T field_value;
        node<T> * field_next;

};

#endif