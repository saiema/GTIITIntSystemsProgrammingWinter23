#include <iostream>

template <typename T>
int index_of(const int size, T values[], T elem, bool (*equals)(T a, T b));

bool equals_int(int a, int b) {
    return a == b;
}

int main() {
    int size = 10;
    int pvalues[size];
    for (int i = 0; i < size; i++) {
        pvalues[i] = i;
    }
    int value_to_search = 7;
    std::cout << "Index of pointer to 7 is : " << index_of(size, pvalues, value_to_search, equals_int) << std::endl;
    return 0;
}

template <typename T>
int index_of(const int size, T values[], T elem, bool (*equals)(T a, T b)) {
    for (int i = 0; i < size; i++) {
        if (equals(values[i], elem)) {
            return i;
        }
    }
    return -1;
}