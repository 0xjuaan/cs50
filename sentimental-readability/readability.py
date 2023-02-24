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

score = (100 * 0.0588 * (L / W) - 0.296 * (S / W) * 100 - 15.8)

if score > 16:
    print("Grade 16+")
elif score < 1:
    print("Before Grade 1")
else:
    print(f"Grade {int(score)}")