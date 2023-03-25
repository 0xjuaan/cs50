
def get_primelist(upper):
	result = []
	for cp in range ( 2, upper + 1 ):
		for i in range ( 2, cp ):
			if ( cp % i == 0 ):
				break
		else:
			result.append(cp)
	return result
def findFactors(primes):
    global count
    for i in primes:
        for j in range(1,len(primes)+1):
            # print("Trying:", i,"+", primes[-j],"=", i+primes[-j]  )
            if i + primes[-j] == int(num):
                # FOUND
                count += 1
                return abs(primes[-j]-i)

count = 0     
num = input()
primes = get_primelist(int(num))
while int(num) > 3:
    num = findFactors(primes)
print(count)

