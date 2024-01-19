#include <stdlib.h>
#include <stdio.h>
#include <list.h>
#include <boolean.h>
#include <assert.h>

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

boolean list_add(list const lst, void * e) {
    assert (lst != NULL);
    if (lst->size == SIZE) {
        return FALSE;
    }
    lst->last++;
    lst->size++;
    lst->array[lst->last] = e;
    return TRUE;
}

boolean list_add_at(list const lst, void * e, const int at) {
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

static boolean shallow_equals(void * elem_1, void * elem_2) {
    return elem_1 == elem_2;
}

boolean list_equals(const list const list_1, const list const list_2) {
    return list_deep_equals(list_1, list_2, shallow_equals);
}

boolean list_deep_equals(const list const list_1, const list const list_2, boolean (*equals(void *, void *))) {
    assert (list_1 != NULL);
    assert (list_2 != NULL);
    if (list_size(list_1) != list_size(list_2)) {
        return FALSE;
    }
    for (int i = 0; i < list_size(list_1); i++) {
        void * list_1_elem = list_at(list_1, i);
        void * list_2_elem = list_at(list_2, i);
        if (!equals(list_1_elem, list_2_elem)) {
            return FALSE;
        }
    }
    return TRUE;
}

static boolean is_even(void * elem) {
    int * int_p = (int *) elem;
    int value = *int_p;
    return value % 2 == 0;
}

list filter(const list const lst, boolean (*accept)(void *)) {
    assert (lst != NULL);
    list filtered_list = list_new();
    for (int i = 0; i < list_size(lst); i++) {
        void * elem = list_at(lst, i);
        if (accept(elem)) {
            list_add(filtered_list, elem);
        }
    }
    return filtered_list;
}

list filter2(const list const lst, boolean (*accept)(list, void *)) {
    //TODO: implement
}

int count(const list const lst, boolean (*accept)(void *)) {
    //TODO: implement
}

int count2(const list const lst, boolean (*accept)(list, void *)) {
    //TODO: implement
}

boolean all(const list const lst, boolean (*accept)(void *)) {
    assert (lst != NULL);
    for (int i = 0; i < list_size(lst); i++) {
        if (!accept(list_at(lst, i))) {
            return FALSE;
        }
    }
    return TRUE;
}

boolean all2(const list const lst, boolean (*accept)(list, void *)) {
    //TODO: implement
}

boolean not(const list const lst, boolean (*accept)(void *)) {
    assert (lst != NULL);
    for (int i = 0; i < list_size(lst); i++) {
        if (accept(list_at(lst, i))) {
            return FALSE;
        }
    }
    return TRUE;
}

boolean not2(const list const lst, boolean (*accept)(list, void *)) {
    //TODO: implement
}

boolean some(const list const lst, boolean (*accept)(void *)) {
    assert (lst != NULL);
    for (int i = 0; i < list_size(lst); i++) {
        if (accept(list_at(lst, i))) {
            return TRUE;
        }
    }
    return FALSE;
}

boolean some2(const list const lst, boolean (*accept)(list, void *)) {
    //TODO: implement
}

char * list_representation(const list const list) {
    //TODO: implement
}

void list_drop(list list) {
    //TODO: implement
}