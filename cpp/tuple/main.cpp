#include <iostream>
#include <tuple_ints.hpp>

int main(void) {
    Tuple t1(1, 2);
    std::cout << "(" << t1.get_fst() << ", " << t1.get_snd() << ")" << std::endl;
    return 0; 
}