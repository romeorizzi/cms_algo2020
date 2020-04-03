#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Soluzione di io_file

with open("input.txt", "r") as fr:
    n = int(fr.readline())

with open("output.txt", "w") as fw:
    fw.write(str(n) + "\n")
