#!/usr/bin/env python3

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

assert len(A) == N
assert len(B) == N

def solve():
    i = j = N - 1
    while True:
        if A[i] == B[j]:
            return A[i]
        if A[i] < B[j]:
            j -= 1
        else:
            i -= 1

print(solve())