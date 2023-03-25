y,x=input().split()
y,x=int(y),int(x)

inp = []
for i in range(y):
    inp.append(input().split())

for iy in range(y):
    for ix in range(x):
        if iy == 0 or ix == 0 or iy == y-1 or ix == x-1:
            print(0, end="")
        else:
            val = inp[iy][ix]
            around = [inp[iy][ix-1],inp[iy][ix+1],inp[iy-1][ix],inp[iy+1][ix]]
            if min(around + [val]) == val and val not in around:
                print(1, end="")
            else:
                print(0, end="")
        if ix != x-1:
            print(" ", end="")
    print()
            