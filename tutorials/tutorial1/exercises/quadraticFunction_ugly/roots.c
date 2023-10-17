#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

float discriminant(float a, float b, float c) {
    return ((b*b) - (4*a*c));
}

int nr_roots(float a, float b, float c) {
    if (discriminant(a, b, c) > 0.0)
        return 2;
    else {
        if (discriminant(a, b, c) == 0.0) {
            return 1;
        }
        else return 0;
    }
}

float calculate_root(float a, float b, float c) {
    return (-b + sqrt(discriminant(a, b, c))) / (2 * a);
}

void calculate_roots(float a, float b, float c, float roots[2]) {
    roots[0] = (-b + sqrt(discriminant(a, b, c))) / (2 * a);
    roots[1] = (-b - sqrt(discriminant(a, b, c))) / (2 * a);
} 

void roots(float a, float b, float c, float roots[2]) {
    assert (a != 0.0f);
    if (nr_roots(a, b, c) == 0) {
        roots[0] = NAN;
        roots[1] = NAN;
    } else if (nr_roots(a, b, c) == 1) {
        float the_root = calculate_root(a, b, c);
        roots[0] = the_root;
        roots[1] = NAN;
    } else { // nr_roots(a, b, c) == 2
        calculate_roots(a, b, c, roots);
    }
}

void main(int argc, char ** argv) {
    if (argc != 4) {
        printf("Wrong amount of arguments (%d)\n", argc - 1);
        printf("Usage: ./roots <a> <b> <c>\n");
        printf("\nWhere coefficients are float numbers definining the coefficients of a quadratic function\n");
        printf("Coefficient a cannot be zero (0)\n");
        exit(1);
    }
    float a = atof(argv[1]);
    float b = atof(argv[2]);
    float c = atof(argv[3]);
    printf("%fX^2 + %fX + %f\n", a, b , c);
    float calculated_roots[2];
    roots(a, b, c, calculated_roots);
    if (isnan(calculated_roots[0])) {
        puts("It has no roots");
    } else if (isnan(calculated_roots[1])) {
        printf("One root: %f\n", calculated_roots[0]);
    } else {
        printf("Two roots: %f and %f\n", calculated_roots[0], calculated_roots[1]);
    }
}