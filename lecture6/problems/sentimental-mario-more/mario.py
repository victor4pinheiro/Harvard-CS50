"""Pyramid's print 
Print the pyramid according to heigh passed by user
"""

from cs50 import get_int


def main() -> None:
    """Ask height for the user and print using print_pyramid()"""
    while True:
        height = get_int('Height:')

        if height is None:
            continue
        elif height < 1 or height > 8:
            continue
        break

    print_pyramid(height)


def print_pyramid(height: int) -> None:
    """Print a pyramide with height passed by argument"""
    for i in range(1, height + 1):
        for j in reversed(range(1, height + 1)):
            if j <= i:
                print('#', end='')
            else:
                print(' ', end='')
        print('  ', end='')

        for j in range(i):
            print('#', end='')
        print()


if __name__ == '__main__':
    main()
