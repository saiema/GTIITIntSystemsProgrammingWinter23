#ifndef QUADRATIC_FUNCTION_H
#define QUADRATIC_FUNCTION_H

/*
 * quadratic_functions.h: header file defining types and functions for quadratic functions.
 * This header defines functions and types to deal with quadratic functions,
 * including functions to compute the value of a function at a given point, computing a function's roots,
 * and providing string representations of functions, among others.
 * 
 * Author: N. Aguirre, S. Gutierrez
 * Date: March 16th 2023, October 10th 2023
 */

/*
 * Type Quadratic_Function: This type represents a Quadratic Function, in general, a Quadratic Function is
 * a grade 2 polinom of the form `f(x): ax^2 + bx + c`.
 */
typedef struct quadratic_function * Quadratic_Function;

/* 
 * Type Roots: A type representing the potential roots of a Quadratic Function, these roots are the solution for
 * the ecuation `0 = ax^2 + bx + c` ; There can be 0, 1, or 2 roots.
 */
typedef struct roots * Roots;

/*
* Creates a new Quadratic Function given three coefficients a, b, and c, with a being not zero (0). 
*/
extern Quadratic_Function create_quadratric_function(float a, float b, float c);

/*
* Returns the amount of calculated roots for a quadratic function. 
*/
extern int nr_roots(Roots roots);

/*
* Returns the first root of the calculated roots for a quadratic function which has
* at least one root. 
*/
extern float get_first_root(Roots roots);

/*
* Returns the second root of the calculated roots for a quadratic function which has
* two roots. 
*/
extern float get_second_root(Roots roots);

/*
 * int number_of_roots(Quadratic_Function f): Returns the number of roots of quadratic function f.
 * The return value is within interval [0,2].
 */
extern int number_of_roots(Quadratic_Function f);

/*
 * float discriminant(Quadratic_Function f): Returns the discriminant of quadratic function f.
 */
extern float discriminant(Quadratic_Function f);

/*
 * Roots compute_roots(Quadratic_Function f): Computes the roots of quadratic function f.
 * Precondition: number_of_roots(f) must be greater than zero.
 * Postcondition: Function returns the roots in a union struct (field the_root if f has a single root, 
 * fields Two_roots.root_one and Two_roots.root_two if f has two roots).
 */
extern Roots compute_roots(Quadratic_Function f);

/*
 * float apply(Quadratic_Function f, float x): Applies f on value x. 
 * Function returns the value of f(x). 
 */
extern float apply(Quadratic_Function f, float x);

/*
* Type Tuple: defines a tuple of two points
*/
typedef struct tuple * Tuple;

/*
* Creates a new Tuple given two float values to store
*/
extern Tuple create_tuple(float fst, float snd);

/*
* Returns the first value of a Tuple
*/
extern float fst(Tuple tuple);

/*
* Returnrs the second value of a Tuple
*/
extern float snd(Tuple tuple);

/*
* Generates a plot of a Quadratic Function for a specific, closed, range.
* The range will contain all values v in [range_start, range_end] defined as
* v = range_start + (step*n) with n being an int.
*/
extern Tuple * plot(Quadratic_Function f, float range_start, float range_end, float step);

/*
 * const char* to_string(Quadratic_Function f): Generates a string representation of function f
 * Function returns a string that represents f.
 */
extern const char* to_string(Quadratic_Function f);

#endif
