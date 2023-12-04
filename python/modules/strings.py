def is_substring(haystack: str, needle: str) -> bool:
    """
    Search if a string is a substring of another
    :param haystack: the string in where to search
    :param needle: the substring to search
    :return: True iff 'needle' is a substring of 'haystack'
    """
    pass


def is_subsequence(haystack: str, needle: str) -> bool:
    """
    Search if a string is a subsequence of another
    :param haystack: the string in where to search
    :param needle: the subsequence to search
    :return: True iff 'needle' is a subsequence of 'haystack'
    """
    pass


def generate_all_substrings(string: str) -> list[str]:
    """
    Generates all substrings of a given string
    :param string: the given string
    :return: a list of all substrings of 'string'
    """
    pass


def generate_all_subsequences(string: str) -> list[str]:
    """
    Generates all subsequences of a given string
    :param string: the given string
    :return: a list of all subsequences of 'string'
    """
    pass


def to_upper_case(string: str) -> str:
    """
    Returns an upper case version of a string
    :param string: the original string
    :return: an upper case version of 'string'
    """
    upper: str = ""
    for c in string:
        if 'a' <= c <= 'z':
            upper += chr(ord(c) - 32)
        else:
            upper += c
    return upper


def to_lower_case(string: str) -> str:
    """
    Returns a lower case version of a string
    :param string: the original string
    :return: a lower case version of 'string'
    """
    lower: str = ""
    for c in string:
        if 'A' <= c <= 'Z':
            lower += chr(ord(c) + 32)
        else:
            lower += c
    return lower


def reverse(string: str) -> str:
    """
    Reverses a string
    :param string: the string to reverse
    :return: a reversed version of 'string'
    """
    rev: str = ""
    for c in string:
        rev = c + rev
    return rev

