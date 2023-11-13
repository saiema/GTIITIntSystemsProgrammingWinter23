/*
* A Char Stack Abstract Data Type
*/
#ifndef STACK_CHAR_H
#define STACK_CHAR_H

#include <boolean.h>

struct Stack_Char;
typedef struct Stack_Char * stack_char;

extern stack_char stack_char_new(void);
extern boolean stack_char_is_empty(const stack_char const stack);
extern boolean stack_char_push(stack_char const stack, const int value);
extern int stack_char_pop(stack_char const stack);
extern void stack_char_drop(stack_char stack);

#endif