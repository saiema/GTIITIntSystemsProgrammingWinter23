#include <stdio.h>

int the_answer(void); //Declaration

void main(void) {
    printf("The answer to the ultimate question is %d\n", the_answer());
}

int the_answer(void) { // Definition
    return 42;
}