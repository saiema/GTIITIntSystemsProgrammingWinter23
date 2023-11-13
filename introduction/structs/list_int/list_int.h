/*
* List if Int Abstract Data Type
*
* This header file declares the Abstract Data Type list_int, and it's related operations
*/

#ifndef LIST_INT_H
#define LIST_INT_H

#include <boolean.h>

struct List_Int;
typedef struct List_Int * list_int;

/*
* Creates a new empty int list
*/
extern list_int list_int_empty(void);

/*
* Returns the amount of elements in a NON_NULL list
*/
extern unsigned int list_int_size(const list_int const list);

/*
* Returns if a NON-NULL list is empty
*/
extern boolean list_int_is_empty(const list_int const list);

/*
* Adds an element at the end of the list, returns `true` if the operation was successful.
*/
extern boolean list_int_add(list_int const list, const int e);

/*
* Adds an element at a particular position of the list, returns `true` if the operation was successful.
* All elements at positions `e` and above in the original list, will be moved one position to the right.
* If the position (given by `at`) is greater or equal than the size of the list, the behavior will be
* equivalent to calling `list_int_add(list, e)`
*/
extern boolean list_int_add_at(list_int const list, const int e, const int at);

/*
* Returns the element of a NON-NULL list (`list`) at a valid position `at`. 
*/
extern int list_int_at(const list_int const list, const int at);

/*
* Removes (and returns) the first element of a NON-NULL and NON-EMPTY list
*/
extern int list_int_del_front(list_int const list);

/*
* Removes (and returns) the last element of a NON-NULL and NON-EMPTY list
*/
extern int list_int_del_back(list_int const list);

/*
* Removes (and returns) the element at a valid position `at` of a NON-NULL and NON-EMPTY list
* All elements at the right of position `at` will be moved one position to the left.
*/
extern int list_int_del_at(list_int const list, const int at);

/*
* Returns `true` iff both, NON-NULL lists, `list_1` and `list_2` have the same elements in the same order.
*/
extern boolean list_int_equals(const list_int const list_1, const list_int const list_2);

/*
* Returns a string representation:
* * If a list is `NULL` it will return `"NULL"`
* * If a list is empty it will return `"[]"`
* * If a list is not empty, it will return a string starting with `'['`, followed by all the elements of the list, separated by comma, and ending with `']'`
*/
extern char * list_int_representation(const list_int const list);

/*
* For a NON-NULL list, it will free all associated (dynamic) memory.
*/
extern void list_int_drop(list_int list);

#endif