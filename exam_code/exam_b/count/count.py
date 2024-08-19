def count(elements):
    assert elements is not None
    counter = 0
    for elem in elements:
        if elem.accept():
            counter = counter + 1
    return counter