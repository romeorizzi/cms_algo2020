#!/usr/bin/env python2

from limiti import *

usage="""Generatore per "Dijkstra".

Parametri:
* N (numero di nodi)
* L (load factor)
* S (seed)

Constraint:
* 1 <= N < %d
* 0 <= L <= 0.001
""" % MAXN

from sys import argv, exit, stderr
import os
from numpy.random import random, randint, seed as nseed
from random import choice, sample, shuffle, seed as rseed

def run(N, L, S):
    rseed(S)
    nseed(S)
    grafo = [[] for i in range(N)]

    def cerchizazione(load,nodi):
        grafo_nodi = [set() for i in nodi]
        size = len(nodi)

        for i in range(len(nodi)):
            grafo_nodi[i].add((i+1)%len(nodi))

        nuovi = int(load* (len(nodi)*len(nodi)-2*len(nodi)) )

        while size != nuovi+len(nodi):
            a = randint(0,len(nodi))
            b = randint(0,len(nodi))
            while a == b or b in grafo_nodi[a]:
                a = randint(0,len(nodi))
                b = randint(0,len(nodi))
            grafo_nodi[a].add(b)
            size += 1

        for nodo in range(len(grafo_nodi)):
            for vicino in grafo_nodi[nodo]:
                grafo[nodi[nodo][0]].append(nodi[vicino][1])



    #cerchizazione(0.5,[[i,i] for i in range(N)])

    nodi = [[i,i] for i in range(N)]

    shuffle(nodi)

    while len(nodi) != 1:
        x = randint(2,len(nodi)+1)

        if randint(0,2):
            nuovo_nodo = [nodi[len(nodi)-x][0],nodi[len(nodi)-1][1]]
        else:
            nuovo_nodo = nodi[len(nodi)-1]
        sub_nodo = []
        #print nodi
        for i in range(x):
            sub_nodo.append(nodi.pop())

        #print x
        #print sub_nodo
        #print nuovo_nodo

        cerchizazione(L,sub_nodo)

        nodi.insert(0,nuovo_nodo)

    # filtro per archi doppi
    out_grafo = [[] for i in range(N)]
    for nodo in range(len(grafo)):
        for arco in grafo[nodo]:
            if nodo in grafo[arco] and nodo > arco:
                continue
            out_grafo[nodo].append(arco)

    M = 0
    for x in out_grafo:
        M += len(x)

    print "%d %d" % (N, M)

    start = randint (1, N+1);
    end = randint (1, N+1);
    while start == end:
        end = randint (1, N+1);

    print "%d %d" % (start, end)

    for nodo in range(len(out_grafo)):
        for arco in out_grafo[nodo]:
            print "%d %d %d" % (nodo+1, arco+1, randint (1, 1001))


if __name__ == "__main__":
    if len(argv) != 4:
        print usage
        exit(1)

    N, L, S = [int(x) for x in argv[1:]]
    assert (2 <= N and N <= MAXN)
    L /= 100000.0
    run(N, L, S)

