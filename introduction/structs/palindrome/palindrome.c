/*
* Checks if a String or a sequence of numbers is a palindrome
* Usage:
* ./palindrome -(s|n) <string|numbers>
*/

#include <stack_int.h>
#include <stack_char.h>
#include <boolean.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum Mode {STRING, NUMBERS, UNKNOWN} mode;

static mode get_operation_mode(char * flag);
static void analyze_string(char * str);
static void analyze_numbers(char ** values);

int main(int argc, char ** argv) {
    if (argc < 2) {
        printf("Wrong amount of arguments, need at least one\n");
        return -1;
    }
    mode operation_mode = get_operation_mode(argv[1]);
    if (operation_mode == UNKNOWN) {
        printf("Unrecognized flag %s\n", argv[1]);
        return -2;
    }
    if (operation_mode == STRING && argc < 3) {
        printf("No string to analyze\n");
        return 0;
    }
    switch (operation_mode) {
        case STRING: {
            analyze_string(argv[2]);
            break;
        }
        
        case NUMBERS: {
            analyze_numbers(argv + 2);
            break;
        }
    }
}

static void analyze_string(char * str) {
    char * current = str;
    stack_char stack = stack_char_new();
    while (*current != '\0') {
        stack_char_push(stack, *current);
        current++;
    }
    current = str;
    boolean is_palindrome = TRUE;
    while (*current != '\0' && is_palindrome) {
        char top = stack_char_pop(stack);
        if (top != *current) {
            is_palindrome = not(is_palindrome);
        }
        current++;
    }
    printf("%s is a%s palindrome\n", str, is_palindrome?"":" not a");
}

static void analyze_numbers(char ** values) {
    char ** current = values;
    stack_int stack = stack_int_new();
    while (*current != NULL) {
        int current_int = atoi(*current);
        stack_int_push(stack, current_int);
        current++;
    }
    current = values;
    boolean is_palindrome = TRUE;
    while (*current != NULL && is_palindrome) {
        int current_int = atoi(*current);
        if (stack_int_pop(stack) != current_int) {
            is_palindrome = not(is_palindrome);
        }
        current++;
    }
    current = values;
    printf("[");
    while (*current != NULL) {
        printf("%s", *current);
        if (*(current + 1) != NULL) {
            printf(", ");
        }
        current++;
    }
    printf("] is%s palindrome\n", is_palindrome?"":" not");
}


static mode get_operation_mode(char * flag) {
    if (flag[0] != '-') {
        return UNKNOWN;
    } else if (flag[1] == 's') {
        return STRING;
    } else if (flag[1] == 'n') {
        return NUMBERS;
    }
    return UNKNOWN;
}

