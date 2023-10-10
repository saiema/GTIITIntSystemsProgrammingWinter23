#include "quadratic_functions.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct tuple {
    float fst; // first value of the tuple
    float snd; // second value of the tuple
};

struct quadratic_function {
    float a; // quadratic coefficient
    float b; // linear coefficient
    float c; // constant coefficient
};

struct roots {
    int nr_roots;
    union {
        float the_root;
        struct two_roots {
            float root_one;
            float root_two;
        } Two_roots;
    } roots;
};

static Quadratic_Function create_quadratic_function(float a, float b, float c) {
    Quadratic_Function qfunction = (Quadratic_Function) malloc(sizeof(struct quadratic_function));
    qfunction->a = a;
    qfunction->b = b;
    qfunction->c = c;
    return qfunction;
}

static Roots create_roots_none() {
    Roots roots = (Roots) malloc(sizeof(struct roots));
    roots->nr_roots = 0;
    return roots;
}

static Roots create_roots_one(float root) {
    Roots roots = (Roots) malloc(sizeof(struct roots));
    roots->nr_roots = 1;
    roots->roots.the_root = root;
    return roots;
}

static Roots create_roots_two(float root_1, float root_2) {
    Roots roots = (Roots) malloc(sizeof(struct roots));
    roots->nr_roots = 2;
    roots->roots.Two_roots.root_one = root_1;
    roots->roots.Two_roots.root_two = root_2;
    return roots;
}

/*
 * quadratic_functions.c: C file implementing types and functions for quadratic functions.
 * This C file implement the functions and types described in quadratic_function.h,
 * to deal with quadratic functions.
 * These include functions to compute the value of a function at a given point, computing a function's roots,
 * and providing string representations of functions, among others.
 * 
 * Author: N. Aguirre, S. Gutierrez
 * Date: March 16th 2023, October 10th 2023
 */

Quadratic_Function create_quadratric_function(float a, float b, float c) {
    assert (a != 0);
    return create_quadratic_function(a, b, c);
}

Tuple create_tuple(float fst, float snd) {
    Tuple tuple = (Tuple) malloc(sizeof(struct tuple));
    tuple->fst = fst;
    tuple->snd = snd;
    return tuple;
}

float fst(Tuple tuple) {
    return tuple->fst;
}

float snd(Tuple tuple) {
    return tuple->snd;
}

int nr_roots(Roots roots) {
    return roots->nr_roots;
}

float get_first_root(Roots roots) {
    assert (nr_roots(roots) >= 1);
    if (roots->nr_roots == 1) {
        return roots->roots.the_root;
    }
    return roots->roots.Two_roots.root_one;
}

float get_second_root(Roots roots) {
    assert (nr_roots(roots) == 2);
    return roots->roots.Two_roots.root_two;
}

float discriminant(Quadratic_Function f) {
    return ((f->b*f->b) - (4*f->a*f->c));
}

int number_of_roots(Quadratic_Function f) {
    if (discriminant(f) > 0.0)
        return 2;
    else {
        if (discriminant(f) == 0.0) {
            return 1;
        }
        else return 0;
    }
}

Roots compute_roots(Quadratic_Function f) {
    Roots roots;
    int nr_roots = number_of_roots(f);
    if (nr_roots == 1) {
        roots = create_roots_one((-f->b + sqrt(discriminant(f))) / (2 * f->a)); 
    } else if (nr_roots == 2) {
        roots = create_roots_two(
            (-f->b + sqrt(discriminant(f))) / (2 * f->a),
            (-f->b - sqrt(discriminant(f))) / (2 * f->a)
        );
    } else {
        roots = create_roots_none();
    }
    return roots;
}

float apply(Quadratic_Function f, float x) {
    return (x * x * f->a + x * f->b + f->c);
}

Tuple * plot(Quadratic_Function f, float range_start, float range_end, float step) {
    assert (range_start <= range_end);
    assert (step > 0.0f);
    float diff = range_end - range_start;
    int steps = diff / step;
    Tuple * points = (Tuple *) malloc(sizeof(Tuple)*steps);
    for (int s = 0; s < steps; s++) {
        float x = range_start + (step * s);
        points[s] = create_tuple(x, apply(f, x));
    }
    return points;
}

const char* to_string(Quadratic_Function f) {
    int len = snprintf(NULL, 0, "f(x) = %.2fx^2 + %.2fx + %.2f", f->a, f->b, f->c);
    char *result = malloc(len + 1);
    snprintf(result, len + 1, "f(x) = %.2fx^2 + %.2fx + %.2f", f->a, f->b, f->c);
    return result;
}


