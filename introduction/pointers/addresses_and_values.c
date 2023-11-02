/*
* A simple program to show introduce the notion of pointers and data sizes.
* To compile use: gcc -o addresses_and_values addresses_and_values.c
* To run use: ./addresses_and_values
*/


#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char *str = "Hello World";
    printf("sizeof(str): %ld\n", sizeof(str));

    char hello[6] = {'h', 'e', 'l', 'l', 'o', 0};
    printf("sizeof(hello): %ld\n", sizeof(hello));

    int my_array[10] = {1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i < 10; i++) {
        printf("my_array[%d]: %d\n", i, my_array[i]);
    }

    printf("sizeof(my_array): %ld\n", sizeof(my_array));
    printf("sizeof(my_array[4]): %ld\n", sizeof(my_array[4]));

    int * p = my_array;

    printf("sizeof(p): %ld\n", sizeof(p));
    printf("my_array starts at address: %p\n", my_array);

    for (int i = 0; i < 10; i++) {
        printf("my_array address: %p\t|",my_array);
        printf("\taddress of my_array[%d]: %p\t|", i, my_array + i);
        printf("\tvalue at current address: %d\n", *(my_array + i));
    }

    return 0;

}
