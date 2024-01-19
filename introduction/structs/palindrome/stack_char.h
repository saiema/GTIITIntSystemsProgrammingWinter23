/*
* A Char Stack Abstract Data Type
*/
#ifndef STACK_CHAR_H
#define STACK_CHAR_H

#include <boolean.h>

struct Stack_Char;
typedef struct Stack_Char * stack_char;

/*
    Creates a new empty stack
*/
extern stack_char stack_char_new(void);

/*
    Returns `TRUE` iff the stack is empty
*/
extern boolean stack_char_is_empty(const stack_char const stack);

/*
    Pushes an element (a char) into the stack
*/
extern boolean stack_char_push(stack_char const stack, const int value);

/*
    Removes, and returns, the element at the top of a Non-empty stack
*/
extern int stack_char_pop(stack_char const stack);

/*
    Frees all memory allocated for a stack
*/
extern void stack_char_drop(stack_char stack);

#endif