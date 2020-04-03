#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Soluzione di for2_std
# Romeo Rizzi, last: 2020-04-01

with open("input.txt", "r") as fr:
    N = int(fr.readline())

with open("output.txt", "w") as fw:
    for k in range(1,N+1):
        fw.write(' '.join(map(str, [k*x for x in range(1,N+1)]))+"\n")
