/*
* An example on why returning the address of a function's local variable should be avoided.
* use clang to compile this program (as gcc might fix the issue during compilation), and just
* run this as ./naughty_function
*
* Compilation would be: clang -o naughty_function naughty_function.c
*/


#include <stdlib.h>
#include <stdio.h>

int * foo(int baseValue);
int bar(int baseValue);

int main(void) {
    int * ptrToValue = foo(32);
    printf("Printing foo's local variable: %d\n", * ptrToValue);
    printf("Printing bar's return value: %d\n", bar(32));
    printf("Re-printing foo's local variable: %d\n", * ptrToValue);
}

int * foo(int baseValue) {
    int myLocalVariable = baseValue;
    if (myLocalVariable % 2 != 0) {
        myLocalVariable++;
    } else {
        myLocalVariable = myLocalVariable * 2;
    }
    return &myLocalVariable;
}

int bar(int baseValue) {
    int myLocalVariable = baseValue;
    if (myLocalVariable % 2 != 0) {
        myLocalVariable--;
    } else {
        myLocalVariable = myLocalVariable / 2;
    }
    return myLocalVariable;
}
