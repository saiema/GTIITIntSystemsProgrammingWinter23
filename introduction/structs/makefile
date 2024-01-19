.PHONY: compile
.PHONY: clean

BOOLEAN=./boolean/
LIST_INT=./list_int/

compile: maximum

maximum: maximum.c $(BOOLEAN)boolean.o $(BOOLEAN)boolean.h $(LIST_INT)llist_int.o $(LIST_INT)list_int.h
	gcc -o maximum maximum.c $(BOOLEAN)boolean.o $(LIST_INT)llist_int.o -I$(LIST_INT) -I$(BOOLEAN)

$(LIST_INT)llist_int.o: $(LIST_INT)llist_int.c $(LIST_INT)list_int.h $(BOOLEAN)boolean.h
	gcc -c -o $(LIST_INT)llist_int.o $(LIST_INT)llist_int.c -I$(LIST_INT) -I$(BOOLEAN)

$(BOOLEAN)boolean.o: $(BOOLEAN)boolean.c $(BOOLEAN)boolean.h
	gcc -c -o $(BOOLEAN)boolean.o $(BOOLEAN)boolean.c -I$(BOOLEAN)

test_list: test_list.c $(BOOLEAN)boolean.o $(BOOLEAN)boolean.h $(LIST_INT)llist_int.o $(LIST_INT)list_int.h
	gcc -o test_list test_list.c $(BOOLEAN)boolean.o $(LIST_INT)llist_int.o -I$(LIST_INT) -I$(BOOLEAN)

clean:
	find . -name '*.o' -delete
	find . -name 'maximum' -delete
	find . -name 'test_list' -delete