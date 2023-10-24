#include <my_math.h>

natural fibonacci(const natural n) {
    unsigned fib1 = 0;
    unsigned fib2 = 1;
    for (int f = 0; f < n; f++) {
        natural aux = fib1;
        fib1 = fib2;
        fib2 = aux + fib2;
    }
    return fib1;
}

natural fibonacci_nth(const natural nth) {
    return fibonacci(nth - 1);
}

boolean is_prime(natural n) {
    natural divisors = 0;
    natural current_divisor = 1;
    while (current_divisor <= n) {
        if (n % current_divisor == 0) {
            divisors++;
        }
    }
    return divisors == 2;
}

/*
* A *private* function, using static before a function definition will make that function
* unaccessible from other files.
*/
static void init_array_to_true(const natural size, boolean array[size]) {
    for (int i = 0; i < size; i++) {
        array[i] = TRUE;
    }
}

/*
* Solution taken from: https://www.geeksforgeeks.org/sieve-of-eratosthenes/
*/
natural sieve_of_eratosthenes(const natural n, boolean prime[n + 1]) {
    init_array_to_true(n + 1, prime);

    natural non_primes_found = 1;
  
    for (int p = 2; p * p <= n; p++) { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p]) { 
            // Update all multiples of p greater than or 
            // equal to the square of it numbers which are 
            // multiple of p and are less than p^2 are 
            // already been marked. 
            for (int i = p * p; i <= n; i += p) {
                non_primes_found += prime[i]?1:0;
                // The previous assignment uses a conditional expression:
                // if the condition is true, the first value is returned,
                // otherwise, the second value is returned. 
                prime[i] = FALSE;
            }
        } 
    } 

    return n - non_primes_found;
}