.PHONY: compile
.PHONY: clean

compile: palindrome

palindrome: palindrome.c boolean.o boolean.h lstack_char.o stack_char.h lstack_int.o stack_int.h
	gcc -o palindrome palindrome.c boolean.o lstack_int.o lstack_char.o -I.

lstack_char.o: lstack_char.c stack_char.h
	gcc -c -o lstack_char.o lstack_char.c -I.

lstack_int.o: lstack_int.c stack_int.h
	gcc -c -o lstack_int.o lstack_int.c -I.

boolean.o: boolean.c boolean.h
	gcc -c -o boolean.o boolean.c -I.


clean:
	find . -name '*.o' -delete
	find . -name 'palindrome' -delete