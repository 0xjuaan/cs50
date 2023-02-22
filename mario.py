
def main():
    while True:
        n = int(input("Height: "))
        if n > 0:
            break

    for i in range(n):
        print(" " * (n-(i+1))  +  "#" * (i+1)  +  " "  +  "#" * (i+1))


main()