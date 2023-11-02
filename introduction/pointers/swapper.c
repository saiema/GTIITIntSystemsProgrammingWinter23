/*
* A simple program that takes two integers as arguments, and swap them
* To compile use: gcc -o swapper swapper.c
* To run use: ./swapper <int> <int>
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int * const a, int * const b);

int main(int argc, char ** argv) {
    if (argc != 3) {
        printf("Wrong amount of arguments (%d)", argc - 1);
        printf("Usage: ./swapper <int> <int>\n");
        return 1;
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("I'll take %d, and %d, and swap them!\n", a, b);
    int * pointer_to_a = &a;
    int * pointer_to_b = &b;
    swap(pointer_to_a, pointer_to_b);
    printf("Tadaaa! %d, %d!!!!!\n", a, b);
    return 0;
}

void swap(int * const a, int * const b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}
