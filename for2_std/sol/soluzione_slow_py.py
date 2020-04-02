#!/usr/bin/env python
# -*- codingxs: utf-8 -*-
# Soluzione di for2_std
# Romeo Rizzi, last: 2020-04-01

N=int(input())
for i in range(1,N+1):
    for j in range(1,N+1):
        print(str(i*j), end=" ")
    print()
