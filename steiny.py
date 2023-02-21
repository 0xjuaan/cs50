
greeting = input("Greeting: ")

if greeting.lower() == "hello":
     x = 100
elif greeting[0].lower() == "h":
     x = 20
else:
    x = 0

print("$" + str(x))