/*
* Boolean type and related operations
*/

#ifndef BOOLEAN_H
#define BOOLEAN_H

/*
*    An alias to `unsigned char` to better represent a `boolean`
*/
typedef unsigned char boolean;

/*
*    A `boolean` constant representing a `True` value
*/
#define TRUE 1

/*
*    A `boolean` constant representing a `False` value
*/
#define FALSE 0

/*
    Returns the logical and between two boolean values
    Takes two `boolean` values `a` and `b`
    Returns `a && b`
*/
extern boolean and(const boolean a, const boolean b);

/*
    Returns the logical not of a boolean value
    Takes one `boolean` value `a`
    Returns `! a`
*/
extern boolean not(const boolean a);

/*
    Returns the logical or between two boolean values
    Takes two `boolean` values `a` and `b`
    Returns `a || b`
*/
extern boolean or(const boolean a, const boolean b);

/*
    Returns the logical xor between two boolean values
    Takes two `boolean` values `a` and `b`
    Returns `a ^ b`
*/
extern boolean xor(const boolean a, const boolean b);

#endif