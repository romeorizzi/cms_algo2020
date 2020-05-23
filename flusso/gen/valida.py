#!/usr/bin/env python2

from limiti import *

from sys import argv, exit, stderr
import os

def usage():
    print >> stderr, "Usage: %s file_input.txt" % \
        os.path.basename(argv[0])
    exit(1)

def run(f):
    assert(len(f) >= 1)
    prima = [int(x) for x in f[0].split()]
    assert(len(prima) == 2)
    N, M = prima
    assert(1 <= N <= MAXN)
    assert(2 <= M <= MAXM)
    assert(len(f) == M+2)
    seconda = [int(x) for x in f[1].split()]
    assert(len(seconda) == 2)
    a, b = seconda
    assert(1 <= a <= N)
    assert(1 <= b <= N)
    for i in xrange(M):
        riga = [int(x) for x in f[i+2].split()]
        assert(len(riga) == 3)
        a, b, val = riga
        assert(1 <= a <= N)
        assert(1 <= b <= N)
        assert(1 <= val < 2**31)
    return 0 # Input corretto

if __name__ == "__main__":
    if len(argv) < 2:
        usage()

    f = open(argv[1]).readlines()
    exit(run(f))


