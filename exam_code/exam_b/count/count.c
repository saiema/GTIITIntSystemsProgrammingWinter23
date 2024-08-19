#include <stddef.h>
#include <assert.h>

typedef unsigned char bool;

int count(const int size, const int elements[size], bool (*accept)(int e)) {
    assert(elements != NULL);
    assert(accept != NULL);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (accept(elements[i])) {
            count++;
        }
    }
    return count;
}