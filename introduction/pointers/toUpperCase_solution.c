#include <stdio.h>
#include <stdlib.h>

static char * toUpperCase(const char * const string);
static unsigned int length(const char * const string);

int main(int argc, char ** argv) {
    for (int i = 1; i < argc; i++) {
        printf("%s", toUpperCase(argv[i]));
        if (i + 1 < argc) {
            printf(" ");
        }
    }
    if (argc > 1) {
        printf("\n");
    }
    return 0;
}

static unsigned int length(const char * const string) {
    int count = 0;
    while(string[count] != 0) {
        count++;
    }
    return count;
}


#define LOWER_CASE_MIN 97
#define LOWER_CASE_MAX 122

#define CASE_DIFF 32

static char * toUpperCase(const char * const string) {
    unsigned int strLength = length(string);
    char * uCaseString = (char *) malloc(strLength + 1);
    if (uCaseString == 0) {
        return 0;
    }
    uCaseString[strLength] = 0;
    for (int i = 0; i < strLength; i++) {
        char currChar = string[i];
        if ((currChar >= LOWER_CASE_MIN) && (currChar <= LOWER_CASE_MAX)) {
            currChar = currChar - CASE_DIFF;
        }
        uCaseString[i] = currChar;
    }
    return uCaseString;
}