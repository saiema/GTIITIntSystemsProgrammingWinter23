/*
* An Int Stack Abstract Data Type
*/
#ifndef STACK_INT_H
#define STACK_INT_H

#include <boolean.h>

struct Stack_Int;
typedef struct Stack_Int * stack_int;

/*
    Creates a new empty stack
*/
extern stack_int stack_int_new(void);

/*
    Returns `TRUE` iff the stack is empty
*/
extern boolean stack_int_is_empty(const stack_int const stack);

/*
    Pushes an element (a char) into the stack
*/
extern boolean stack_int_push(stack_int const stack, const int value);

/*
    Removes, and returns, the element at the top of a Non-empty stack
*/
extern int stack_int_pop(stack_int const stack);

/*
    Frees all memory allocated for a stack
*/
extern void stack_int_drop(stack_int stack);

#endif