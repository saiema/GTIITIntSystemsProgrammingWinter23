#include <iostream>
#include <cassert>

template <typename T>
T max(const int size, T values[]) {
    assert (size > 0);
    assert (values != NULL);
    T current_max = values[0];
    for (int i = 1; i < size; i++) {
        if (current_max < values[i]) {
            current_max = values[i];
        }
    }
    return current_max;
}

template <typename T>
T maximum(const int size, T values[], T (*max)(T a, T b)) {
    assert (size > 0);
    assert (values != NULL);
    assert (max != NULL);
    T current_max = values[0];
    for (int i = 1; i < size; i++) {
        current_max = max(current_max, values[i]);
    }
    return current_max;
}

template <typename T>
void print(const T value) {
    std::cout << value[0] << std::endl;
}

void increase(int& value) {
    std::cout << "Current value is " << value++ << std::endl;
}

int max(int a, int b) {
    return a > b?a:b;
}

char max(char a, char b) {
    return a > b?a:b;
}

template <int N>
void number_printer() {
    std::cout << N << std::endl;
}

int main(void) {

    // print<int>(5);
    // print<char>('h');
    // print<std::string>("Hello?");
    // int values[3] = {1, 2, 3};
    // print<int[]>(values);
    
    // int value = 1;
    // increase(value);
    // increase(value);

    // print<int>(5);
    // print<char>('h');
    // print<std::string>("Hello?");
    // int values[3] = {1, 2, 3};
    // print<int[]>(values);


    char characters[11] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd'};
    int integers[11] = {1, 3, 8, 13, 42, 6, 88, 90, 104, 99, 73};
    // float floats[11] = {3.2f, 1.0f, 13.0f, 42.83f, 3.14f, 15.89f, 99.73f, 2.2f, 183.9f, 52.5f, 0.3f};
    // char max_char = max<char>(11, characters);
    // int max_int = max<int>(11, integers);
    // float max_float = max<float>(11, floats);
    // printf("max char is %c, max int is %d, and max float is %f\n", max_char, max_int, max_float);
    int max_int = maximum<int>(11, integers, max);
    printf("Max of integers is %d\n", max_int);

    int max_char = maximum<char>(11, characters, max);
    printf("Max of characters is %c\n", max_char);
    return 0;
}