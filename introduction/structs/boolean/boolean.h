/*
* Boolean Abstract Data Type
*
* This header file declares the Abstract Data Type boolean, and it's related operations
*/

#ifndef BOOLEAN_H
#define BOOLEAN_H

struct Boolean;
typedef struct Boolean * boolean;

/*
* Creates a new boolean representing True
*/
extern boolean boolean_true(void);

/*
* Creates a new boolean representing False
*/
extern boolean boolean_false(void);

#define BOOLEAN_TRUE boolean_true()
#define BOOLEAN_FALSE boolean_false()

/*
* Returns a new boolean representing the result of the logical conjunction between two boolean values.
* Arguments:
* a : a **NON-NULL** boolean value
* b : a **NON-NULL** boolean value
* Return value:
* a boolean `c` representing `a and b`
*/
extern boolean boolean_and(const boolean const a, const boolean const b);

/*
* Returns a new boolean representing the result of the logical disjunction between two boolean values.
* Arguments:
* a : a **NON-NULL** boolean value
* b : a **NON-NULL** boolean value
* Return value:
* a boolean `c` representing `a or b`
*/
extern boolean boolean_or(const boolean const a, const boolean const b);

/*
* Returns a new boolean representing the result of the logical exclusive disjunction between two boolean values.
* Arguments:
* a : a **NON-NULL** boolean value
* b : a **NON-NULL** boolean value
* Return value:
* a boolean `c` representing `a xor b`
*/
extern boolean boolean_xor(const boolean const a, const boolean const b);

/*
* Returns a new boolean representing the result of the logical negation of a boolean value.
* Arguments:
* b : a **NON-NULL** boolean value
* Return value:
* a boolean `c` representing `not b`
*/
extern boolean boolean_not(const boolean const b);

/*
* Returns the representation of a boolean value as a pointer to a sequence of char's ending with a **0**.
* Arguments:
* b : a **NON-NULL** boolean value
* Return value:
* a C string representing the boolean value `b`, this string will either be `TRUE` or `FALSE` depending on `b`.
*/
extern char * boolean_representation(const boolean const b);

/*
* Returns a boolean value from a C string
* Arguments:
* str : a C string representing a boolean value
* Return value:
* a boolean value representing `true` if a string `TRUE` is provided, `false` if a string `FALSE` is provided;
* any other value will result in a boolean value representing `false` being returned.
*/
extern boolean boolean_from_string(const char * const str);

/*
* Returns a boolean value from an int value.
* Arguments
* value : an int value
* Return value:
* a boolean value representing `false` if `value` is **0**, a boolean value representing `true` for any other value.
*/
extern boolean boolean_from_int(const int value);

/*
* Frees the memory associated with a boolean value
*/
extern void boolean_drop(const boolean const value);

#endif