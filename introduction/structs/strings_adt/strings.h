/*
* String Abstract Data Type
*
* This header file declares the Abstract Data Type string, and it's related operations
*/

#ifndef STRING_H
#define STRING_H

#include <boolean.h>

struct String;
typedef struct String * string;


/*
* Creates an empty string
*/
string string_empty(void);

/*
* Creates a new string from a C string (a pointer to a sequence of characters ending with a **0**)
*/
string string_from(const char * const cstring);

/*
* Calculates the length of a string.
* Arguments:
* str : a string value
* Return Value:
* the amount of characters in `str`, **0** of `str` is `NULL`.
*/
extern unsigned int string_length(const string const str);

/*
* Returns whether two strings are equal or not
* Arguments:
* str1 : a string value
* str2 : another string value
* Return value:
* `true` iff both `str1` and `str2` are `NULL` or if `str1` and `str2` have the same characters in the same order.
*/
extern boolean string_equals(const string const str1, const string const str2);

/*
* Returns the first index where a character appears in a string.
* Arguments:
* str : a string value
* e : a character
* Return value:
* the index of the first occurrence of `e` in `str` considering characters in `str` start at position **0**.
* **-1** if `e` doesn't exists in `str`.
*/
extern int string_index_of(const string const str, const char e);

/*
* Returns the last index where a character appears in a string.
* Arguments:
* str : a string value
* e : a character
* Return value:
* the index of the last occurrence of `e` in `str` considering characters in `str` start at position **0**.
* **-1** if `e` doesn't exists in `str`.
*/
extern int string_last_index_of(const string const str, const char e);

/*
* Returns a new string which will be a modified version of a string where every uppercase letter has been transformed into lowercase.
* Arguments:
* str : a string value
* Return value:
* A new string equals to `str`, except that every UpperCase character ('A' - 'Z') will be turned into it's LowerCase version ('a' - 'z').
* `NULL` if `str` is `NULL`
*/
extern string string_to_lower_case(const string const str);

/*
* Returns a new string which will be a modified version of a string where every lowercase letter has been transformed into uppercase.
* Arguments:
* str : a string value
* Return value:
* A new string equals to `str`, except that every LowerCase character ('a' - 'z') will be turned into it's UpperCase version ('A' - 'Z').
* `NULL` if `str` is `NULL`
*/
extern string string_to_upper_case(const string const str);

/*
* Returns a slice of a string.
* Arguments:
* str : a string value
* from : the index of the start of the slice
* to : the index of the end of the slice
* Return value:
* A new string `slice` such that `slice` will be equal to the substring of `str` going from
* index `from` to index `to - 1`.
* `NULL` if `str` is `NULL`
* Examples:
* `substring("Hello", 2, 3) == "l"`
* `substring("Hello", 2, 5) == "llo"`
* __note: input strings are written as C string to simplify the examples__
*/
extern string string_substring(const string const str, unsigned int from, unsigned int to);

/*
* Returns a new string from appending two strings
* Arguments:
* thiz : a string value
* that : a string value
* Return value:
* `NULL` iff `thiz` and `that` are both `NULL`
* a copy of `thiz` if `that` is `NULL`
* a copy of `that` if `thiz` is `NULL`
* a new string composed of `thizthat`
*/
extern string string_append(const string const thiz, const string const that);
/*
* Frees the memory associated with a boolean value
*/
extern void string_drop(const string const str);

#endif