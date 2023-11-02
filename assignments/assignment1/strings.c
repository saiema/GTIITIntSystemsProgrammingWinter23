#include "standard.h"
#include <stdlib.h>

natural length(const char * const string) {
    //TODO: complete
}

boolean equals(const char * const string1, const char * const string2) {
    //TODO: complete
}

int index_of(const char * const string, const char e) {
    //TODO: complete
}

int last_index_of(const char * const string, const char e) {
    //TODO: complete
}

#define LOWER_CASE_MIN 97
#define LOWER_CASE_MAX 122

#define UPPER_CASE_MIN 65
#define UPPER_CASE_MAX 90

#define CASE_DIFF 32

char * to_lower_case(const char * const string) {
    //TODO: complete
}

char * to_upper_case(const char * const string) {
    //TODO: complete
}

//TODO create a private function (use the `static` keyword) which will
//     switch a range of characters by a certain constant value, the profile
//     will be:
//     `static char shift_in_range(const char c, natural range_start, natural range_end, const int shift)`

char * substring(const char * const string, natural from, natural to) {
    natural strLength = length(string);
    if (from < 0 || from >= strLength || to > strLength || from > to) {
        return 0;
    }
    natural sliceLength = to - from;
    char * slice = (char *) malloc(sliceLength + 1);
    if (slice == 0) {
        return 0;
    }
    slice[sliceLength] = 0;
    for (int i = 0; i < sliceLength; i++) {
        char origChar = string[from + i];
        slice[i] = origChar;
    }
    return slice;
}