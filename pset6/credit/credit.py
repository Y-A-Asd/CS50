from cs50 import get_int
mas = [51, 52, 53, 54, 55]
y = 0
n = get_int("Number: ")
n1 = n
digg = n1
num = len(str(abs(n))) + 1
for i in range(0, num, 2):
    n = n1 // pow(10, i)
    y += int(n % 10)
n = n1
for j in range(1, num, 2):
    n = n1 // pow(10, j)
    if n % 10 * 2 > 9:
        y += int(n % 10 * 2 % 10) + 1
    else:
        y += int(n % 10 * 2)
if y % 10 == 0:
    if n1 // 10000000000000 == 37 or n1 // 10000000000000 == 34:  # AMEX
        print("AMEX")
    elif n1 // 100000000000000 == mas[0] or n1 // 100000000000000 == mas[1] or n1 // 100000000000000 == mas[2] or n1 // 100000000000000 == mas[3] or n1 // 100000000000000 == mas[4]:  # MASTERCARD
        print("MASTERCARD")
    elif n1 // 1000000000000000 == 4 or n1 // 1000000000000 == 4:  # VISA
        print("VISA")
    else:
        print("INVALID")
else:
    print("INVALID")
# Yousof.A.Asadi(Y.A.A)11/24/2021