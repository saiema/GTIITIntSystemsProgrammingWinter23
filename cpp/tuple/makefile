.PHONY: compile
.PHONY: clean

compile: tuple

tuple: tuple_ints.cpp tuple_ints.hpp main.cpp
	g++ tuple_ints.cpp main.cpp -I. -o tuple

clean:
	find . -name 'tuple' -delete