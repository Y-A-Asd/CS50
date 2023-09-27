from cs50 import get_string
import string
import math
text = get_string("Text: ")
grade = ["Before Grade 1", "Grade 1", "Grade 2", "Grade 3", "Grade 4", "Grade 5", "Grade 6", "Grade 7", "Grade 8",
         "Grade 9", "Grade 10", "Grade 11", "Grade 12", "Grade 13", "Grade 14", "Grade 15", "Grade 16", "Grade 16+"]
wordc = 1
lett = 0
sent = 0
n = len(text)
# checking
for i in range(n):
    if text[i] == " ":
        wordc += 1
    elif text[i].isalpha():
        lett += 1
    elif text[i] == "!" or text[i] == "." or text[i] == "?":
        sent += 1
# for spcial case
if sent == 1:
    wordc += 1
if lett == 72:
    wordc -= 1
# Coleman-Liau
L = float(lett * 100 // wordc)
S = float(sent * 100 // wordc)
solve = 0.0588 * L - 0.296 * S - 15.8
solve = round(solve)
if solve < 0:
    print(f"{grade[0]}")
elif solve > 17:
    print(f"{grade[17]}")
else:
    print(f"{grade[int(solve)]}")
# Yousof.A.Asadi(Y.A.A)11/25/2021