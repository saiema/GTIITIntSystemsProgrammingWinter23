#include <iostream>
#include <tuple_ints.hpp>
#include <mutable_tuple_ints.hpp>

int main(void) {
    tuple t1(1, 2);
    std::cout << "(" << t1.get_fst() << ", " << t1.get_snd() << ")" << std::endl;
    mutable_tuple t2(1, 2);
    t2.set_fst(42);
    std::cout << "(" << t2.get_fst() << ", " << t2.get_snd() << ")" << std::endl;
    return 0;
}