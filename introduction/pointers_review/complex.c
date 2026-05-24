#include <stdlib.h>
#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

typedef struct Complex complex;
typedef unsigned char boolean;

static complex create_complex(float real, float imaginary);
static char * string_rep_complex(complex c);
static boolean equal_complex(complex complex_a, complex complex_b);
static complex add_complex(complex complex_a, complex complex_b);
static complex subtract_complex(complex complex_a, complex complex_b);
static complex multiply_complex(complex complex_a, complex complex_b);

//Let's try to modify a complex value
void set_real(complex c, float real);
void set_imaginary(complex c, float imaginary);

int main(void) {
    complex complex_a = create_complex(1.33f, 4.2f);
    complex complex_b = create_complex(8.75f, 3.14f);
    complex complex_c = create_complex(1.33f, 4.2f);
    printf("Complex A: %s\n", string_rep_complex(complex_a));
    printf("Complex B: %s\n", string_rep_complex(complex_b));
    printf("Complex C: %s\n", string_rep_complex(complex_c));
    boolean complex_a_equals_b = equal_complex(complex_a, complex_b);
    boolean complex_a_equals_c = equal_complex(complex_a, complex_c);
    printf("%s == %s is %s\n",
            string_rep_complex(complex_a),
            string_rep_complex(complex_b), 
            complex_a_equals_b?"TRUE":"FALSE"
    );
    printf("%s == %s is %s\n",
            string_rep_complex(complex_a),
            string_rep_complex(complex_c), 
            complex_a_equals_c?"TRUE":"FALSE"
    );
    complex complex_a_plus_b = add_complex(complex_a, complex_b);
    printf("%s + %s = %s\n",
        string_rep_complex(complex_a),
        string_rep_complex(complex_b),
        string_rep_complex(complex_a_plus_b)
    );
    complex complex_b_minus_c = subtract_complex(complex_b, complex_c);
    printf("%s - %s = %s\n",
        string_rep_complex(complex_b),
        string_rep_complex(complex_c),
        string_rep_complex(complex_b_minus_c)
    );
    complex complex_a_times_b = multiply_complex(complex_a, complex_b);
    printf("%s * %s = %s\n",
        string_rep_complex(complex_a),
        string_rep_complex(complex_b),
        string_rep_complex(complex_a_times_b)
    );
    printf("Change imaginary part of %s, from %g to %g\n", string_rep_complex(complex_a), complex_a.imaginary, 42.0f);
    set_imaginary(complex_a, 42.0f);
    printf("The effect can be seen: %s\n", string_rep_complex(complex_a));
    return 0;
}

static complex create_complex(float real, float imaginary) {
    complex new_complex;
    new_complex.real = real;
    new_complex.imaginary = imaginary;
    return new_complex;
}

#define COMPLEX_STRING_FORMAT "%g + %gi"

static char * string_rep_complex(complex c) {
    size_t size = (size_t) snprintf(NULL, 0, COMPLEX_STRING_FORMAT, c.real, c.imaginary);
    char * rep = (char *) malloc(size + 1); //we need space for the ending 0
    snprintf(rep, size+1, COMPLEX_STRING_FORMAT, c.real, c.imaginary);
    return rep;
}

static boolean equal_complex(complex complex_a, complex complex_b) {
    //a1 + b1i  = a2 + b2i iff a1 = a2 & b1 = b2
    return complex_a.real == complex_b.real && complex_a.imaginary == complex_b.imaginary;
}

static struct Complex add_complex(complex complex_a, complex complex_b) {
    //a + imaginary = (x + u) + (y + v)i
    return create_complex((complex_a.real + complex_b.real), (complex_a.imaginary + complex_b.imaginary));
}

static struct Complex subtract_complex(complex complex_a, complex complex_b) {
    //a - imaginary = (x - u) + (y - v)i
    return create_complex((complex_a.real - complex_b.real), (complex_a.imaginary - complex_b.imaginary));
}

static struct Complex multiply_complex(complex complex_a, complex complex_b) {
    // a * imaginary = (xu - yv) + (xv + yu)i
    float mult_a_part = (complex_a.real * complex_b.real) - (complex_a.imaginary * complex_b.imaginary);
    float mult_b_part = (complex_a.real * complex_b.imaginary) + (complex_a.imaginary * complex_b.real);
    return create_complex(mult_a_part, mult_b_part); 
}

void set_real(complex c, float real) {
	c.real = real;
}

void set_imaginary(complex c, float imaginary) {
	c.imaginary = imaginary;
}
