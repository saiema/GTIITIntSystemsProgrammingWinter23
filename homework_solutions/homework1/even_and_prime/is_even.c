#include <stdio.h>

#define VALUE 42

unsigned char is_even(const int value);

int main(void) {
    printf("%d is %san even number\n", VALUE, is_even(VALUE)?"":"not ");
    return 0;
}

unsigned char is_even(const int value) {
    return value % 2 == 0;
}