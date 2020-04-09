#!/usr/bin/env pypy3

from limiti import *
from graph import *
from sys import argv, exit, stderr
import os
from random import random, randint, choice, sample, shuffle, seed

usage="""Generatore di "oddcycle".

Parametri:
* N (numero)
* S (seed)
* type (tasktype)

Constraint:
* 1 <= N <= %d
""" % (MAXN)



def run(N, type):
    if type == 2:
        g = ugraph(N,type='clique')
    if type == 3:
        g = ugraph(N/2,type='star')
        g.addedges(N/2)
    if type == 4:
        g = ugraph(N/3,type='cycle')+ugraph(N/3,type='cycle')
    if type == 5:
        g = ugraph(N,type='connected') | ugraph(2*(N/8)+3,type='cycle')
    print_nums(N)


if __name__ == "__main__":
    if len(argv) != 3:
        print usage
        exit(1)

    N, S, type = map(int, argv[1:])
    
    assert (1 <= N <= MAXN)
    seed(S)
    run(N, type)
