#include <stdlib.h>
#include <assert.h>

typedef unsigned char bool;

int length(const char * const string) {
    if (string == NULL) {
        return 0;
    }
    int i = 0;
    while (string[i] != 0) {
        i++;
    }
    return i;
}

bool is_lower_case_letter(const char letter) {
    return letter >= 'a' && letter <= 'z';
}

char to_upper_letter(const char symbol) {
    if (is_lower_case_letter(symbol)) {
        return symbol - 32;
    }
    return symbol;
}

char * to_upper(const char * const string) {
    int string_length = length(string);
    char * upper = (char *) malloc(string_length + 1);
    upper[string_length] = 0;
    for (int i = 0; i < string_length; i++) {
        upper[i] = to_upper_letter(string[i]);
    }
    return upper;
}