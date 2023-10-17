#include <stdio.h>
#include <the_answer.h>

extern int the_answer;

void main(void) {
    the_answer = 42;
    printf("The answer to the ultimate question is %d\n", the_answer);
}