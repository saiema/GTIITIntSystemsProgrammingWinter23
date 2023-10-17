#include <stdio.h>
#include <stdlib.h>

#define SIZE 42
#define MAX_VALUE 15
#define FALSE 0
#define TRUE 1

unsigned char and(const unsigned char a, const unsigned char b) {
    //TODO: complete
}

unsigned char not(const unsigned char a) {
    //TODO: complete
}

unsigned char or(const unsigned char a, const unsigned char b) {
    //TODO: complete
}

unsigned char xor(const unsigned char a, const unsigned char b) {
    //TODO: complete
}

unsigned int length(const char * string) {
    //TODO: complete
}

unsigned char equals(const char * string1, const char * string2) {
    //TODO: complete
}

int index_of(const char * string, const char e) {
    //TODO: complete
}

int last_index_of(const char * string, const char e) {
    //TODO: complete
}

#define LOWER_CASE_MIN 97
#define LOWER_CASE_MAX 122

#define UPPER_CASE_MIN 65
#define UPPER_CASE_MAX 90

#define CASE_DIFF 32

char * to_lower_case(const char * string) {
    //TODO: complete
}

char * to_upper_case(const char * string) {
    //TODO: complete
}

//TODO create a private function (use the `static` keyword) which will
//     switch a range of characters by a certain constant value, the profile
//     will be:
//     `static char shift_in_range(const char c, unsigned int range_start, unsigned int range_end, const int shift)`

char * substring(const char * string, unsigned int from, unsigned int to) {
    //TODO: complete
}

int max(const int a, const int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int maximum(const int size, int values[size]) {
    //TODO: complete
}

unsigned char is_even(const int value) {
    if (value & 1) {
        return FALSE;
    } else {
        return TRUE;
    }
}

unsigned char is_odd(const int value) {
    //TODO: complete
}

unsigned char is_prime(const unsigned int value) {
    //TODO: complete
}

unsigned int fibonnaci(const unsigned int nth) {
    //TODO: complete
}

void print_array(const int size, const int values[size]) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", values[i]);
        if (i + 1 < size) {
            printf(", ");
        }
    }
    printf("]\n");
}

void main(int argc, char ** argv) {
    printf("max(1,2): %d\n", max(1,2));
    printf("max(2,1): %d\n", max(2,1));
    printf("max(-1, 1): %d\n", max(-1, 1));
    printf("max(1, -1): %d\n", max(1, -1));

    int values[SIZE];
    int seed = argc>1?atoi(argv[1]):33;
    srand(seed);
    for (int i = 0; i < SIZE; i++) {
        values[i] = rand() % MAX_VALUE;
    }
    print_array(SIZE, values);
    printf("maximum is: %d\n", maximum(SIZE, values));

    for (int i = 0; i < SIZE; i++) {
        printf("is_even(%1$d): %2$d\t|\tis_odd(%1$d): %3$d\t|\tis_prime(%1$d): %4$d\n",
            values[i],
            is_even(values[i]),
            is_odd(values[i]),
            is_prime(values[i])
        );
    }
    
    printf("Fibonnaci sequence:\n");
    for (int ith = 1; ith < 20; ith++) {
        printf("%dth fibonacci: %d\n", ith, fibonnaci(ith));
    }
    const char * hello_there = "Hello there! - General Kenobi!";
    const char * hello = "Hello!";
    const char * hello_ = "Hello! ";
    const char * h3llo = "H3llo!";
    printf("length(%s): %d\n", hello_there, length(hello_there));
    printf("to_lower_case(%s): %s\n", hello_there, to_lower_case(hello_there));
    printf("to_upper_case(%s): %s\n", hello_there, to_upper_case(hello_there));
    printf("index_of(%s, %c): %d\n", hello_there, 'e', index_of(hello_there, 'e'));
    printf("last_index_of(%s, %c): %d\n", hello_there, 'e', last_index_of(hello_there, 'e'));
    printf("equals(%s, %s): %d\n", hello, hello, equals(hello, hello));
    printf("equals(%s, %s): %d\n", hello_, hello, equals(hello_, hello));
    printf("equals(%s, %s): %d\n", hello, hello_, equals(hello, hello_));
    printf("equals(%s, %s): %d\n", h3llo, hello, equals(h3llo, hello));
    printf("equals(%s, %s): %d\n", hello, h3llo, equals(hello, h3llo));
    printf("equals(%s, %s): %d\n", h3llo, hello_, equals(h3llo, hello_));
    printf("equals(%s, %s): %d\n", hello_, h3llo, equals(hello_, h3llo));
    printf("substring(%s, %d, %d): %s\n",
        hello_there, 0, length(hello_there),
        substring(hello_there, 0, length(hello_there))
    );
    printf("substring(%s, %d, %d): %s\n",
        hello_there, 15, 30,
        substring(hello_there, 15, 30)
    );
    printf("substring(%s, %d, %d): %s\n",
        hello_there, 15, 22,
        substring(hello_there, 15, 22)
    );
}