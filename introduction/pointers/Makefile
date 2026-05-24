.PHONY: clean
.PHONY: compile

compile: addresses_and_values swapper to_upper_case

to_upper_case: to_upper_case.c
	gcc -o to_upper_case to_upper_case.c
	
swapper: swapper.c
	gcc -o swapper swapper.c
	
addresses_and_values: addresses_and_values.c
	gcc -o addresses_and_values addresses_and_values.c
	
clean:
	find . -name 'addresses_and_values' -delete
	find . -name 'swapper' -delete
	find . -name 'to_upper_case' -delete
	
