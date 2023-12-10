def std_max(a: int, b: int) -> int:
    """
    Returns the maximum of two integer values
    :param a: the first integer value
    :param b: the second integer value
    :return: 'a' iff 'a' is greater than 'b', otherwise it returns 'b'
    """
    if a > b:
        return a
    else:
        return b


def maximum(values: [int]) -> int:
    """
    Given a non-NULL and non-empty list of integers, it returns the maximum value
    :param values: a list of values
    :return: the maximum value in 'values'
    """
    assert len(values) > 0  # values, bool(values), len(values) are other alternatives
    current_max: int = values[0]
    for i in range(1, len(values)):
        if values[i] > current_max:
            current_max = values[i]
    return current_max


def is_even(value: int) -> bool:
    """
    Checks whether an integer value is even or not
    :param value: the value to check
    :return: 'true' iff 'value' is even
    """
    return value % 2 == 0


def is_odd(value: int) -> bool:
    """
    Checks whether an integer value is odd or not
    :param value: the value to check
    :return: 'true' iff 'value' is odd
    """
    return value % 2 != 0


def is_prime(value: int) -> bool:
    """
    Checks whether an integer value is a prime number or not
    :param value: the value to check
    :return: 'true' iff 'value' has only 2 divisors (1, and 'value')
    """
    divisors: int = 0
    divisor: int = 1
    while divisor <= value:
        if value % divisor == 0:
            divisors += 1
    return divisors == 2


def fibonacci(n: int) -> int:
    """
    Returns fibonacci of n
    :param n: the value for which to calculate fibonacci
    :return: 0 if 'n' is 0; 1 if 'n' is 1; otherwise fibonacci of 'n - 1' plus fibonacci of 'n - 2'
    """
    if n == 0:
        return 0
    if n == 1:
        return 1
    return fibonacci(n - 1) + fibonacci(n - 2)


def length(string: str) -> int:
    """
    Returns the length of a string
    :param string: the string to use
    :return: the length of the string
    """
    # It is possible to just use len(string)
    counter: int = 0
    for _ in string:
        counter += 1
    return counter


def equals(string1: str, string2: str) -> bool:
    """
    Compares if two strings to check if they are equal
    :param string1: the first string to compare
    :param string2: the second string to compare
    :return: True iff `string1` is equal to `string2`
    """
    if len(string1) != len(string2):
        return False
    for i in range(len(string1)):
        if string1[i] != string2[i]:
            return False
    return True


def index_of(string: str, e: str) -> int:
    """
    Returns the first index in which a 'character', i.e.: a string of size 1 appears in another string
    :param string: the string in which to search
    :param e: the 'character', i.e.: string of size 1, to search for
    :return: an index 'i' if 'string[i] == e' and there is no other index 'j < i' such
    that 'string[j] == e'; or -1 if 'e' does not appear in 'string'
    """
    assert len(e) == 1
    for i in range(len(string)):
        if string[i] == e:
            return i
    return -1


def last_index_of(string: str, e: str) -> int:
    """
    Returns the last index in which a 'character', i.e.: a string of size 1 appears in another string
    :param string: the string in which to search
    :param e: the 'character', i.e.: string of size 1, to search for
    :return: an index 'i' if 'string[i] == e' and there is no other index 'j > i' such
    that 'string[j] == e'; or -1 if 'e' does not appear in 'string'
    """
    assert len(e) == 1
    last_i: int = -1
    for i in range(len(string)):
        if string[i] == e:
            last_i = i
    return last_i


def to_lower_case(string: str) -> str:
    """
    Transform a string into it's lower case formate
    :param string: the string to transform
    :return: a variation of 'string' where all upper case characters are transformed into lower case
    """
    lower: str = ""
    for c in string:
        if 'A' <= c <= 'Z':
            c = chr(ord(c) + 32)  # alternative solution: c.lower()
        lower = lower + c
    return lower
    # alternative solution: return string.lower()


def to_upper_case(string: str) -> str:
    """
    Transform a string into it's upper case formate
    :param string: the string to transform
    :return: a variation of 'string' where all lower case characters are transformed into upper case
    """
    upper: str = ""
    for c in string:
        if 'a' <= c <= 'z':
            c = chr(ord(c) - 32)  # alternative solution: c.upper()
        upper += c
    return upper
    # alternative solution: return string.upper()


def substring(string: str, from_inclusive: int, to_exclusive: int) -> str:
    """
    Returns a slice of a string
    :param string: the string from which to get a slice
    :param from_inclusive: the initial index of the slice (inclusive)
    :param to_exclusive: the final index of the slice (exclusive)
    :return: a slice from 'string[from_inclusive]' to 'string[to_exclusive - 1]'
    """
    assert 0 <= from_inclusive <= len(string)
    assert from_inclusive <= to_exclusive <= len(string)
    slice_string: str = ""
    for i in range(from_inclusive, to_exclusive):
        slice_string += string[i]
    return slice_string
    # alternative solution: return string[from_inclusive:to_exclusive]


if __name__ == "__main__":
    test_values: [int] = [9, 2, 8, 42, 0, -1, 88]
    print(std_max(1, 2))
    print("The maximum of {0} is {1}".format(test_values, maximum(test_values)))
    print("{} is even? {}".format(41, is_even(41)))
    print("{} is even? {}".format(42, is_even(42)))
    print("{} is odd? {}".format(41, is_odd(41)))
    print("{} is odd? {}".format(42, is_odd(42)))
    print("Fibonacci of {1} is {0}".format(fibonacci(8), 8))
    print("The length of '{}' is {}".format("General Kenobi", length("General Kenobi")))
    print("to_upper_case of '{}' is '{}'".format("General Kenobi", to_upper_case("General Kenobi")))
    print("to_lower_case of '{}' is '{}'".format("General Kenobi", to_lower_case("General Kenobi")))
