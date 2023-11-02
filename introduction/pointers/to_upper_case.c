/*
* A simple example on how to implement a program that will output every command-line argument in upper case
* To compile use: gcc -o to_upper_case to_upper_case.c
* To run use ./to_upper_case <arguments separated by space> (*)
*
* (*) If an argument contains spaces, you can surround that argument with double quotes.
*/


#include <stdio.h>
#include <stdlib.h>

static char * to_upper_case(const char * const string);
static int length(const char * const string);

int main(int argc, char ** argv) {
    for (int i = 1; i < argc; i++) {
        printf("%s", to_upper_case(argv[i]));
        if (i + 1 < argc) {
            printf(" ");
        }
    }
    if (argc > 1) {
        printf("\n");
    }
    return 0;
}

#define LOWER_CASE_MIN 97
#define LOWER_CASE_MAX 122
#define DIFF 32

static char * to_upper_case(const char * const string) {
    if (string == NULL) {
        return NULL;
    }
    int size = length(string);
    char * upper_version = (char *) malloc(size + 1);
    upper_version[size] = 0;
    for (int i = 0; i < size; i++) {
        char current = string[i];
        if (current >= LOWER_CASE_MIN && current <= LOWER_CASE_MAX) {
            current = current - DIFF;
        }
        upper_version[i] = current;
    }
    return upper_version;
}

static int length(const char * const string) {
    int i = 0;
    if (string == NULL) {
        return 0;
    }
    while (string[i] != '\0') {
        i++;
    }
    return i;
}