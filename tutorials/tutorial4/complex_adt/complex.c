#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

struct Complex {
    float real;
    float imaginary;
};

complex create_complex(const float real, const float imaginary) {
    struct Complex * complex_new = (struct Complex *) malloc(sizeof(struct Complex));
    complex_new->real = real;
    complex_new->imaginary = imaginary;
    return complex_new;
}

#define COMPLEX_STRING_FORMAT "%g + %gi"

char * complex_representation(const complex const complex_value) {
    size_t size = (size_t) snprintf(NULL, 0, COMPLEX_STRING_FORMAT, complex_value->real, complex_value->imaginary);
    char * rep = (char *) malloc(size + 1); //we need space for the ending 0
    snprintf(rep, size+1, COMPLEX_STRING_FORMAT, complex_value->real, complex_value->imaginary);
    return rep;
}

complex complex_addition(const complex const complex_a, const complex const complex_b) {
    return create_complex((complex_a->real + complex_b->real), (complex_a->imaginary + complex_b->imaginary));
}

complex complex_subtraction(const complex const complex_a, const complex const complex_b) {
    //TODO: implement
}

complex complex_multiply(const complex const complex_a, const complex const complex_b) {
    //TODO: implement
}

float complex_real(const complex const complex_val) {
    return complex_val->real;
}

float complex_imaginary(const complex const complex_val) {
    return complex_val->imaginary;
}