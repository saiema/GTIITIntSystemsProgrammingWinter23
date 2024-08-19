def index_of(values, value):
    i = 0
    for current_value in values:
        if current_value == value:
            return i
        i = i + 1
    return -1

if __name__ == "__main__":
    values = [0, 1, 2, 3, 4, 5, 6, 7]
    value = 3
    print("The index of {} in {} is {}".format(value, values, index_of(values, value)))