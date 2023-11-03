/*
* Example of a program using the `complex` Abstract Data Type
* run as ./complex
*/

#include <stdio.h>
#include <complex.h>

int main(void) {
    complex complex_a = create_complex(1.2f, 2.5f);
    complex complex_b = create_complex(4.2f, 8.5f);
    printf("Complex A: %s\n", complex_representation(complex_a));
    printf("Complex B: %s\n", complex_representation(complex_b));
    complex complex_a_plus_b = complex_addition(complex_a, complex_b);
    printf("A + B: %s\n", complex_representation(complex_a_plus_b));
    printf("The real part of A (%s) is %g\n", 
        complex_representation(complex_a),
        complex_real(complex_a)
    );
}