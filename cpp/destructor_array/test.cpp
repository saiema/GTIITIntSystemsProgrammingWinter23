#include <iostream>

using namespace std;

struct my_type {
    ~my_type() { cout << "destructor" << endl; };
};

int main() {
    my_type v[5];
    my_type* array = new my_type[4];
    delete array;
    return 0;
}