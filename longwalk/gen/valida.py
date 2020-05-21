#!/usr/bin/env python

from limiti import *

from sys import argv, exit, stderr
import os

def usage():
    print("Usage: %s file_input.txt" % os.path.basename(argv[0]), file=stderr)
    exit(1)

def run(f):
    assert(len(f) > 1)
    prima = [int(x) for x in f[0].split()]
    assert(len(prima) == 2)
    N, M = prima
    assert(2 <= N <= MAXN)
    assert(2 <= M <= MAXM)
    assert(len(f) == M+1)

    for i in range(1, M+1):
        token = [int(x) for x in f[i].split()]
        assert(len(token) == 2)
        u, v = token
        assert(1 <= u <= N)
        assert(1 <= v <= N)
        assert(u != v)

    return 0 # Input corretto

if __name__ == "__main__":
    if len(argv) < 2:
        usage()

    f = open(argv[1]).readlines()
    exit(run(f))
