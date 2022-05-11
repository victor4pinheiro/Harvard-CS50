from cs50 import get_string


def main() -> None:
    """Get the input to calculate the grade required for text and print this grade"""
    while True:
        text = get_string("Text: ")

        if not text:
            continue
        break

    letters = 0
    words = 1  # Always exist one word in a sentence. Letters and sentences will be checked
    sentences = 0
    dots = [".", "!", "?"]

    for char in text:
        if char.isspace():
            words += 1

        if char in dots:
            sentences += 1

        if char.isalpha():
            letters += 1

    L = get_letters_per_words(letters, words)
    S = get_senteces_per_words(sentences, words)
    index = get_index_coleman_liau(L, S)
    print(check_grade(index))


def get_letters_per_words(letters: int, words: int) -> float:
    """Return the average of letter per 100 words"""
    return (letters / words) * 100


def get_senteces_per_words(sentences: int, words: int) -> float:
    """Return the average of sentences per 100 words"""
    return (sentences / words) * 100


def get_index_coleman_liau(L: float, S: float) -> int:
    """Return the integer value of index in Coleman-Liau formula"""
    return round(0.0588 * L - 0.296 * S - 15.8)


def check_grade(index: float) -> str:
    """Return the grade of the text passed by user"""
    if index >= 16:
        return "Grade 16+"
    elif index < 1:
        return "Before Grade 1"
    else:
        return f"Grade {index}"


if __name__ == "__main__":
    main()
