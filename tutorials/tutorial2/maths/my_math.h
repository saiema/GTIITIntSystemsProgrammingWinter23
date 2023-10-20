/*
*   Maths functions library
*   This header declares several math functions that we will commonly use.
*/

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
extern unsigned int fibonacci(const unsigned int n);

/*
* Returns the nth element of the fibonacci sequence
*/
extern unsigned int fibonacci_nth(const unsigned int nth);

/*
* Evaluates whether a natural number is a prime number
* Returns True iff `#(e <- [1..n] | n % e == 0) == 2`
*/
extern unsigned char is_prime(unsigned int n);

/*
* Sieve of Eratosthenes
* Given a number n, and an array of (n + 1), update the array such that
* is `array[i] is not zero (0) iff i is prime`.
* Returns the amount of primes found
*/
extern unsigned int sieve_of_eratosthenes(const unsigned int n, int prime[n + 1]);

// extern ?? min_max(unsigned int size, const int values[size]);