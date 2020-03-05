#!/usr/bin/env python3
from sys import argv
import random

MAXL = 64

if len(argv) < 3:
    exit(1)

if argv[1] == "COPY":
    with open(argv[2]) as f:
        print(f.read())

if argv[1] == "RANK":
    assert len(argv) == 3
    s = argv[2]
    assert 1 <= len(s) <= 100
    for c in s:
        assert c == "A" or c == "B"
    print(s)

if argv[1] == "UNRANK":
    assert len(argv) == 4
    l = int(argv[2])
    r = int(argv[3])
    assert 1 <= l <= 100
    assert 0 <= r <= 2**l
    print(l, r)

