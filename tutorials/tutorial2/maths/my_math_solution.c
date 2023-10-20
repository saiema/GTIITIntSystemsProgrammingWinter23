#include <my_math.h>
#include <assert.h>

unsigned int fibonacci(const unsigned int n) {
    switch (n) {
        case 0: return 0;
        case 1: return 1;
        default: return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

unsigned int fibonacci_nth(const unsigned int nth) {
    assert (nth >= 1);
    return fibonacci(nth - 1);
}

unsigned char is_prime(unsigned int n) {
    unsigned int divisors = 0;
    unsigned int divisor = 1;
    while (divisor <= n) {
        if (n % divisor == 0) {
            divisors++;
        }
        divisor++;
    }
    return divisors == 2;
}

static void init_array_to_true(const unsigned int size, int array[size]) {
    for (int i = 0; i < size; i++) {
        array[i] = 1;
    }
}

/*
* Solution taken from: https://www.geeksforgeeks.org/sieve-of-eratosthenes/
*/
unsigned int sieve_of_eratosthenes(const unsigned int n, int prime[n + 1]) {
    init_array_to_true(n + 1, prime);

    unsigned int non_primes_found = 1;
  
    for (int p = 2; p * p <= n; p++) { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p]) { 
            // Update all multiples of p greater than or 
            // equal to the square of it numbers which are 
            // multiple of p and are less than p^2 are 
            // already been marked. 
            for (int i = p * p; i <= n; i += p) { 
                non_primes_found += 1 * prime[i];
                prime[i] = 0;
            }
        } 
    } 

    return n - non_primes_found;
}