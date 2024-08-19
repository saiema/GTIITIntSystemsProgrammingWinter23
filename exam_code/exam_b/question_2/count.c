#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned char boolean;

int count(const int size, void * values[size], boolean (*accept)(void * arg));

boolean is_even(void * arg) {
    int arg_as_int = * (int *) arg;
    return arg_as_int % 2 == 0;
}

int main(void) {
    void * my_values[10];
    for (int i = 0; i < 10; i++) {
        int * value = (int *) malloc(sizeof(int));
        *value = i;
        my_values[i] = value;
    }
    printf("Values that are even: %d\n", count(10, my_values, is_even));
}

int count(const int size, void * values[size], boolean (*accept)(void * arg)) {
    assert (values != NULL);
    assert (accept != NULL);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (accept(values[i])) {
            count++;
        }
    }
    return count;
}