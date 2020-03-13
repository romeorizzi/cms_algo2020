#!/usr/bin/env python3

import argparse
import random

MAXN = 1_000_000

parser = argparse.ArgumentParser()
parser.add_argument('mode', type=int, help='0 = no repetitions, 1 = repetitions, 2 = only last repeated')
parser.add_argument('N', type=int, help='Number of elements')
parser.add_argument('seed', type=int, help='Seed for the random generator')
parser.add_argument('MAXE', type=int, help='maximum value for an element of the sequence', nargs='?', default=2**63)

args = parser.parse_args()
random.seed(args.seed)

assert args.N <= MAXN
assert args.mode in (0, 1, 2)
assert args.mode != 0 or args.N <= args.MAXE
assert args.mode != 2 or args.N <= args.MAXE - 1

reps = set()
values = []
while len(values) < args.N:
    x = random.randint(1, args.MAXE)
    if x not in reps:
        reps.add(x)
        values.append(x)
    if len(values) < args.N and args.mode == 1 and random.random() > 0.7:
        values.append(x)

assert len(values) == args.N

random.shuffle(values)

if args.mode == 2:
    values.pop()
    values.append(values[random.randint(0, args.N - 1)])

print(args.N)
for x in values:
    print(x, end=' ')
print()
