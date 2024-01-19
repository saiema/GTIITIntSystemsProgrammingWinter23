#include <iostream>

template<typename T>
void insertion_sort(const int size, T value[], int (*compare_to)(T a, T b));
void print_array(const int size, int values[]);

int main() {
    int my_values[10] = {5, 2, 1, 0, 9, 12, 13, 8, 42, 10};
    std::cout << "My original array:" << std::endl;
    print_array(10, my_values);
    std::cout << std::endl;
    insertion_sort(10, my_values);
    std::cout << "My sorted array:" << std::endl;
    print_array(10, my_values);
    std::cout << std::endl;
    return 0;
}

void print_array(const int size, int values[]) {
    std::cout << "[";
    for (int i = 0; i < size; i++) {
        std::cout << values[i];
        if (i + 1 < size) {
            std::cout << ", ";
        }
    }
    std::cout << "]";
}


int find_index_to_insert(int values[], int element, int last_position) {
    for (int i = 0; i <= last_position; i++) {
        if (element < values[i]) {
            return i;
        }
    }
    return last_position + 1;
}

void shift_once_from(int values[], const int from, const int to) {
    for (int i = to; i > from; i--) {
        values[i] = values[i - 1];
    }
}

void ordered_insert(int values[], int element, int last_position) {
    if (last_position == -1) {
        values[0] = element;
        return;
    }
    int index_to_insert = find_index_to_insert(values, element, last_position);
    if (index_to_insert <= last_position) {
        shift_once_from( values, index_to_insert, last_position + 1);
    }
    values[index_to_insert] = element;
}

void insertion_sort(const int size, int value[]) {
    int last_ordered_position = -1;
    for (int i = 0; i < size; i++) {
        ordered_insert(value, value[i], last_ordered_position);
        last_ordered_position++;
    }
}