from cs50 import get_string

text = get_string("Text: ")

L = 0
W = 0
S = 0

for i in text:
    if i == " ":
        W += 1
    elif i in ["!", ".", "?"]:
        S += 1
    elif i.isalpha():
        L +=1

score = int((0.0588 * L - 0.296 * S - 15.8) / W)

print(f"Grade {score}")