#include <boolean.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct Boolean {
    unsigned char bool;
};

#define TRUE 1
#define FALSE 0

boolean boolean_true(void) {
    boolean true_val = (boolean) malloc(sizeof(struct Boolean));
    true_val->bool = TRUE;
    return true_val;
}

boolean boolean_false(void) {
    boolean false_val = (boolean) malloc(sizeof(struct Boolean));
    false_val->bool = FALSE;
    return false_val;
}

boolean boolean_and(const boolean const a, const boolean const b) {
    assert(a != NULL);
    assert(b != NULL);
    boolean and_val = (boolean) malloc(sizeof(struct Boolean));
    and_val->bool = a->bool && b->bool;
    return and_val;
}

boolean boolean_or(const boolean const a, const boolean const b) {
    assert(a != NULL);
    assert(b != NULL);
    boolean or_val = (boolean) malloc(sizeof(struct Boolean));
    or_val->bool = a->bool || b->bool;
    return or_val;
}

boolean boolean_xor(const boolean const a, const boolean const b) {
    assert(a != NULL);
    assert(b != NULL);
    boolean xor_val = (boolean) malloc(sizeof(struct Boolean));
    xor_val->bool = a->bool ^ b->bool;
    return xor_val;
}

boolean boolean_not(const boolean const b) {
    assert(b != NULL);
    boolean not_val = (boolean) malloc(sizeof(struct Boolean));
    not_val->bool = !(b->bool);
    return not_val;
}

#define BOOLEAN_STRING_TRUE "TRUE"
#define BOOLEAN_STRING_FALSE "FALSE"

char * boolean_representation(const boolean const b) {
    int size = b->bool?4:5;
    char * boolean_rep = (char *) malloc(sizeof(char) * (size + 1));
    snprintf(boolean_rep, (size + 1), (b->bool?BOOLEAN_STRING_TRUE:BOOLEAN_STRING_FALSE));
    return boolean_rep;
}

boolean boolean_from_string(const char * const str) {
    if (str == NULL) {
        return boolean_false();
    }
    unsigned char is_true = 1;
    unsigned int i = 0;
    while (str[i] != '\0' && i < 4 && is_true) {
        if (str[i] != BOOLEAN_STRING_TRUE[i]) {
            is_true = 0;
        }
        i++;
    }
    if (is_true && i == 4 && str[i] == '\0') {
        return boolean_true();
    }
    return boolean_false();
}

boolean boolean_from_int(const int value) {
    return value?boolean_true():boolean_false();
}

void boolean_drop(const boolean const value) {
    assert (value != NULL);
    free(value);
}
