def foo(a):
	print("Reference of 'a' at the start of foo: {}".format(id(a)))
	a += 1
	print("Reference of 'a' at the end of foo: {}".format(id(a)))


val_a = 0
print("Reference of 'val_a' before calling foo: {}".format(id(val_a)))
foo(val_a)
print("Reference of 'val_a' after calling foo: {}".format(id(val_a)))

my_tuple = (1, 2, 3)
print(my_tuple)
my_tuple[1] = 42
print(my_tuple)

