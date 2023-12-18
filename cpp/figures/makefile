.PHONY: compile
.PHONY: clean

compile: figures

figures: main.cpp figure.hpp circle.cpp rectangle.cpp
	g++ main.cpp circle.cpp rectangle.cpp -I. -o figures

clean:
	find . -name 'figures' -delete