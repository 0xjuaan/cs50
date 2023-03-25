p=[]

for i in range(20):
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

print(p)

print(p)