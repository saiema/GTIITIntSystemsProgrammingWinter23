def function_in_b():
    print("Hello, I'm B!\n")

if __name__ == "__main__":
    import a
    a.function_in_a()
    function_in_b()