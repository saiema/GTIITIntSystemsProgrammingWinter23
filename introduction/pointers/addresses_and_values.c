#include <stdio.h>

void main(void) {

    char *str = "hola mundo";
    printf("sizeof(str): %ld\n", sizeof(str));

    char hola[5] = {'h', 'o', 'l', 'a', 0};
    printf("sizeof(hola): %ld\n", sizeof(hola));


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
        printf("my_address address: %p\t|\taddress of my_address[%d]: %p\t|\tvalue at current address: %d\n", my_array, i, my_array + i, my_array[i]);
    }

}