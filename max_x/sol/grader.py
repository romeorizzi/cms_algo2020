# problem: max_x, Romeo Rizzi Jan 2015

import sys

nBalls = 0
goodBall = 0
nPesate = 0
maxLies = 0
maxPesate = 0
subtask = 0
rseed = 0
perm = None

RAND_MAX = 0x7fffffff


def rand_cp():
    global rseed
    rseed = (rseed * 1103515245 + 12345) & RAND_MAX
    return rseed


def generaPerm_random_uniform(perm, n):
    for i in range(n):
        perm[i] = i
    for i in reversed(range(1, n)):
        j = rand_cp() % i
        perm[i], perm[j] = perm[j], perm[i]


def pesa(bigliaA, bigliaB):
    global nPesate, perm, maxLies

    nPesate += 1
    invert = 1
    if (maxLies > 0) and (rand_cp() % nBalls - nPesate < maxLies):
        invert = -1
        maxLies -= 1

    if perm[bigliaA] > perm[bigliaB]:
        return invert
    if perm[bigliaA] < perm[bigliaB]:
        return -invert
    return 0


def pensoCheMaxSia(risp):
    global outfile
    print("%d %d %d" % (risp, nPesate, maxPesate), file=outfile)
    sys.exit(0)


def ottieni_valori():
    global outfile, nBalls, goodBall, nPesate, perm
    global maxLies, maxPesate, subtask, rseed

    infile = open("input.txt", "r")
    # infile = sys.stdin;

    (goodBall, nBalls, subtask, seed) = [int(x.strip()) for x in infile.read().split()]
    infile.close()

    perm = [0] * nBalls

    rseed = seed
    generaPerm_random_uniform(perm, nBalls - 1)  # genera permutazione di tutte eccetto la piu' pesante
    perm[nBalls - 1] = perm[goodBall]  # sposto in fondo quella che occupa la posizione predestinata
    perm[goodBall] = nBalls - 1  # colloco la piu' pesante al suo posto

    outfile = open("output.txt", "w")
    # outfile = sys.stdout;

    maxPesate = 10 * nBalls
    if subtask == 0:
        assert(goodBall == 2)
    elif subtask == 1:
        assert(nBalls == 2)
    elif subtask == 2:
        maxPesate = nBalls
    elif subtask == 3:
        maxPesate = nBalls - 1
    elif subtask == 4:
        maxLies = 1
    elif subtask == 5:
        maxLies = 1
        maxPesate = 3 * nBalls - 3
    elif subtask == 6:
        maxLies = 1
        maxPesate = 2 * nBalls
    elif subtask == 7:
        maxLies = 1
        maxPesate = 2 * nBalls - 1
    elif subtask == 8:
        maxLies = 2 + (rand_cp() % 7)
        maxPesate = (maxLies + 1) * (nBalls - 1) + maxLies

    return (nBalls, maxLies)
