#include <stack_int.h>
#include <boolean.h>
#include <stdlib.h>
#include <assert.h>

struct Node_Int {
    int value;
    struct Node_Int * next;
};

typedef struct Node_Int * node_int;

static node_int node_int_new(const int value) {
    node_int new = (node_int) malloc(sizeof(struct Node_Int));
    new->value = value;
    new->next = NULL;
    return new;
}

struct Stack_Int {
    node_int head;
    int size;
};

stack_int stack_int_new(void) {
    stack_int new = (stack_int) malloc(sizeof(struct Stack_Int));
    new->head = NULL;
    new->size = 0;
    return new;
}

boolean stack_int_is_empty(const stack_int const stack) {
    assert (stack != NULL);
    return stack->size == 0;
}

boolean stack_int_push(stack_int const stack, const int value) {
    assert (stack != NULL);
    node_int new_node = node_int_new(value);
    new_node->next = stack->head;
    stack->head = new_node;
    stack->size++;
    return TRUE;
}

int stack_int_pop(stack_int const stack) {
    assert (stack != NULL);
    assert (!stack_int_is_empty(stack));
    int top = stack->head->value;
    stack->head = stack->head->next;
    stack->size--;
    return top;
}

void stack_int_drop(stack_int stack) {
    if (stack == NULL) {
        return;
    }
    node_int current = stack->head;
    while (current != NULL) {
        node_int next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}