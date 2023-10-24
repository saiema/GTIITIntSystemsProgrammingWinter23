#include <stdio.h>

extern char * greetings(void);

int main(void) {
    printf("%s\n", greetings());
    return 0;
}