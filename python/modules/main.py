import strings
from my_math import maximum_of_ints as maxs
import my_math
from List import LinkedList

import sys

if __name__ == "__main__":
    my_haystack: str = "Hello there General Kenobi!"
    my_numbers: list[int] = [1, 200, 3, 4, 5, 6, 1, 42, 88, 102]
    print(strings.to_upper_case(my_haystack))
    print(maxs(my_numbers))
    print(strings.reverse(my_haystack))
    print(my_math.reverse(123))
    my_list: LinkedList = LinkedList()
    my_list.append(1)
    my_list.append(2)
    my_list.append(3)
    print(my_list.to_string())
    print("Arguments received {}".format(len(sys.argv)))
    for arg in sys.argv:
        print("Command-line argument: {}".format(arg))
