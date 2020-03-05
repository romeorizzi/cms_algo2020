#!/usr/bin/env python2

import random
import sys

N, min_val, max_val, seed = map(int, sys.argv[1:])

random.seed(seed)

print N
for i in range(N):
    print " ".join([str(random.randint(min_val, max_val)) for j in range(N)])
