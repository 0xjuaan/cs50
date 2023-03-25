def diff(x,y):
    return y-x


for i in range(100):
    if i%2==0 & i!=2:
        continue
    elif i%3==0 & i!=3:
        continue
    elif i%5==0 & i!=5:
        continue
    elif i%7==0 & i!=7:
        continue
    print(i)