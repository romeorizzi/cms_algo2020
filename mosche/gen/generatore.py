#!/usr/bin/env python2

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os
from numpy.random import random, randint, seed as nseed
from random import choice, sample, shuffle, seed as rseed
import string

usage="""Generatore di "mosche".

Parametri:
* R (numero righe della finestra)
* S (numero colonne della finestra)
* K (lato della racchetta)
* SEED (seed)
Oppure:
* NOMEFILE contenente l'istanza

Constraints:
* 3 <= R <= %d
* 3 <= S <= %d
* 3 <= K <= %d
""" % (MAXR, MAXS, MAXK)


def run(R,S,K):
    print R, S, K
    chars = '.*'
    for i in range(R):
        print ''.join(choice(chars) for j in range(S))

def copy(FILENAME):
    os.system("zcat " + FILENAME)

if __name__ == "__main__":
    if len(argv) == 5:
        R, S, K, SEED = map(int, argv[1:])
        # su seed non positivo copia un input di esempio dal .tex
        if SEED <= 0:
            print extract_input()[-SEED],
            exit(0)
        assert (3 <= R <= MAXR)
        assert (3 <= S <= MAXS)
        assert (3 <= K <= MAXK)
        nseed(SEED)
        rseed(SEED)
        run(R, S, K)
        exit(0)
    if len(argv) == 2:
        FILENAME = argv[1]
        copy(FILENAME)
        exit(0)

    print usage
    exit(1)


