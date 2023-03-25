def main():
    goldy(20, 0)
    print(c)


def diff(x,y):
    return y-x

def fprimes(n):
    p=[]
    for i in range(n):
        if i == 1:
            continue
        if i%2==0 and i != 2:
            continue
        elif i%3==0 and i != 3:
            continue
        elif i%5==0 and i != 5:
            continue
        elif i%7==0 and i != 7:
            continue
        p.append(i)

    return p

def goldy(n, c):
    print(n)
    if n < 3:
        return

    primes = fprimes(n)
    diffs = []
    for i in range(n):
        if i in primes:
            for j in primes:
                if (len(primes)-j)-i == n:
                    print(f"{i}, {j}")
                    diffs.append((n-j)-i)

    print(diffs)
    c += 1
    goldy(max(diffs), c)


main()