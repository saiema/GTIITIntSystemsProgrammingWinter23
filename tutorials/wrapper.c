#include <stdio.h>
#include <stdlib.h>

typedef struct list* List;

struct list {
    struct Node* head;
    int size;
};

struct Node {
    int elem;
    struct Node* next;
};


typedef struct wrapper {
    void * elem;
} Wrapper;


Wrapper * wrap_elem(void * x) {
    printf("The address of x is: %p\n", x);
    Wrapper * result = malloc(sizeof(Wrapper));
    printf("The address of result is: %p\n", result);
    (* result).elem = x;
    printf("The address held in elem is: %p\n", (* result).elem);
    return result;
}


int main() {
    int * value = malloc(sizeof(int));
    printf("Address of value is: %p\n", value);
    *value = 10;
    Wrapper * w = wrap_elem(value);
    printf("Address of w is: %p\n", w);
    value = NULL;
    printf("%d\n", *((int *) (*w).elem));
    return 0;
}