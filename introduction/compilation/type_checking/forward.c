#include <stdio.h>

struct X; // forward declaration

char * x_msg(struct X * x);

void f(struct X* x) { 

    // printf("Hello %s\n", x->msg); // ILLEGAL
    printf("Hello %s\n", x_msg(x));

}  // usage of the declared, undefined structure

// void f(struct X) { }         // ILLEGAL
// struct X x;                  // ILLEGAL
// int n =sizeof(struct X);     // ILLEGAL

// later, or somewhere else altogether
struct X { 
    char * msg;
 };

 char * x_msg(struct X * x) {
    return x->msg;
 }

 void main(void) {
    struct X x = {"World!"};
    f(&x);
 }