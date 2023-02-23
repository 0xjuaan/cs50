from cs50 import get_int

def main():
    number = get_int("Number: ")



def first(number):
    while(number > 10):
        number = (number - number % 10) / 10

