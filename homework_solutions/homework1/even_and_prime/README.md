# Even and Prime numbers

These two programs, `is_even.c` and `is_prime.c`, will respectively print: `<VALUE> is an even number` or `<VALUE> is not an even number` depending if `<VALUE>` is even or not;  
and, `<VALUE> is a Prime number` or `<VALUE> is not a Prime number` depending if `<VALUE>` is a prime number or not.

To compile and run these programs you should execute the following commands:

```console
me@device:~/$ gcc is_even.c -o is_even
me@device:~/$ gcc is_prime.c -o is_prime
me@device:~/$ ./is_even
42 is an even number
me@device:~/$ ./is_prime
42 is not a Prime number
me@device:~/$
```

Try modifying the value associated with symbol `VALUE` in both `is_even.c` and `is_prime` to test these programs with different values.