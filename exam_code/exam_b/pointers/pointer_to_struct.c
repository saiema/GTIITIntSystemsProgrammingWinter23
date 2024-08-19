#include <stdio.h>

struct s;
typedef struct s * s_type;

int main(void) {
    s_type var;
    printf("The address of var is %p\n", var);
    return 0;
}