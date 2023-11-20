#include <stdlib.h>
#include <stdio.h>
#include <list.h>
#include <boolean.h>

#define SIZE 20

struct List {
    void * array[SIZE];
    unsigned int size;
    int last;
};

static void initialize_array(const int size, void * array[size]) {
    for (int i = 0; i < size; i++) {
        array[i] = NULL;
    }
}

list list_new(void) {
    list lst = (list) malloc(sizeof(struct List));
    lst->size = 0;
    lst->last = -1;
    initialize_array(SIZE, lst->array);
    return lst;
}

unsigned int list_size(const list const lst) {
    assert (lst != NULL);
    return lst->size;
}

boolean list_is_empty(const list const lst) {
    assert (lst != NULL);
    return lst->size == 0;
}

boolean list_add(list const lst, const void * e) {
    assert (lst != NULL);
    if (lst->size == SIZE) {
        return FALSE;
    }
    lst->last++;
    lst->size++;
    lst->array[lst->last] = e;
    return TRUE;
}

boolean list_add_at(list const lst, const void * e, const int at) {
    assert (lst != NULL);
    assert (at >= 0);
    if (at >= lst->size) {
        return list_add(lst, e);
    }
    if (lst->size == SIZE) {
        return FALSE;
    }
    lst->size++;
    for (int i = lst->last; i >= at; i--) {
        lst->array[i + 1] = lst->array[i];
    }
    lst->last++;
    lst->array[at] = e;
    return TRUE;
}

void * list_at(const list const lst, const int at) {
    assert (lst != NULL);
    assert (at >= 0 && at < lst->size);
    return lst->array[at];
}

void * list_del_front(list const lst) {
    //TODO: implement
}

void * list_del_back(list const list) {
    //TODO: implement
}

void * list_del_at(list const list, const int at) {
    //TODO: implement
}

boolean list_equals(const list const list_1, const list const list_2) {
    //TODO: implement
}

char * list_representation(const list const list) {
    //TODO: implement
}

void list_drop(list list) {
    //TODO: implement
}