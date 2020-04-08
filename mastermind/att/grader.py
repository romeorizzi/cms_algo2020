#!/usr/bin/env python3
import sys

maxAttempts = None
guesses = 0
outfile = None
rseed = 0

secretCode = [0] * 4  # Codice da scoprire

RAND_MAX = 0x7fffffff


def checkCode(attempt, result):
    global guesses, secretCode

    black = 0
    white = 0

    fr_att = [0] * 6
    fr_hist = [0] * 6

    for i in range(4):
        if attempt[i] == secretCode[i]:
            black += 1
        else:
            assert(0 <= attempt[i] <= 5)
            assert(0 <= secretCode[i] <= 5)
            fr_att[attempt[i]] += 1
            fr_hist[secretCode[i]] += 1

    for i in range(6):
        white += min(fr_att[i], fr_hist[i])

    result[0] = black
    result[1] = white

    if result[0] != 4:
        guesses += 1


def pensoCheCodiceSia(risposta):
    global outfile, maxAttempts

    print("%d %d" % (maxAttempts, guesses), file=outfile)

    for j in range(4):
        print("%d" % risposta[j], end=' ', file=outfile)

    print(file=outfile)
    outfile.close()

    sys.exit(0)


def inizializza():
    global outfile, maxAttempts, rseed

    # infile = open("input.txt", "r")
    file = sys.stdin;

    subtask, seed = [int(x.strip()) for x in infile.read().split()]
    infile.close()

    # outfile = open("output.txt", "w")
    file = sys.stdout;

    if subtask == 0:
        maxAttempts = 1000000
    if subtask == 1:
        maxAttempts = 10
    if subtask == 2:
        maxAttempts = 6  # soluzione ottima (6 errate)

    rseed = seed

    def rand_cp():
        global rseed
        rseed = (rseed * 1103515245 + 12345) & RAND_MAX
        return rseed

    for i in range(4):
        secretCode[i] = rand_cp() % 6
