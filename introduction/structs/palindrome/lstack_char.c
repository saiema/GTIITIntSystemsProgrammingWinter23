#include <stack_char.h>
#include <boolean.h>
#include <stdlib.h>
#include <assert.h>

struct Node_Char {
    char value;
    struct Node_Char * next;
};

typedef struct Node_Char * node_char;

static node_char node_char_new(const char value) {
    node_char new = (node_char) malloc(sizeof(struct Node_Char));
    new->value = value;
    new->next = NULL;
    return new;
}

struct Stack_Char {
    node_char head;
    char size;
};

stack_char stack_char_new(void) {
    stack_char new = (stack_char) malloc(sizeof(struct Stack_Char));
    new->head = NULL;
    new->size = 0;
    return new;
}

boolean stack_char_is_empty(const stack_char const stack) {
    assert (stack != NULL);
    return stack->size == 0;
}

boolean stack_char_push(stack_char const stack, const int value) {
    assert (stack != NULL);
    node_char new_node = node_char_new(value);
    new_node->next = stack->head;
    stack->head = new_node;
    stack->size++;
    return TRUE;
}

int stack_char_pop(stack_char const stack) {
    assert (stack != NULL);
    assert (!stack_char_is_empty(stack));
    char top = stack->head->value;
    stack->head = stack->head->next;
    stack->size--;
    return top;
}

void stack_char_drop(stack_char stack) {
    if (stack == NULL) {
        return;
    }
    node_char current = stack->head;
    while (current != NULL) {
        node_char next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}