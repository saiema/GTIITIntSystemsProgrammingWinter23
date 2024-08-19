#include <stdio.h>
#include <stdlib.h>

struct s;
typedef struct s * s_type;
int main(void) {
    s_type var = (s_type) malloc(sizeof(struct s));
    printf("The address of var is %p\n", var);
    return 0;
}