compile: quadratic_functions.c quadratic_functions.h quadratic_roots.c
	gcc -o qfunctions quadratic_functions.c quadratic_roots.c -lm
	

.PHONY: clean
clean:
	find . -name '*.o' -delete
	find . -name 'qfunctions' -delete
