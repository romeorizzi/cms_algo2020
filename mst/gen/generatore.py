#!/usr/bin/env python3
from limiti import *

usage="""Generatore per "Dijkstra".

Parametri:
* N (numero di nodi)
* M (numero di archi) [0 per numero casuale]
* L (load factor)
* se C = 0 il peso degli archi varia, se C = 1 il peso degli archi è Costante, se C = 2 il peso è 2 o 3
* S (seed)

Constraint:
* 1 <= N < %d
* M < %d
* 0 <= C <= %d
* 0 <= L <= 0.001
""" % (MAXN, MAXM, MAXC)

from sys import setrecursionlimit, argv, exit, stderr
import os
from random import seed, choice, sample, shuffle, random, randrange
import queue
setrecursionlimit(10**8)

def run(N, realM, L, C, S):
    seed(S)
    grafo = [[] for i in range(N)]

    def cerchizazione(load,nodi):
        grafo_nodi = [set() for i in nodi]
        size = len(nodi)

        for i in range(len(nodi)):
            grafo_nodi[i].add((i+1)%len(nodi))

        nuovi = int(load* (len(nodi)*len(nodi)-2*len(nodi)) )

        while size != nuovi+len(nodi):
            a = randrange(len(nodi))
            b = randrange(len(nodi))
            while a == b or b in grafo_nodi[a]:
                a = randrange(0,len(nodi))
                b = randrange(0,len(nodi))
            grafo_nodi[a].add(b)
            size += 1

        for nodo in range(len(grafo_nodi)):
            for vicino in grafo_nodi[nodo]:
                grafo[nodi[nodo][0]].append(nodi[vicino][1])



    #cerchizazione(0.5,[[i,i] for i in range(N)])

    nodi = [[i,i] for i in range(N)]

    shuffle(nodi)

    while len(nodi) != 1:
        x = randrange(2,len(nodi)+1,1)

        if randrange(2):
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
    out_grafo = [{} for i in range(N)]
    for nodo in range(len(grafo)):
        for arco in grafo[nodo]:
            if nodo in grafo[arco] and nodo > arco:
                continue
            out_grafo[nodo][arco] = True

    mappa_archi = [{} for i in range(N)]
    M = 0
    for x in range(len(out_grafo)):
        M += len(out_grafo[x])
        if (realM != 0):
            for arco in out_grafo[x]:
                mappa_archi[arco][x] = True
                mappa_archi[x][arco] = True

    #M specificato
    if (realM != 0):
        #se ci sono troppi archi, elimino archi superflui fino a raggiungere M giusto.
        if(M > realM):
            q = queue.Queue()
            q.put(0)
            visited = [False] * N
            visited[0] = True
            visitedN = 0
            minArcs = [{} for i in range(N)]
            while(not q.empty()):
                popped = q.get()
                visitedN += 1
                if(visitedN == N):
                    break
                for u1 in mappa_archi[popped]:
                    if(not visited[u1]):
                        q.put(u1)
                        visited[u1] = True
                        minArcs[popped][u1] = True
                        minArcs[u1][popped] = True
            M = N - 1
            for u1 in range(N):
                for u2 in list(mappa_archi[u1]):
                    if (u2 not in minArcs[u1]):
                        mappa_archi[u2].pop(u1, None)
                        mappa_archi[u1].pop(u2, None)
                        if(M < realM):
                            M += 1
                        else:
                            out_grafo[u2].pop(u1, None)
                            out_grafo[u1].pop(u2, None)

        #Se ce ne erano troppi pochi, aggiungo altri archi.
        if(M < realM):
            for u1 in range(N):
                if (M >= realM):
                    break
                for u2 in range(u1 + 1, N):
                    if (u1 not in mappa_archi[u2]):
                        mappa_archi[u1][u2] = True
                        mappa_archi[u2][u1] = True
                        out_grafo[u2][u1] = True
                        M += 1
                        if (M >= realM):
                            break





    #Stampe finali
    print("%d %d" % (N, M))

    for nodo in range(len(out_grafo)):
        for arco in out_grafo[nodo]:
            if C == 0: #pesi random
                print("%d %d %d" % (nodo, arco, randrange(1, MAXP + 1, 1)))
            if C == 1: #pesi costanti
                print("%d %d %d" % (nodo, arco, 100))
            if C == 2: #peso 2 o 3
                print("%d %d %d" % (nodo, arco, randrange(2, 4, 1)))


if __name__ == "__main__":
    if len(argv) != 6:
        print(usage)
        exit(1)

    N, realM, L, C, S = [int(x) for x in argv[1:]]
    assert (2 <= N and N <= MAXN)
    assert (realM == 0 or (realM >= N - 1 and realM <= MAXM))
    assert (0 <= C and C <= MAXC)
    L /= 100000.0
    run(N, realM, L, C, S)
