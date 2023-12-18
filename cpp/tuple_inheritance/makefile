.PHONY: compile
.PHONY: clean

compile: tuple

tuple: tuple_ints.cpp mutable_tuple_ints.cpp mutable_tuple_ints.hpp tuple_ints.hpp main.cpp
	g++ tuple_ints.cpp mutable_tuple_ints.cpp main.cpp -I. -o tuple

clean:
	find . -name 'tuple' -delete