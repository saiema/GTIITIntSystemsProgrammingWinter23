#include <iostream>
#include <cassert>

template<typename T>
int count(const int size, T values[]);

int main() {
    return 0;
}

template<typename T>
int count(const int size, T values[], bool (*accept)(T value)) {
    assert(values != NULL);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (accept(values[i])) {
            count++;
        }
    }
    return count;
}