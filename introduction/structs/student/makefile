.PHONY: compile
.PHONY: clean

compile: test_student

test_student: main.c student.o student.h strings.o strings.h boolean.o boolean.h
	gcc -o test_student main.c student.o strings.o boolean.o -I.

student.o: student.c student.h strings.h boolean.h
	gcc -c -o student.o student.c -I.

strings.o: strings.c strings.h boolean.h
	gcc -c -o strings.o strings.c -I.

boolean.o: boolean.c boolean.h
	gcc -c -o boolean.o boolean.c -I.

clean:
	find . -name '*.o' -delete
	find . -name 'test_student' -delete
