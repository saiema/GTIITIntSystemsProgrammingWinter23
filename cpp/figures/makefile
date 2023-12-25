.PHONY: compile
.PHONY: clean

compile: figures

figures: main.cpp figure.hpp circle.o rectangle.o triangle.o point.o
	g++ main.cpp circle.o rectangle.o triangle.o point.o -I. -o figures

circle.o: figure.hpp circle.cpp
	g++ -c circle.cpp -I. -o circle.o

rectangle.o: figure.hpp rectangle.cpp
	g++ -c rectangle.cpp -I. -o rectangle.o

triangle.o: figure.hpp triangle.cpp
	g++ -c triangle.cpp -I. -o triangle.o

point.o: figure.hpp point.cpp
	g++ -c point.cpp -I. -o point.o

clean:
	find . -name 'figures' -delete
	find . -name '*.o' -delete