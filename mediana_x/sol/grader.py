# problem: ordina_x, Romeo Rizzi Mar 2015

import sys

nBalls = 0
nPesate = 0
maxPesate = 0
subtask = 0
rseed = 0
outfile = None

order = None

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


def bigliaIntermedia(bigliaA, bigliaB, bigliaC):
    global nPesate

    nPesate += 1

    if order[bigliaA] >= order[bigliaB]:
        if order[bigliaB] >= order[bigliaC]:
            return bigliaB
        if order[bigliaA] <= order[bigliaC]:
            return bigliaA
        return bigliaC
    else:
        if order[bigliaB] <= order[bigliaC]:
            return bigliaB
        if order[bigliaA] >= order[bigliaC]:
            return bigliaA
        return bigliaC


def consegnaBiglieInOrdine(biglia_in_pos):
    global nBalls, order, outfile, nPesate, maxPesate
    well_ordered = True
    for i in range(nBalls):
        if (order[biglia_in_pos[i]] != i) and (order[biglia_in_pos[i]] != nBalls - i - 1):
            well_ordered = False

    print("%d %d %d" % (well_ordered, nPesate, maxPesate), file=outfile)
    # only for debugging
    # for i in range(nBalls):
    #     print(file, "%ld ", order[i])
    # print(file, "\n")
    # for i in range(nBalls):
    #   print(file, "%ld ", biglia_in_pos[i])
    sys.exit(0)


def ottieni_num_balls():
    global nBalls, rseed, outfile, maxPesate, order

    infile = open("input.txt", "r")
    # infile = sys,stdin;

    (nBalls, subtask, seed) = [int(x.strip()) for x in infile.read().split()]
    infile.close()

    LOG_UP = 1
    guy = 2
    while guy < nBalls:
        LOG_UP += 1
        guy *= 2

    order = [0] * nBalls

    rseed = seed
    generaPerm_random_uniform(order, nBalls)  # genera permutazione

    outfile = open("output.txt", "w")
    # outfile = sys.stdout

    maxPesate = 1000 * nBalls * nBalls

    if subtask == 1:
        for i in range(nBalls):
            order[i] = i
    elif subtask == 2:
        for i in range(nBalls):
            order[i] = nBalls - i - 1
    elif subtask == 5:
        maxPesate = nBalls * (nBalls - 1) / 2
    elif subtask == 6:
        maxPesate = 3 * nBalls * LOG_UP
    elif subtask == 7:
        maxPesate = nBalls + nBalls * (LOG_UP)

    return nBalls
