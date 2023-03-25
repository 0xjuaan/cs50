c = 0
def main():


    global c
    goldy(int(input()))
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

def goldy(n):
    global c

    if n < 3:
        return

    primes = fprimes(n)
    diffs = []
    c+=1
    fin = False
    for i in primes:
        if fin:
            break
        for j in range(len(primes)):
            if i + primes[len(primes)-1-j] == n:
                diffs.append(diff(i, primes[len(primes)-1-j]))
                fin = True
                break







    goldy(max(diffs))


main()