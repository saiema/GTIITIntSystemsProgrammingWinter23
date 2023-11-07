#include <stdio.h>

#define VALUE 42

unsigned char is_prime(const int value);

int main(void) {
    printf("%d is %sa Prime number\n", VALUE, is_prime(VALUE)?"":"not ");
    return 0;
}

unsigned char is_prime(const int value) {
    int divisors = 0;
    int current_divisor = 1;
    while (current_divisor <= value) {
        if (value % current_divisor == 0) {
            divisors++;
        }
        current_divisor++;
    }
    return divisors == 2;
}