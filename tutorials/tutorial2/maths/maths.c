#include <stdio.h>
#include <my_math.h>

#define N 88
#define FIB_N 25
#define FIBS 20

void main(void) {
    boolean prime[N + 1];
    int primes_found = sieve_of_eratosthenes(N, prime);
    printf("Primes found %d\n", primes_found);
    for (int p = 2; p <= N; p++) {
        if (prime[p]) {
            printf("%d", p);
            if (primes_found - 1 > 0) {
                printf(", ");
                primes_found--;
            }
        }
    }
    printf("\nfibonacci(%d): %d\n", FIB_N, fibonacci(FIB_N));
    for (int i = 1; i <= FIBS; i++) {
        printf("fibonacci_nth(%d): %d\n", i, fibonacci_nth(i));
    }
}