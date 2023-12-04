class _Node:

    def __init__(self, value=None, next_node=None):
        self.__value = value
        self.__next_node = next_node

    def set_value(self, value):
        self.__value = value

    def get_value(self):
        return self.__value

    def set_next(self, node):
        self.__next_node = node

    def get_next(self):
        return self.__next_node


class LinkedList:

    def __init__(self):
        self.__head = None
        self.__size: int = 0

    def append(self, value):
        if self.__size == 0:
            self.__head = _Node(value)
        else:
            current: _Node = self.__head
            while current.get_next() is not None:
                current = current.get_next()
            current.set_next(_Node(value))
        self.__size += 1

    def to_string(self) -> str:
        rep: str = "["
        current: _Node = self.__head
        while current is not None:
            rep += str(current.get_value())
            if current.get_next() is not None:
                rep += ", "
            current = current.get_next()
        rep += "]"
        return rep

