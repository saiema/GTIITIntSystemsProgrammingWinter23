#include <student.h>
#include <strings.h>
#include <boolean.h>
#include <stdlib.h>
#include <stdio.h>

struct Student {
    string name;
    string surname;
    int id;
    string notes;
};


extern student student_new(const string const name, const string const surname, const int id) {
    student new = (student) malloc(sizeof(struct Student));
    new->name = name;
    new->surname = surname;
    new->id = id;
    new->notes = NULL;
    return new;
}

extern void student_add_note(student stdnt, const string const new_note) {
    string new_notes =  append(stdnt->notes, new_note);
    stdnt->notes = new_notes;
}

extern const string student_name(const student stdnt) {
    return stdnt->name;
}

extern const string student_surname(const student stdnt) {
    return stdnt->surname;
}

extern const int student_id(const student stdnt) {
    return stdnt->id;
}

extern string student_notes(const student stdnt) {
    return stdnt->notes;
}

extern string student_representation(const student stdnt) {
    string notes = stdnt->notes == NULL?"N/A":stdnt->notes;
    string student_rep_format = "Student {\n\tName: %s,\n\tSurname: %s,\n\tId: %d,\n\tNotes: %s\n}";
    size_t student_rep_size = (size_t) snprintf(
        NULL,
        0,
        student_rep_format,
        stdnt->name,
        stdnt->surname,
        stdnt->id,
        notes
    );
    string student_rep = (string) malloc(sizeof(char) * (student_rep_size + 1));
    snprintf(
        student_rep,
        student_rep_size + 1,
        student_rep_format,
        stdnt->name,
        stdnt->surname,
        stdnt->id,
        notes
    );
    return student_rep;
}