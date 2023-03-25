def main():
    goldy(20, 0)
    print(c)


def diff(x,y):
    if y>x:
        return y-x
    if x>=y:
        return x-y


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

    if n < 3:
        return

    primes = fprimes(n)
    diffs = []
    for i in primes:
        for j in primes:
            if i + (len(primes)-j) == n:
                diffs.append(diff(i,j))
                break



    print(diffs)
    c += 1
    goldy(max(diffs), c)


main()