#!/usr/bin/env python2


from limiti import *
from varie import *
from sys import argv, exit, stderr
from numpy.random import random, randint, seed as nseed
from random import choice, sample, shuffle, seed as rseed
import os

usage="""Generatore di "prova".

Parametri:
* N (numero)
* S (seed)
* R (result: 1 -> isomorph, 0 -> not isomorph, 2 -> completely random???to avoid determinism )
* BM (branching max)
* Bm (branching min)
* D (inverse depth probability [anyway (2, 5)]


Constraint:
* 1 <= N <= %d
""" % (MAXN)


def dfs(node, N, BM, Bm, D, albero):
    Nbranch = randint(max(1,Bm), BM) #il massimo e' perche' il troncamento di un ramo lo scelgo a random alla fine
    son = node
    while(Nbranch > 0):
        son = randint(0, N)
        if(albero[son]): #se e' gia' stato preso
            for i in range(son, N):
                if(not albero[i]):
                    son=i
                    break
        if(albero[son]): #cerco indietro (se avanti non ho posizioni libere)
            for i in range(son, -1, -1):
                if(not albero[i]):
                    son=i
                    break
        
        if(albero[son]): #in questo caso ho ormai usato tutti i nodi che potevo
            return 0

        #altrimenti non ho ancora assegnato
        albero[son]=True
        print node, son 
        Nbranch=Nbranch-1
    

    dfs(son, N, BM, Bm, D, albero)



#qua dovrei richiamare corsivamente
        

def run(N, R, BM, Bm, D):
    print N
    root = (randint(0, N))

    albero = [False for i in range(0, N)]
    albero[root]=True
    dfs(root, N, BM, Bm, D, albero)

    print root




if __name__ == "__main__":
    if len(argv) != 7:
        print usage
        exit(1)

    N, S, R, BM, Bm, D= map(int, argv[1:])
    assert (-MAXN <= N <= MAXN)

    # su seed non positivo copia un input di esempio dal .tex
    if S <= 0:
        print extract_input()[-S],
        exit(0)

#sono misure di prova
    if D<2:
        D=2
    if D>5:
        D=5

    run(N, R, BM, Bm, D)


