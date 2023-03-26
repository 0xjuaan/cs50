primes = []
status = False

for i in range(1, 20):
    for j in range(1, round(int(i)/2)):
        if (i % j == 0 and i != j) == 0:
            status = False
            
        else:
            status = True
    if status == True:
        primes.append(i)


print(primes)



# for i in range(1, int(num)):
#     for j in range(1, round(int(num)/2)):
#         if i % j == 0:
#             status = False
#         else:
#             status = True
#     if status == True:
#         primes.append(i)

# print(primes)