def main() -> None:
    """Input for user"""
    while True:
        try:
            text = input("Number (only numeric value): ")

            if text is None:
                raise AttributeError("Null values")

            if text.isdigit() is False:
                raise AttributeError("Not only numeric letters")
            break
        except AttributeError as e:
            print(str(e))

    long_card = to_array(text)
    product = luhn_algorithm(long_card)
    length_credit = len(long_card)

    if product % 10 == 0:
        if is_amex(long_card, length_credit):
            print("AMEX")
        elif is_mastercard(long_card, length_credit):
            print("MASTERCARD")
        elif is_visa(long_card, length_credit):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


def is_amex(card: list[int], length: int) -> bool:
    """Check if the card is America Express"""
    if length != 15:
        return False

    last_numbers = get_first_numbers(card, 2)

    if last_numbers not in [34, 37]:
        return False

    return True


def is_mastercard(card: list[int], length: int) -> bool:
    """Check if the card is Mastercard"""
    if length != 16:
        return False

    last_numbers = get_first_numbers(card, 2)

    if last_numbers not in [51, 52, 53, 54, 55]:
        return False

    return True


def is_visa(card: list[int], length: int) -> bool:
    """Check if the card is Visa"""
    if length not in [13, 16]:
        return False

    last_numbers = get_first_numbers(card, 1)

    if last_numbers != 4:
        return False

    return True


def get_first_numbers(card: list[int], amount_numbers: int) -> int:
    """Return the first N (know as amount_numbers) numbers of card"""
    last_numbers = ''.join(map(str, reversed(card[-amount_numbers:])))

    return int(last_numbers)


def valid_length_card(length: int, length_card: int) -> bool:
    """Check if the length is valid according to length_card"""
    if length == length_card:
        return True
    else:
        return False


def luhn_algorithm(credit_card_number: list[int]) -> int:
    """Return the product after following the the algorithm of Hans Luhn"""
    product = 0
    for index, number in enumerate(credit_card_number):
        if index % 2 == 1:
            new_number = number * 2

            if new_number >= 10:
                product += new_number % 10 + int(new_number / 10)
            else:
                product += new_number
        else:
            product += number
    return product


def to_array(string: str) -> list[int]:
    """Convert a string to an array of integers and return it"""
    return list(map(int, reversed(string.strip())))


if __name__ == '__main__':
    main()
