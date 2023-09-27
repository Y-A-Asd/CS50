from csv import reader, DictReader
from sys import argv
sequences = {}
if len(argv) < 3:
    print("usage error, dna.py+sequence+database")
    exit(1)
with open(argv[2]) as dnaf:
    dnrd = reader(dnaf)
    for row in dnrd:
        dnls = row
dna = dnls[0]
with open(argv[1]) as pfile:
    people = reader(pfile)
    for row in people:
        podna = row
        podna.pop(0)
        break

for m in podna:
    sequences[m] = 1

for k in sequences:
    ln = len(k)
    maxt = 0
    tmp = 0
    for i in range(len(dna)):
        while tmp > 0:
            tmp -= 1
            continue
        if dna[i: i + ln] == k:
            while dna[i - ln: i] == dna[i: i + ln]:
                tmp += 1
                i += ln
            if tmp > maxt:
                maxt = tmp
    sequences[k] += maxt
with open(argv[1], newline='') as pfile:
    people = DictReader(pfile)
    for i in people:
        v = 0
        for dna in sequences:
            if sequences[dna] == int(i[dna]):
                v += 1
        if v == len(sequences):
            print(i['name'])
            exit(0)

    print("No Match")
# Yousof.A.Asadi(Y.A.A)11/28/2021