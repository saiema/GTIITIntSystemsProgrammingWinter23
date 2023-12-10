
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
    for key_value in dictionary:
        if key_value[0] == key:
            return True
    return False        

def get_value(dictionary: list[(str, int)], key: str) -> int | None:

def set_value(dictionary: list[(str, int)], key: str, value: int) -> int:
