#!/usr/bin/env python
# -*- codingxs: utf-8 -*-
# Soluzione di for2_std
# Romeo Rizzi, last: 2020-04-01

N=int(input())
for k in range(1,N+1):
    print(' '.join(map(str, [k*x for x in range(1,N+1)])))
