#!/usr/bin/python3

# confronto_con(val)
# answer(risp)

from grader import ottieni_n, confronto_con, answer

infile = open('input.txt', 'r')
outfile = open('output.txt', 'w')

args = [int(x.strip()) for x in infile.read().split(' ')]
print("1 " + str(args[0]), file = outfile)
