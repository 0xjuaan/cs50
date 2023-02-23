from cs50 import get_int

def main():
    number = get_int("Number: ")


    # Getting the length of the number
    spare = number
    len_number = 0
    while (spare > 1):
        spare = spare/10
        len_number += 1

    print(first(number))



def first(number):
    while(number > 10):
        number = (number - number % 10) / 10
    return int(number)

def first2(number):
    while(number > 10):
        number = (number - number % 10) / 10
    return int(number)


main()