#!/usr/bin/env python

from limiti import *

usage="""Generatore per "Longwalk".

Parametri:
* T (1 se il grafo deve essere un DAG, 0 altrimenti)
* N (numero di nodi)
* M (numero di archi)
* S (seed)

Constraint:
* 2 <= N <= %d
""" % MAXN

from sys import argv, exit, stderr
import os
from numpy.random import random, randint, seed as nseed
from random import choice, sample, shuffle, seed as rseed

import graph

def run(N, M, T, S):
    nseed(S)
    rseed(S)
    if T==0:
        g=graph.dgraph(N)
    else:
        g=graph.dag(N)
    g.addedges(M)
    g.shuffle()
    print g

if __name__ == "__main__":
    if len(argv) != 5:
        print usage
        exit(1)

    N, M, T, S = [int(x) for x in argv[1:5]]
    assert (2 <= N <= MAXN)
    assert (2 <= M <= MAXM)
    assert (T==0 or T==1)
    run(N, M, T, S)
