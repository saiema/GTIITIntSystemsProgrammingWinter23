# Hello!

These two programs, `hello_world.c` and `hello.c`, will print `Hello World!` and `Hello <name>!` respectively.

To compile and run these programs you should execute the following commands:

```console
me@device:~/$ gcc hello_world.c -o hello_world
me@device:~/$ gcc hello.c -o hello
me@device:~/$ ./hello_world
Hello World!
me@device:~/$ ./hello
Hello Simón!
me@device:~/$
```

Try modifying `hello.c` so it can print your own name by changing the value associated with the `NAME` symbol.