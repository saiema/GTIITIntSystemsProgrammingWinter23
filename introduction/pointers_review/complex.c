#include <stdlib.h>
#include <stdio.h>

struct Complex {
    float real;
    float imaginary;
};

typedef struct Complex complex;
typedef unsigned char boolean;

static struct Complex create_complex(const float real, const float imaginary);
static char * string_rep_complex(const complex const complex_val);
static boolean equal_complex(const struct Complex const complex_a, const struct Complex const complex_b);
static struct Complex add_complex(const struct Complex const complex_a, const struct Complex const complex_b);
static struct Complex subtract_complex(const struct Complex const complex_a, const struct Complex const complex_b);
static struct Complex multiply_complex(const struct Complex const complex_a, const struct Complex const complex_b);

int main(void) {
    struct Complex complex_a = create_complex(1.33f, 4.2f);
    struct Complex complex_b = create_complex(8.75f, 3.14f);
    struct Complex complex_c = create_complex(1.33f, 4.2f);
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
    struct Complex complex_a_plus_b = add_complex(complex_a, complex_b);
    printf("%s + %s = %s\n",
        string_rep_complex(complex_a),
        string_rep_complex(complex_b),
        string_rep_complex(complex_a_plus_b)
    );
    struct Complex complex_b_minus_c = subtract_complex(complex_b, complex_c);
    printf("%s - %s = %s\n",
        string_rep_complex(complex_b),
        string_rep_complex(complex_c),
        string_rep_complex(complex_b_minus_c)
    );
    struct Complex complex_a_times_b = multiply_complex(complex_a, complex_b);
    printf("%s * %s = %s\n",
        string_rep_complex(complex_a),
        string_rep_complex(complex_b),
        string_rep_complex(complex_a_times_b)
    );
}

static struct Complex create_complex(const float real, const float imaginary) {
    struct Complex complex;
    complex.real = real;
    complex.imaginary = imaginary;
    return complex;
}

#define COMPLEX_STRING_FORMAT "%g + %gi"

static char * string_rep_complex(const struct Complex const complex) {
    size_t size = (size_t) snprintf(NULL, 0, COMPLEX_STRING_FORMAT, complex.real, complex.imaginary);
    char * rep = (char *) malloc(size + 1); //we need space for the ending 0
    snprintf(rep, size+1, COMPLEX_STRING_FORMAT, complex.real, complex.imaginary);
    return rep;
}

static boolean equal_complex(const struct Complex const complex_a, const struct Complex const complex_b) {
    //a1 + b1i  = a2 + b2i iff a1 = a2 & b1 = b2
    return complex_a.real == complex_b.real && complex_a.imaginary == complex_b.imaginary;
}

static struct Complex add_complex(const struct Complex const complex_a, const struct Complex const complex_b) {
    //a + imaginary = (x + u) + (y + v)i
    return create_complex((complex_a.real + complex_b.real), (complex_a.imaginary + complex_b.imaginary));
}

static struct Complex subtract_complex(const struct Complex const complex_a, const struct Complex const complex_b) {
    //a - imaginary = (x - u) + (y - v)i
    return create_complex((complex_a.real - complex_b.real), (complex_a.imaginary - complex_b.imaginary));
}

static struct Complex multiply_complex(const struct Complex const complex_a, const struct Complex const complex_b) {
    // a * imaginary = (xu - yv) + (xv + yu)i
    float mult_a_part = (complex_a.real * complex_b.real) - (complex_a.imaginary * complex_b.imaginary);
    float mult_b_part = (complex_a.real * complex_b.imaginary) + (complex_a.imaginary * complex_b.real);
    return create_complex(mult_a_part, mult_b_part); 
}