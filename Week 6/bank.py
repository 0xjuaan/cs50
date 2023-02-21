
greeting = input("Greeting: ")

if greeting.split()[0].lower() in ["hello", "hello,", "hello!"]:
     x = 0
elif greeting[0].lower() == "h":
     x = 20
else:
     x = 100

print("$" + str(x))