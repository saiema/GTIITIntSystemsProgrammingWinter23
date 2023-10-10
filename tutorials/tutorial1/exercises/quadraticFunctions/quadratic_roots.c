#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadratic_functions.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("***usage: ./quadratic-roots <a> <b> <c>\n");
        return -1;
    }
    else {
        Quadratic_Function f = create_quadratric_function(
            atof(argv[1]),
            atof(argv[2]),
            atof(argv[3])
        );
        int root_count = number_of_roots(f);
        if (root_count > 1) {
            Roots roots = compute_roots(f);
            printf("The roots of %s are %.2f and %.2f\n", to_string(f), get_first_root(roots), get_second_root(roots));
        }
        else {
            if (root_count == 1) {
                Roots roots = compute_roots(f);
                printf("The only root of %s is %.2f\n", to_string(f), get_first_root(roots));
            }
            else {
                printf("Function %s has no real roots\n", to_string(f));
            }
        }
        float range_start = -2.0f;
        float range_end = 2.0f;
        float step = 0.5f;
        Tuple * points = plot(f, range_start, range_end, step);
        float diff = range_end - range_start;
        int steps = diff / step;
        for (int s = 0; s < steps; s++) {
            printf("f(%f): %f\n", fst(points[s]), snd(points[s]));
        }
        return 0;
    }
}