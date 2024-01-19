#ifndef WRAPPER_H
#define WRAPPER_H

#include <iostream>

template <typename T>
class wrapper {

    public:

        wrapper(const T value) : wrapped_value(value) {
            std::cout << "Calling wrapper with value " << value << std::endl;
        }

        wrapper(const wrapper<T>& other) : wrapped_value(other.wrapped_value) {
            std::cout << "Calling wrapper copy constructor " << other << std::endl;
        }

        ~wrapper() {
            std::cout << "Calling wrapper destructor on value " << wrapped_value << std::endl;
        }

        T unwrap() const {
            return wrapped_value;
        }

    private:
        T wrapped_value;

};

template<typename T>
std::ostream& operator<< (std::ostream& os, const wrapper<T> &w) {
    os << "wrapper(" << w.unwrap() << ")";
    return os;
}
#endif