.PHONY: compile

compile: min_max

min_max: tuple.o main.c tuple.h
	gcc -o min_max main.c tuple.o -I.

tuple.o: tuple.c tuple.h
	gcc -c -o tuple.o tuple.c -I.

.PHONY: clean

clean:
	find . -name '*.o' -delete
	find . -name 'min_max' -delete