import strings
from my_math import maximum_of_ints as maxs

my_haystack: str = "Hello there General Kenobi!"
my_numbers: list[int] = [1, 200, 3, 4, 5, 6, 1, 42, 88, 102]
print(strings.to_upper_case(my_haystack))
print(maxs(my_numbers))