#include <stdio.h>
#include <stdlib.h>

struct Student {
    const char * const name;
    const char * const surname;
    const int id;
    char * notes;
};

static struct Student student_new(const char * const name, const char * const surname, const int id);
static void student_add_note(struct Student student, const char * const new_note);
static const char * student_name(const struct Student student);
static const char * student_surname(const struct Student student);
static const int student_id(const struct Student student);
static char * student_notes(const struct Student student);
static char * student_representation(const struct Student student);

static int length(const char * const str);
static char * append(const char * const this, const char * const that);
static char * copy(char * const dest, const char * const src);
static char * ncopy(char * const dest, const char * const src, const int size);

int main(void) {
    struct Student me = student_new("Simón", "Gutiérrez Brida", 42);
    printf("%s\n", student_representation(me));
    student_add_note(me, "\nStarted studying Microbiology\n");
    student_add_note(me, "\nChanged to computer analyst\n");
    student_add_note(me, "\nKept going for the full 5 year degree in Computer Science\n");
    printf("%s\n", student_representation(me));
}

static struct Student student_new(const char * const name, const char * const surname, const int id) {
    struct Student new = {.name = name, .surname = surname, .id = id, .notes = NULL};
    return new;
}

static void student_add_note(struct Student student, const char * const new_note) {
    char * new_notes =  append(student.notes, new_note);
    student.notes = new_notes;
}

static const char * student_name(const struct Student student) {
    return student.name;
}

static const char * student_surname(const struct Student student) {
    return student.surname;
}

static const int student_id(const struct Student student) {
    return student.id;
}

static char * student_notes(const struct Student student) {
    return student.notes;
}

static char * student_representation(const struct Student student) {
    char * notes = student.notes == NULL?"N/A":student.notes;
    char * student_rep_format = "Student {\n\tName: %s,\n\tSurname: %s,\n\tId: %d,\n\tNotes: %s\n}";
    size_t student_rep_size = (size_t) snprintf(
        NULL,
        0,
        student_rep_format,
        student.name,
        student.surname,
        student.id,
        notes
    );
    char * student_rep = (char *) malloc(sizeof(char) * (student_rep_size + 1));
    snprintf(
        student_rep,
        student_rep_size + 1,
        student_rep_format,
        student.name,
        student.surname,
        student.id,
        notes
    );
    return student_rep;
}

static int length(const char * const str) {
    if (str == NULL) {
        return 0;
    }
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

static char * append(const char * const this, const char * const that) {
    if ((this == NULL) && (that == NULL)) {
        return NULL;
    } else if (this == NULL) {
        char * copy_of_that = (char *) malloc(sizeof(char) * (length(that) + 1));
        return copy(copy_of_that, that);
    } else if (that == NULL) {
        char * copy_of_this = (char *) malloc(sizeof(char) * (length(this) + 1));
        return copy(copy_of_this, this);
    } else {
        int length_this = length(this);
        int length_that = length(that);
        char * this_and_that = (char *) malloc(sizeof(char) * (length_this + length_that + 1));
        ncopy(this_and_that, this, length_this);
        ncopy((this_and_that+length_this), that, length_that + 1);
        return this_and_that;
    }
}

static char * ncopy(char * const dest, const char * const src, const int size) {
    int i = 0;
    while (src[i] != '\0' && i < size) {
        dest[i] = src[i];
        i++;
    }
    return dest;
}

static char * copy(char * const dest, const char * const src) {
    int size_src = length(src);
    return ncopy(dest, src, size_src + 1);
}
