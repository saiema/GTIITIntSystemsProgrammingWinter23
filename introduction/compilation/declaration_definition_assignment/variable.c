#include <stdio.h>

extern int the_answer;
// int the_answer;

void main(void) {
    the_answer = 42;
    printf("The answer to the ultimate question is %d\n", the_answer);
}
