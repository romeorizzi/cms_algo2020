#!/usr/bin/env python3

infile = open("input.txt", "r")
outfile = open("output.txt", "w")

N = int(infile.readline().strip())

h = [0] + [int(x.strip()) for x in infile.readline().split()]  # altezze delle tessere
count = [0] * (N+1)  # count[i] = numero di isole con i tessere

i = 1
nIsola = 1

while i <= N:
    len = 1  # lunghezza dell'isola corrente
    goes_to_at_least = i + h[i] - 1  # lower-bound su estremo destro dell'isola corrente
    while (i < N) and (i < goes_to_at_least):
        i += 1
        len += 1
        goes_to_at_least = max(goes_to_at_least, i + h[i] - 1)
        # print("i = %d, nIsola = %d, len = %d\n" % (i, nIsola, len))

    assert((i == N) or (i == goes_to_at_least))
    count[len] += 1
    i += 1
    nIsola += 1

killed = 0
for len in reversed(range(1, N+1)):
    while count[len] != 0:
        count[len] -= 1
        killed += len
        print("%d" % (killed), file=outfile, end=' ')

while nIsola <= N:
    nIsola += 1
    print("%d" % (killed), file=outfile, end=' ')
print("", file=outfile)
