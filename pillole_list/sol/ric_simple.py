#!/usr/bin/env python3

# Soluzione di pillole_list, written by Alessandro Righi 2020.03.21

def compute(I: int, M: int, s: str):
    if I == 0 and M == 0:
        yield s
    if I > 0:
        yield from compute(I - 1, M + 1, s + "I")
    if M > 0:
        yield from compute(I, M - 1, s + "M")


def main():
    N = int(input())

    sol = list(compute(N, 0, ""))

    print(len(sol))
    for s in sol:
        print(s)

if __name__ == '__main__':
    main()
