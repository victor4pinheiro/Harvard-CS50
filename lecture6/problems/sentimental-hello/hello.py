def main() -> None:
    """Print the name passed by the user only if it contains no digits"""
    while True:
        try:
            name = input('What is your name?\n')

            if check_string is True:
                raise AttributeError('Numerical values prohibited')
            break
        except AttributeError as e:
            print('Exception:', str(e))
    print('hello', name)


def check_string(string: str) -> bool:
    """Return true if string containys any digit.
    
    Keywords arguments:
    string -- string to be checked
    """
    return any(string.isdigit() for char in string)


if __name__ == '__main__':
    main()
