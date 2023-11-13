/*
* An Int Stack Abstract Data Type
*/
#ifndef STACK_INT_H
#define STACK_INT_H

#include <boolean.h>

struct Stack_Int;
typedef struct Stack_Int * stack_int;

extern stack_int stack_int_new(void);
extern boolean stack_int_is_empty(const stack_int const stack);
extern boolean stack_int_push(stack_int const stack, const int value);
extern int stack_int_pop(stack_int const stack);
extern void stack_int_drop(stack_int stack);

#endif