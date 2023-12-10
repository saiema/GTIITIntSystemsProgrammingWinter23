
def keys(dictionary: list[(str, int)]) -> list[str]:
    """
    Given a list of tuples mapping strings with integers
    return all the strings
    :param dictionary: the dictionary over a list of tuples
    :return: all the strings in the dictionary
    """
    pass

def values(dictionary: list[(str, int)]) -> list[int]:
    """
    Given a list of tuples mapping strings with integers
    return all the integers
    :param dictionary: the dictionary over a list of tuples
    :return: all the integers in the dictionary
    """
    pass

def key_exists(dictionary: list[(str, int)], key: str) -> bool:
    """
    Given a list of tuples mapping strings with integers, and a string
    return if there is a tuple with that string as key
    :param dictionary: the dictionary over a list of tuples
    :param key: the key to search for
    :return: `True` iff there is a tuple `(key, _)` in `dictionary`.
    """
    for key_value in dictionary:
        if key_value[0] == key:
            return True
    return False        

def get_value(dictionary: list[(str, int)], key: str) -> int | None:
    """
    Given a list of tuples mapping strings with integers, and a string
    return the value associated with that string, or `None` if there is no
    associated value
    :param dictionary: the dictionary over a list of tuples
    :param key: the key to search for
    :return: `value` if there is a tuple `(key, value)` in `dictionary`; `None` otherwise
    """
    pass

def set_value(dictionary: list[(str, int)], key: str, value: int) -> int | None:
    """
    Given a list of tuples mapping strings with integers, a string, and an integer
    updates the dictionary with the string and the integer, returning the old value if exists
    :param dictionary: the dictionary over a list of tuples
    :param key: the key of the tuple to add/update
    :param value: the value of the tuple to add/update
    :return: `old` if there was a tuple `(key, old)` in `dictionary`; `None` otherwise
    """
    pass
