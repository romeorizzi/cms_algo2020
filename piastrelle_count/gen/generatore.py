#!/usr/bin/env python2

from limiti import *
from varie import *
from sys import argv, exit, stderr
import os

usage="""Generatore di "prova".

Parametri:
* N (numero)

Constraint:
* -%d <= N <= %d
""" % (MAXN,MAXN)


if __name__ == "__main__":
    if len(argv) != 2:
        print usage
        exit(1)

    N = int(argv[1])
    assert (-MAXN <= N <= MAXN)
    print N

