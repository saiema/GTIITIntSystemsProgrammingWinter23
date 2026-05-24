link: assemble
	gcc -o max max.o

assemble: compile
	gcc -c -o max.o max.s

compile: preprocess
	gcc -S -o max.s max.i

preprocess: max.c
	gcc -E -o max.i max.c

.PHONY: clean
clean:
	find . -name '*.o' -delete
	find . -name '*.s' -delete
	find . -name '*.i' -delete
	find . -name 'max' -delete
