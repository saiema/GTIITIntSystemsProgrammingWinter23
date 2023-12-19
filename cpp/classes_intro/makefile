.PHONY: compile
.PHONY: clean

compile: classes

classes: main.cpp classes.cpp
	g++ main.cpp classes.cpp -I. -o classes

clean:
	find . -name 'classes' -delete