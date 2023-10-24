/*
* A simple example introducing the concept of structs in C
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
* A tuple (an ordered set of values) of two `int` values: `a` and `b`. 
*/
struct TupleInt {
    int a;
    int b;
};

/*
* A function that calculates the minimum and maximum values from an array
* The array must not be empty
* Returns a tuple `TupleInt` containing the minimum value and the maximum value
* in that order.
*/
struct TupleInt min_max(const int size, const int values[size]) {
    assert (size > 0);
    struct TupleInt min_max_tuple = {values[0], values[0]};
    for (int i = 1; i < size; i++) {
        int current = values[i];
        if (current < min_max_tuple.a) {
            min_max_tuple.a = current;
        } else if (current > min_max_tuple.b) {
            min_max_tuple.b = current;
        }
    }
    return min_max_tuple;
}

void print_usage(void);
void print_int_array(const int size, const int array[size]);

void main(int argc, char ** argv) {
    if (argc < 2) {
        printf("Wrong amount of arguments (%d)\n", argc - 1);
        print_usage();
        exit(1);
    }
    int size = atoi(argv[1]);
    if (size < 0) {
        printf("Invalid size (%d), it must be a number greater or equal to zero\n", size);
        print_usage();
        exit(2);
    }
    if (size != (argc - 2)) {
        printf("Invalid arguments, size argument (%d) doesn't match number of elements (%d)\n", size, (argc - 2));
        print_usage();
        exit(3);
    }
    int values[size];
    for (int i = 0; i < size; i++) {
        values[i] = atoi(argv[i + 2]); // We ignore the first two arguments
    }
    print_int_array(size, values);
    struct TupleInt min_max_values = min_max(size, values);
    printf("Minimum value: %d\t|\tMaximum value: %d\n", min_max_values.a, min_max_values.b);
    exit(0);
}

void print_usage(void) {
    printf("Usage: ./maximum <size> <elems>\n");
    printf("Where <size> is an integer greater or equal to zero, specifying how many arguments will be provided next.\n");
    printf("Where <elems> is a list, separated by spaces, of <size> integer numbers.\n");
}

void print_int_array(const int size, const int array[size]) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i + 1 < size) {
            printf(", ");
        }
    }
    printf("]\n");
}