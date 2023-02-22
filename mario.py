
def main():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0:
                break
        except ValueError:
            print("Not an integer")

    for i in range(n):
        print(" " * (n-(i+1))  +  "#" * (i+1)  +  " "  +  "#" * (i+1))


main()