#include <stdio.h>

static char * bar(int index, char * string);

void main(void) {
    printf("Fubar from 3: %s\n", bar(3, "Fubar"));
}

static char * bar(int index, char * string) {
    return string + index;
}
