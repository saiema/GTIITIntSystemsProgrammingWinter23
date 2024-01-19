/*
* A generic list Abstract Data Type
*
* This header file declares the Abstract Data Type list, and it's related operations
*/

#ifndef LIST_H
#define LIST_H

#include <boolean.h>

struct List;
typedef struct List * list;

/*
* Creates a new empty list
*/
extern list list_new(void);

/*
* Returns the amount of elements in a NON_NULL list
*/
extern unsigned int list_size(const list const lst);

/*
* Returns if a NON-NULL list is empty
*/
extern boolean list_is_empty(const list const lst);

/*
* Adds an element at the end of the list, returns `true` if the operation was successful.
*/
extern boolean list_add(list const lst, void * e);

/*
* Adds an element at a particular position of the list, returns `true` if the operation was successful.
* All elements at positions `e` and above in the original list, will be moved one position to the right.
* If the position (given by `at`) is greater or equal than the size of the list, the behavior will be
* equivalent to calling `list_add(list, e)`
*/
extern boolean list_add_at(list const lst, void * e, const int at);

/*
* Returns the element of a NON-NULL list (`list`) at a valid position `at`. 
*/
extern void * list_at(const list const lst, const int at);

/*
* Removes (and returns) the first element of a NON-NULL and NON-EMPTY list
*/
extern void * list_del_front(list const lst);

/*
* Removes (and returns) the last element of a NON-NULL and NON-EMPTY list
*/
extern void * list_del_back(list const lst);

/*
* Removes (and returns) the element at a valid position `at` of a NON-NULL and NON-EMPTY list
* All elements at the right of position `at` will be moved one position to the left.
*/
extern void * list_del_at(list const lst, const int at);

/*
* Returns `true` iff both, NON-NULL lists, `lst_1` and `lst_2` have the same elements in the same order.
*/
extern boolean list_equals(const list const lst_1, const list const lst_2);

/*
* Returns `true` iff both, NON-NULL lists, `list_1` and `list_2` have the same elements in the order, according to an equality function.
*/
extern boolean list_deep_equals(const list const list_1, const list const list_2, boolean (*equal(void *, void *)));

/*
* Given a NON-NULL list `lst`, will return a new list with all the elements in `lst` for which the function `accept` returns `true`.
*/
extern list filter(const list const lst, boolean (*accept)(void *));

/*
* Given a NON-NULL list `lst`, will return a new list with all elements in `lst`for which the function `accept` returns `true`.
*/
extern list filter2(const list const lst, boolean (*accept)(list, void *));

/*
* Given a NON-NULL list `lst`, will return how many elements in `lst` satisfy the function `accept`.
*/
extern int count(const list const lst, boolean (*accept)(void *));

/*
* Given a NON-NULL list `lst`, will return how many elements in `lst` satisfy the function `accept`.
*/
extern int count2(const list const lst, boolean (*accept)(list, void *));

/*
* Given a NON-NULL list `lst`, will return `true` iff every element in `lst` satisfies function `accept`.
*/
extern boolean all(const list const lst, boolean (*accept)(void *));

/*
* Given a NON-NULL list `lst`, will return `true` iff every element in `lst` satisfies function `accept`.
*/
extern boolean all2(const list const lst, boolean (*accept)(list, void *));

/*
* Given a NON-NULL list `lst`, will return `true` iff there is no element in `lst` that satisfies function `accept`.
*/
extern boolean not(const list const lst, boolean (*accept)(void *));

/*
* Given a NON-NULL list `lst`, will return `true` iff there is no element in `lst` that satisfies function `accept`.
*/
extern boolean not2(const list const lst, boolean (*accept)(list, void *));

/*
* Given a NON-NULL list `lst`, will return `true` iff there is at least one element in `lst` that satisfies function `accept`.
*/
extern boolean some(const list const lst, boolean (*accept)(void *));

/*
* Given a NON-NULL list `lst`, will return `true` iff there is at least one element in `lst` that satisfies function `accept`.
*/
extern boolean some2(const list const lst, boolean (*accept)(list, void *));

/*
* Returns a string representation:
* * If a list is `NULL` it will return `"NULL"`
* * If a list is empty it will return `"[]"`
* * If a list is not empty, it will return a string starting with `'['`, followed by all the elements of the list, separated by comma, and ending with `']'`
*/
extern char * list_representation(const list const lst);

/*
* For a NON-NULL list, it will free all associated (dynamic) memory.
*/
extern void list_drop(list lst);

#endif