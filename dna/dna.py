import csv
import sys


def main():

    # Ensuring correct usage with Command Line Arguments
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    # Open database as dict
    with open(sys.argv[1], "r") as database:
        # Copy the first line into a list
        strings = list(next(csv.reader(database)))
        strings.pop(0)
    #Again open database, this time to transfer into people (list of dicts)
    with open(sys.argv[1], "r") as database:
        data_reader = csv.DictReader(database)
        # Transfer each person(dict) into a list of people
        people = []
        for person in data_reader:
            people.append(person)

    # Read DNA sequence file into a variable
    sequence_file = open(sys.argv[2], "r")
    sequence = sequence_file.read()

    #Find longest match of each STR in DNA sequence
    matches = {}
    for string in strings:
        matches[string] = longest_match(sequence, string)

    #Check database for matching profiles
    for idx in range(len(people)): # Iterate across all people
        for string in strings: #Iterate across all strings of this person, and check it with 'sequence'

            if matches[string] == int(people[idx][string]) and string == strings[len(strings)-1]:
                print(people[idx]["name"])
                exit(0)

            elif matches[string] == int(people[idx][string]):
                continue

            else:
                break

    print("No match")
    return


def longest_match(sequence, subsequence):
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
