#!/usr/bin/env pypy

from limiti import *
from varie import *
from graph import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "css".

Parametri:
* N (nodi)
* M (archi)
* S (seed)

Constraint:
* 1 <= N <= %d
* 1 <= M <= %d
""" % (MAXN, MAXM)


def run(N, M):
    g = dgraph(N)
    g.addedges(M)
    print N, M
    print g.printedges(True)

if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, M, S = map(int, argv[1:])
    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input(True)[-S],
        exit(0)

    assert (1 <= N <= MAXN)
    assert (1 <= M <= MAXM)
    seed(S)
    run(N, M)
