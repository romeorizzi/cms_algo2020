#!/usr/bin/env python2

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


# 0            -> corretto
# altro numero -> non corretto
def run(f, st):
    R, S, K = map(int, f[0].split())
    if R > MAXR:
        return -2
    if S > MAXS:
        return -3
    if K > MAXK:
        return -4
    if R < 3:
        return -5
    if S < 3:
        return -6
    if K < 3:
        return -7
    if K > R:
        return -8
    if K > S:
        return -9
    if S != len(f[1].strip()):
        return -10
    if S != len(f[2].strip()):
        return -11
    return 0


if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    exit(run(f, st))
