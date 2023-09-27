from cs50 import get_int
# test number to make while
n = 1000
while 1 > n or 8 < n:
    n = get_int("Height:")
for i in range(n):
    for m in range(n-(i+1)):
        print(" ", end="")
    for t in range(i+1):
        print("#", end="")
    print("  ", end="")
    for q in range(i+1):
        print("#", end="")
    print()

# Yousof.A.Asadi(Y.A.A)11/24/2021