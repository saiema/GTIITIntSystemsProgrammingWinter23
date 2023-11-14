#include <stdio.h>
#include <student.h>


int main(void) {
    student me = student_new("Simón", "Gutiérrez Brida", 42);
    printf("%s\n", student_representation(me));
    student_add_note(me, "\nStarted studying Microbiology\n");
    student_add_note(me, "\nChanged to computer analyst\n");
    student_add_note(me, "\nKept going for the full 5 year degree in Computer Science\n");
    printf("%s\n", student_representation(me));
}