#ifndef OPTIONAL_H
#define OPTIONAL_H

#include <cassert>
#include <iostream>

template <typename T>
class optional {
    public:
        virtual bool is_empty() = 0;
        virtual T value() = 0;
        virtual void print() = 0;
};

template <typename T>
class just: public optional<T> {

    public:
        just(T value) {
            fvalue = value;
        }
        bool is_empty() {
            return false;
        }
        T value() {
            return fvalue;
        }
        ~just() {};
        void print() {
            std::cout << "JUST (" << fvalue << ")";
        }

    private:
        T fvalue;

};

template<typename T>
class nothing: public optional<T> {

    public:
        nothing() {};
        bool is_empty() {
            return true;
        }
        T value() {
            assert(false);
        }
        ~nothing() {};
        void print() {
            std::cout << "NOTHING";
        }

};

#endif