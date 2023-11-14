#include <strings.h>
#include <boolean.h>
#include <stdlib.h>

unsigned int length(const string const str) {
    if (str == NULL) {
        return 0;
    }
    int count = 0;
    while(str[count] != 0) {
        count++;
    }
    return count;
}

boolean equals(const string const str1, const string const str2) {
    if (str1 == NULL) {
        return str2 == NULL;
    } else if (str2 == NULL) {
        return FALSE;
    }
    int i = 0;
    while (str1[i] != 0) {
        if (str2[i] == 0) {
            return FALSE;
        } else if (str1[i] != str2[i]) {
            return FALSE;
        }
        i++;
    }
    return str2[i] == 0;
}

int index_of(const string const str, const char e) {
    if (str == NULL) {
        return -1;
    }
    int idx = 0;
    boolean found = FALSE;
    while (str[idx] != 0) {
        if (str[idx] == e) {
            return idx;
        }
        idx++;
    }
    return found?idx:-1;
}

int last_index_of(const string const str, const char e) {
    if (str == NULL) {
        return -1;
    }
    int idx = 0;
    int resIdx = -1;
    while(str[idx] != 0) {
        if (str[idx] == e) {
           resIdx = idx; 
        }
        idx++;
    }
    return resIdx;
}

#define LOWER_CASE_MIN 97
#define LOWER_CASE_MAX 122

#define UPPER_CASE_MIN 65
#define UPPER_CASE_MAX 90

#define CASE_DIFF 32

static char shift_in_range(const char c, unsigned int range_start, unsigned int range_end, const int shift) {
    if ((range_start <= c) && (c <= range_end)) {
        return c + shift;
    } else {
        return c;
    }
}

string to_lower_case(const string const str) {
    if (str == NULL) {
        return NULL;
    }
    int strLength = length(str);
    string lCaseString = (string) malloc(strLength + 1);
    if (lCaseString == 0) {
        return 0;
    }
    lCaseString[strLength] = 0;
    for (int i = 0; i < strLength; i++) {
        lCaseString[i] = shift_in_range(str[i], UPPER_CASE_MIN, UPPER_CASE_MAX, CASE_DIFF);
    }
    return lCaseString;
}

string to_upper_case(const string const str) {
    if (str == NULL) {
        return NULL;
    }
    unsigned int strLength = length(str);
    string uCaseString = (string) malloc(strLength + 1);
    if (uCaseString == 0) {
        return 0;
    }
    uCaseString[strLength] = 0;
    for (int i = 0; i < strLength; i++) {
        uCaseString[i] = shift_in_range(str[i], LOWER_CASE_MIN, LOWER_CASE_MAX, -CASE_DIFF);
    }
    return uCaseString;
}

string substring(const string const str, unsigned int from, unsigned int to) {
    if (str == NULL) {
        return NULL;
    }
    unsigned int strLength = length(str);
    if (from < 0 || from >= strLength || to > strLength || from > to) {
        return NULL;
    }
    unsigned int sliceLength = to - from;
    string slice = (string) malloc(sliceLength + 1);
    if (slice == 0) {
        return NULL;
    }
    slice[sliceLength] = 0;
    for (int i = 0; i < sliceLength; i++) {
        char origChar = str[from + i];
        slice[i] = origChar;
    }
    return slice;
}

string append(const string const this, const string const that) {
    if ((this == NULL) && (that == NULL)) {
        return NULL;
    } else if (this == NULL) {
        string copy_of_that = (string) malloc(sizeof(char) * (length(that) + 1));
        return copy(copy_of_that, that);
    } else if (that == NULL) {
        string copy_of_this = (string) malloc(sizeof(char) * (length(this) + 1));
        return copy(copy_of_this, this);
    } else {
        int length_this = length(this);
        int length_that = length(that);
        string this_and_that = (string) malloc(sizeof(char) * (length_this + length_that + 1));
        ncopy(this_and_that, this, length_this);
        ncopy((this_and_that+length_this), that, length_that + 1);
        return this_and_that;
    }
}

string ncopy(string const dest, const string const src, const int size) {
    size_t i;
    for (i = 0; i < size && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for ( ; i < size; i++) {
        dest[i] = '\0';
    }
    return dest;
}

string copy(string const dest, const string const src) {
    int size_src = length(src);
    return ncopy(dest, src, size_src + 1);
}