#include <stdlib.h>
#include <stdio.h>

// int main(void) {
//     void * p = malloc(5);
//     char * s = (char *) p;
//     int * i = (int *) malloc(sizeof(int) * 2);
//     s = "Hi!";
//     i[1] = 42;
//     printf("%s\n", s);
//     printf("Address of i: %p\n", i);
//     printf("Address of i + 1: %p\n", (i+1));
//     printf("Value at i[1] *(i + 1): %d\n", *(i + 1));
//     printf("%p\n", p);
//     free(p);
//     printf("%p\n", p);
//     int var;
//     free(i);
//     var = i[1];
//     printf("Value at i[1] *(i + 1): %d\n", var);
//     printf("Value at i[1] *(i + 1): %d\n", *(i + 1));
//     // free(p);
//     // printf("%s\n", s);
// }

int main(void) {
    while(1) {
        char * s = (char *) malloc(4);
    }
}