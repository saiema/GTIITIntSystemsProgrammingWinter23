#include <stdio.h>
#include <stdlib.h>

int index_of(const int size, void * values[size], void * elem, int (*equals)(void * a, void * b));

int equals_int(void * a, void * b) {
    int a_as_int = *((int *) a);
    int b_as_int = *((int *) b);
    return a_as_int == b_as_int;
}

int main(void) {
    int size = 10;
    void * pvalues[size];
    for (int i = 0; i < size; i++) {
        int * current_value = (int *) malloc(sizeof(int));
        *current_value = i;
        pvalues[i] = current_value;
    }
    int value_to_search = 7;
    printf("Index of pointer to 7 is : %d\n", index_of(size, pvalues, &value_to_search, equals_int));
    return 0;
}

int index_of(const int size, void * values[size], void * elem, int (*equals)(void * a, void * b)) {
    for (int i = 0; i < size; i++) {
        if (equals(values[i], elem)) {
            return i;
        }
    }
    return -1;
}