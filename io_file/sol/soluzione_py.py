#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Soluzione di io_file
# Romeo Rizzi, last: 2020-03-24

with open("input.txt", "r") as fr:
    n = int(fr.readline())

with open("output.txt", "w") as fw:
    fw.write(str(n) + "\n")
