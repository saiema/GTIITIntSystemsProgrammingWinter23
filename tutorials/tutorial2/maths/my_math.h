/*
*   Maths functions library
*   This header declares several math functions that we will commonly use.
*/

/*
* Defines a boolean type, this is just an alias for `unsigned char`.
*/
typedef unsigned char boolean;

/*
* Defines a natural type, this is just an alias for `unsigned int`.
*/
typedef unsigned int natural;

/*
* The constant TRUE
*/
#define TRUE 1

/*
* The constant TRUE
*/
#define FALSE 0

/*
* Calculates the fibonacci of a number according to the
* definition
* ```
* fibonacci(n):
* n == 0 = 0
* n <= 1 = 1
* otherwise fibonacci(n - 1) + fibonacci(n - 2)
* ```
*/
extern natural fibonacci(const natural n);

/*
* Returns the nth element of the fibonacci sequence
*/
extern natural fibonacci_nth(const natural nth);

/*
* Evaluates whether a natural number is a prime number
* Returns TRUE iff `#(e <- [1..n] | n % e == 0) == 2`
*/
extern boolean is_prime(natural n);

/*
* Sieve of Eratosthenes
* Given a number n, and an array of (n + 1), update the array such that
* is `array[i] is not zero (0) iff i is prime`.
* Returns the amount of primes found
*/
extern natural sieve_of_eratosthenes(const natural n, boolean prime[n + 1]);