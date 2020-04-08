#!/usr/bin/env python3

infile = open("input.txt", "r")
outfile = open("output.txt", "w")

N = int(infile.readline().strip())

h = [0] + [int(x.strip()) for x in infile.readline().split()]  # altezze delle tessere (1-based)

for i in range(1, N+1):
    print("%d" % (i), file=outfile, end=' ')  # giusto quando tutte le tessere sono alte 1.
print("", file=outfile)
