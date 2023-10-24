#include <stdio.h>
#include <stdlib.h>

void swap(int * const a, int * const b);

int  main(int argc, char ** argv) {
    if (argc != 3) {
        printf("Wrong amount of arguments (%d)", argc - 1);
        printf("Usage: ./swapper <int> <int>\n");
        exit(1);
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    printf("I'll take %d, and %d, and swap them!\n", a, b);
    swap(&a, &b);
    printf("Tadaaa! %d, %d!!!!!\n", a, b);
}

void swap(int * const a, int * const b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}