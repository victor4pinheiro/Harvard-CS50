import csv
import sys


def main():
    if len(sys.argv) != 3:
        # Code say to use print but it's non-sense. I can't let execute if params total is wrong.
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Get database
    database = []
    try:
        with open(sys.argv[1], 'r') as file:
            csv_file = csv.DictReader(file)
            for row in csv_file:
                database.append(row)
    except FileNotFoundError as e:
        print(str(e))

    number_columns = get_total_number_columns(database[0])

    # Get sequence of DNA
    sequence = ''
    try:
        with open(sys.argv[2], 'r') as file:
            sequence = file.readline()
    except FileNotFoundError as e:
        print(str(e))

    total_matches = find_all_longest_match(database, sequence)
    identified_person = get_name(database, total_matches, number_columns)

    if identified_person is None:
        print("No match")
    else:
        print(identified_person)

    return


def get_total_number_columns(database: list[str]) -> int:
    """Get total number of columns of CSV file"""
    return len(database)


def find_all_longest_match(database: list[str], sequence: str) -> list[int]:
    """Return all longest match of each STR in DNA sequence"""
    matches = []
    header = database[0].keys()

    for subsequence in header:
        if subsequence != "name":
            matches.append(longest_match(sequence, subsequence))

    return matches


def get_name(database: list[str], total_matches: list[int], number_columns: int) -> str | None:
    """Check database for matching profiles and return if the name if it exist. If not, return None"""
    for person in database:
        count = 0
        for key, alleles in person.items():
            if key != "name":
                if int(alleles) in total_matches:
                    count += 1

        if count == number_columns - 1:
            return person.get("name")

    return None


def longest_match(sequence: str, subsequence: str) -> int:
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
