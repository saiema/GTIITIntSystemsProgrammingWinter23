# Using include

This exercise is meant to understand how `include` works.

## Getting the solution

Run `gcc -E -x c -P 42.txt` to get the expected result.

The `-E` flag indicates to only run the *preprocessing* phase; the `-x c` flag is indicating `gcc` to treat `42.txt` as a **C** file (if not it will treat the file as either a compilation script or a binary file); the `-P` flag indicates `gcc` to not include comments in the output (you can try running the command without that flag to see what happens).

The result will be:

```console
me@device:~$ ls
42.txt README.md answer_to_life.txt is.txt
me@device:~$ gcc -E -x c -P 42.txt
The answer to life
is
42
me@device:~$
```