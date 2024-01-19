#include "wrapper.hpp"
#include "node.hpp"
#include "list.hpp"
#include <iostream>

typedef wrapper<int> wint;

int main() {
    //wrapper<int> w1(1);
    // std::cout << w1.unwrap() << std::endl;
    //wrapper<wrapper<int>> ww1(w1);
    // std::cout << ww1.unwrap().unwrap() << std::endl;

    // // node<int> n3(3);
    // // node<int> n2(2, &n3);
    // // node<int> n1(1, &n2);

    list<int> l;
    l.append(1);
    l.append(2);
    l.append(3);
    std::cout << l << std::endl;
}