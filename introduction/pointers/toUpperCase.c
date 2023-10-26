#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    for (int i = 1; i < argc; i++) {
        printf("%s", toUpperCase(argv[i]));
        if (i + 1 < argc) {
            printf(" ");
        }
    }
    if (argc > 1) {
        printf("\n");
    }
    return 0;
}