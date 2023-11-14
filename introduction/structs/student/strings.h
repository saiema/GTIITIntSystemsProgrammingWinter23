/*
* string type and related operations
*/

#ifndef STRING_H
#define STRING_H

#include <boolean.h>

typedef char * string;


/*
    Returns the length of a `NULL-Terminated` string
    Takes a pointer to the first character of a string, the string must be `NULL-Terminated`
*/
extern unsigned int length(const string const str);

/*
    Returns whether two `NULL-Terminated` string are equal or not
    Takes two string (pointers to char) `string1` and `string2`
    Returns `True` iff both strings are of the same length and
    for every `i in [0..length(string1)] | string1[i] == string2[i]`
*/
extern boolean equals(const string const string1, const string const string2);

/*
    Returns the first index where a character appears in a string.
    Takes a `NULL-Terminated` string (`string`) and a character to look for (`e`)
    Returns `i` such that `string[i] == e` and there is no `j < i` where `string[j] == e`,
    returns `-1` if the character does not appear in the string
*/
extern int index_of(const string const str, const char e);

/*
    Returns the last index where a character appears in a string.
    Takes a `NULL-Terminated` string (`string`) and a character to look for (`e`)
    Returns `i` such that `string[i] == e` and there is no `j > i` where `string[j] == e`,
    returns `-1` if the character does not appear in the string
*/
extern int last_index_of(const string const str, const char e);

/*
    Returns a modified version of a string where every uppercase letter has been transformed into lowercase.
    Takes a `NULL-Terminated` string (`string`)
    Returns a new `NULL-terminated` string (`string2`) equal to `string` except for every uppercase letter
    in `string` will be in lowercase in `string2`
*/
extern string to_lower_case(const string const str);

/*
    Returns a modified version of a string where every lowercase letter has been transformed into uppercase.
    Takes a `NULL-Terminated` string (`string`)
    Returns a new `NULL-terminated` string (`string2`) equal to `string` except for every lowercase letter
    in `string` will be in uppercase in `string2`
*/
extern string to_upper_case(const string const str);

/*
    Returns a `NULL-Terminated` substring string of another `NULL-Terminated` string.
    Takes a `NULL-Terminated` string (`string`), and two natural numbers (`from`, and `to`)
    Returns a slice of `string` going from index `from` (inclusive) to index `to` (exclusive),
*/
extern string substring(const string const str, unsigned int from, unsigned int to);

/*
    Returns a `NULL-Terminated` string which is the result of appending two other strings
*/
extern string append(const string const this, const string const that);

/*
    Copies up to `size` characters from `src` into `dest`, fills the remainder of `dest` with **0**s
*/
extern string ncopy(string const dest, const string const src, const int size);

/*
    Copies `src` into `dest`, including the ending **0**
*/
extern string copy(string const dest, const string const src);


#endif