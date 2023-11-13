#include <list_int.h>
#include <boolean.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node * next;
};

typedef struct Node * node;

static node create_new_node(int value) {
    node new_node = (node) malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

struct List_Int {
    node head;
    int size;
};

extern list_int list_int_empty(void) {
    //TODO: implement
}

unsigned int list_int_size(const list_int const list) {
    //TODO: implement
}

boolean list_int_is_empty(const list_int const list) {
    //TODO: implement
}

boolean list_int_add(list_int const list, const int e) {
    //TODO: implement
}

boolean list_int_add_at(list_int const list, const int e, const int at) {
    //TODO: implement
}

int list_int_at(const list_int const list, const int at) {
    //TODO: implement
}

int list_int_del_front(list_int const list) {
    //TODO: implement
}

int list_int_del_back(list_int const list) {
    //TODO: implement
}

int list_int_del_at(list_int const list, const int at) {
    //TODO: implement
}

boolean list_int_equals(const list_int const list_1, const list_int const list_2) {
    //TODO: implement
}

char * list_int_representation(const list_int const list) {
    //TODO: implement
}

void list_int_drop(list_int list) {
    //TODO: implement
}