#include <stdio.h>

char * bar(int index, char * string);

void main(void) {
    printf("Fubar from 3: %s\n", bar(3, "Fubar"));
}

char * bar(int index, char * string) {
    return string + index;
}