#!/usr/bin/env python3
# Generator for clone_det

import argparse
import random

MAXN = 30_000_000

parser = argparse.ArgumentParser()
parser.add_argument('seed', type=int, help='Seed for the random generator')
parser.add_argument('N', type=int, help='Number of elements')
parser.add_argument('E', type=int, help='Maximum element value', nargs='?', default=2**63)

args = parser.parse_args()
random.seed(args.seed)

assert 1 <= args.N <= MAXN

A = [0]
B = [0]
for i in range(args.N - 1):
    A.append(random.randint(0, args.E))
    B.append(random.randint(0, args.E))

x = random.randint(0, args.N)
A[x] = B[x]

assert len(A) == args.N
assert len(B) == args.N

print(args.N)

for a in sorted(A):
    print(a, end=' ')
print()

for b in sorted(B):
    print(b, end=' ')
print()