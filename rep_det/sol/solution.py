#!/usr/bin/env python3

N = int(input())
X = list(map(int, input().split()))

assert len(X) == N

rep = set()

res = 2**64
for x in X:
    if x in rep:
        res = min(res, x)
    rep.add(x)

print(res if res < 2**64 else 0)
