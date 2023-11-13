/*
* Student Record (student) Abstract Data Type
*
* This header file declares the Abstract Data Type student, and it's related operations
*/

#ifndef STUDENT_HEADER
#define STUDENT_HEADER

#include <string.h>

struct Student; // implementation related structure
typedef struct Student * student; // abstract data type

/*
* Creates a new student with no initial notes
* Arguments:
* name : the name of the student (as a string value)
* surname : the surname of the student (as a string value)
* id : the id of the new student
*/
extern student student_new(const string const name, const string const surname, const int id);

/*
* 
*/
extern void student_add_note(student stdnt, const string const new_note);
extern const string student_name(const student const stdnt);
extern const string student_surname(const student const stdnt);
extern const int student_id(const student const stdnt);
extern const string student_notes(const student const stdnt);
extern char * student_representation(const student const stdnt);

#endif