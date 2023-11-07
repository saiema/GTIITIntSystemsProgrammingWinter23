# Compilation phases

Given two initial files `main.c` and `hello.c` we will explain all the phases of the compilation process. We will also
show how to call the `gcc` compiler to execute *up to* a certain phase (only required phases will be executed).

## Preprocessing

To run up to this phase one must run `gcc -E <filename>.c -o <filename>.i`, e.g.: `gcc -E main.c -o main.i` and `gcc -E hello.c -o hello.i`, the `.i` extension is the  
convention for preprocessed files.

This phase will resolve all preprocessor commands in a file, in this course we will only consider the following ones:

  1. `#include <file>` The preprocessor will replace this command by the contents of file `file`, it will look for `file` in a set of predefined folders (or directories),  
                       one can add customs folders (or directories) using the `-I<path to folder>` for each new folder one wants to add.  
                       *note: the -I flag affects all compilation phases*  

  2. `#include "file"` The sames as the previous command but `file` will be searched in the *working directory*, i.e.: the directory in which `gcc` is being executed.
  3. `#define SYMBOL REPLACEMENT` This will replace every occurrence of `SYMBOL` with `REPLACEMENT`, e.g.: `#define TRUE 1` will replace every occurrence of `TRUE` with `1`.
  4. `#ifdef SYMBOL BODY #endif` If `SYMBOL` is defined, it will process `BODY`, if not it will ignore it. An example of this could be:
                                 
```C
//will only parse `#include <my_code.h>` of `MY_SYMBOL` is defined
#ifdef MY_SYMBOL
#include <my_code.h>
#endif
```
  5. `#ifndef SYMBOL BODY #endif` Same as before, but wil process `BODY` if `SYMBOL` is **NOT** defined.

## Compilation

To run up to this phase one must run `gcc -S <filename>.i -o <filename>.s`, e.g.: `gcc -S main.i -o main.s` and `gcc -S hello.i -o hello.s`, the `.s` extension is the  
convention for compiled files. One could also start from a `.c` and run both the *preprocessing* and *compilation* phases.

This phase will translate code written in a higher level language to a lower level language, in our case it will take *C* code and generate *assembly* code, the generated file is still viewable with just a text editor.

## Assembling

To run up to this phase one must run `gcc -c <filename>.s -o <filename>.o`, e.g.: `gcc -c main.s -o main.o` and `gcc -c hello.s -o hello.o`, the `.o` extension is the  
convention for assembled files, the output is also known as an **Object File** and it's almost what the CPU can execute. One could also start from a `.c` and run the *preprocessing*, *compilation*, and *assembling* phases.

This phase translate assembly code into machine readable code (what the CPU can execute), but the result is still not an executable.

## Linking

To run up to this phase one must run `gcc <filename>.o -o <filename>`, e.g.: `gcc main.o hello.o -o hello`, the output is known as an **Executable** and it's what the CPU can execute. One could also start from a `.c` and run the *preprocessing*, *compilation*, *assembling*, and *linking* phases.

One could run the linker `ld` instead of using `gcc`, but the latter will set a lot of different arguments for the linker (`ld`).

This phase will merge all object files (`.o` extension) into one executable, will resolve all static symbol addresses (functions and variables defined in any of the object files), and will add code to resolve, during runtime, all dynamic symbols (functions and variables defined in shared libraries like the *C Standard Library*).