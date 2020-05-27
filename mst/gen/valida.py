#!/usr/bin/env python3
from limiti import *

from sys import setrecursionlimit, argv, exit, stderr
import os
setrecursionlimit(10**8)

def usage():
    print("Usage: %s file_input.txt" % \
        os.path.basename(argv[0]), file=stderr)
    exit(1)

def dfs(currentNode, mappa_archi, visited):
    if (visited[currentNode] == True):
        return
    visited[currentNode] = True
    for k in mappa_archi[currentNode]:
        if (visited[k] == False):
            dfs(k, mappa_archi, visited)

def run(f):
    assert(len(f) >= 1)
    prima = [int(x) for x in f[0].split()]
    assert(len(prima) == 2)
    N, M = prima
    assert(1 <= N and N <= MAXN)
    assert(N - 1 <= M and M <= MAXM)
    mappa_archi = [{} for i in range(N)]

    for i in range(M):
        riga = [int(x) for x in f[i+1].split()]
        assert(len(riga) == 3)
        a, b, c = riga
        assert(0 <= a and a <= N-1)
        assert(0 <= b and b <= N-1)
        assert(1 <= c and c <= MAXP)
        mappa_archi[a][b] = True
        mappa_archi[b][a] = True
    for i in range(N):
        assert(len(mappa_archi[i]) > 0)
        if(len(mappa_archi[i]) == 1):
            assert(i not in mappa_archi[i])
    visited = [False] * N
    dfs(0,mappa_archi,visited)
    assert(visited.count(False) == 0)

    return 0 # Input corretto

if __name__ == "__main__":
    if len(argv) < 2:
        usage()

    f = open(argv[1]).readlines()
    exit(run(f))


