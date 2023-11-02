.PHONY: compile

compile: tutorial1

.PHONY: clean
clean:
	find . -name '*.o' -delete
	find . -name 'tutorial1' -delete

tutorial1: main.o boolean.o strings.o math.o standard.h
	gcc -o tutorial1 main.o boolean.o strings.o math.o -I.

main.o: main.c standard.h
	gcc -c -o main.o main.c -I.

boolean.o: boolean.c standard.h
	gcc -c -o boolean.o boolean.c -I.

strings.o: strings.c standard.h
	gcc -c -o strings.o strings.c -I.

math.o: math.c standard.h
	gcc -c -o math.o math.c -I.