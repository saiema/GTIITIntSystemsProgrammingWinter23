#ifndef LIST_H
#define LIST_H

#include "node.hpp"
#include <cassert>
#include <iostream>

template<typename T>
class list {
    
    public:
        list() : head(NULL), field_size(0) {}

        list(list<T>& other) {
            for (int i = 0; i < other.size(); i++) {
                this->append(other.at(i));
            }
        }

        ~list() {
            std::cout << "list destructor started\n";
            node<T> * to_delete;
            node<T> * current = head;
            while (current != NULL) {
                to_delete = current;
                current = current->next();
                delete to_delete;
            }
            std::cout << "list destructor finished" << std::endl;
        }

        void append(T value) {
            if (head == NULL) {
                head = new node<T>(value);
            } else {
                node<T> * current = head;
                while (current->next() != NULL) {
                    current = current->next();
                }
                current->set_next(new node<T>(value));
            }
            field_size++;
        }

        T at(const int pos) {
            assert (pos >= 0 && pos < field_size);
            node<T> * current = head;
            for (int i = 0; i < pos; i++) {
                current = current->next();
            }
            return current->value();
        }

        int size() {
            return this->field_size;
        }

    private:
        node<T> * head;
        int field_size;

};

template <typename T>
std::ostream& operator<< (std::ostream& os, list<T>& l) {
    os << "[";
    for (int i = 0; i < l.size(); i++) {
        os << l.at(i);
        if (i + 1 < l.size()) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

#endif