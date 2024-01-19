#include <list_int.h>
#include <boolean.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

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

list_int list_int_empty(void) {
    list_int new_list = (list_int) malloc(sizeof(struct List_Int));
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

unsigned int list_int_size(const list_int const list) {
    assert (list != NULL);
    return list->size;
}

boolean list_int_is_empty(const list_int const list) {
    assert (list != NULL);
    return list->size == 0;
}

boolean list_int_add(list_int const list, const int e) {
    assert (list != NULL);
    if (list->size == 0) {
        list->head = create_new_node(e);
    } else {
        node current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = create_new_node(e);
    }
    list->size++;
    return TRUE;
}

boolean list_int_add_at(list_int const list, const int e, const int at) {
    assert (list != NULL);
    assert (at >= 0);
    if (at >= list_int_size(list)) {
        return list_int_add(list, e);
    }
    node current = list->head;
    for (int i = 0; i < (at - 1); i++) {
        current = current->next;
    } //we want to position current at the node in position at - 1
    node new_node = create_new_node(e);
    new_node->next = current->next;
    current->next = new_node;
    list->size++;
    return TRUE;
}

int list_int_at(const list_int const list, const int at) {
    node current = list->head;
    for (int i = 0; i < at; i++) {
        current = current->next;
    }
    return current->value;
}

int list_int_del_front(list_int const list) {
    assert (list != NULL);
    assert (list->size > 0);
    int value = list->head->value;
    node to_remove = list->head;
    list->head = list->head->next;
    free(to_remove);
    list->size--;
    return value;
}

int list_int_del_back(list_int const list) {
    assert (list != NULL);
    assert (list->size > 0);
    return list_int_del_at(list, list->size - 1);
}

int list_int_del_at(list_int const list, const int at) {
    assert (list != NULL);
    assert (list->size > 0);
    assert (at < list->size);
    assert (at >= 0);
    node current = list->head;
    for (int i = 0; i < at - 1; i++) {
        current = current->next;
    } //we want to position current at the node in position at - 1
    int value = current->next->value;
    node to_remove = current->next;
    current->next = to_remove->next;
    free(to_remove);
    list->size--;
    return value;
}

boolean list_int_equals(const list_int const list_1, const list_int const list_2) {
    assert (list_1 != NULL);
    assert (list_2 != NULL);
    int list_1_size = list_int_size(list_1);
    if (list_1_size != list_int_size(list_2)) {
        return FALSE;
    }
    for (int i = 0; i < list_1_size; i++) {
        int value_1 = list_int_at(list_1, i);
        int value_2 = list_int_at(list_2, i);
        if (value_1 != value_2) {
            return FALSE;
        }
    }
    return TRUE;
}

char * list_int_representation(const list_int const list) {
    int size = 0;
    int list_size = list_int_size(list);
    for (int i = 0; i < list_size; i++) {
        int current = list_int_at(list, i);
        size += snprintf(NULL, 0, "%d", current);
        if (i + 1 < list_size) {
            size += 2;
        }
    }
    size += 2;
    char * rep = (char *) malloc(size + 1);
    rep[size] = 0;
    rep[0] = '[';
    char * cursor = (rep + 1);
    for (int i = 0; i < list_size; i++) {
        int current = list_int_at(list, i);
        int bytes_written = snprintf(NULL, 0, "%d", current);
        snprintf(cursor, bytes_written + 1, "%d", current);
        cursor = cursor + bytes_written;
        if (i + 1 < list_size) {
            snprintf(cursor, 3, ", ");
            cursor += 2;
        }
    }
    rep[size - 1] = ']';
    return rep;
}

void list_int_drop(list_int list) {
    assert (list != NULL);
    node current = list->head;
    node to_remove;
    while(current != NULL) {
        to_remove = current;
        current = current->next;
        free(to_remove);
    }
    free(list);
}