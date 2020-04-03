#!/usr/bin/python3
# Una soluzione di for1_file
# Andrea Cracco/Alessandro Righi, last update: Romeo Rizzi 2020-03-24

with open("input.txt","r") as infile:
 N = int(infile.readline())
st=""
for n in range(1,N+1):
 st += str(n) + " "
with open("output.txt", "w") as outfile:
 outfile.write(st+"\n")
