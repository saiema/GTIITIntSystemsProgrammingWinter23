.PHONY: compile

compile: complex

complex: complex.o main.c complex.h
	gcc -o complex main.c complex.o -I.

complex.o: complex.c complex.h
	gcc -c -o complex.o complex.c -I.

.PHONY: clean

clean:
	find . -name '*.o' -delete
	find . -name 'complex' -delete