#!/usr/bin/env python3
from sys import argv
import random, string

if len(argv) < 3:
    exit(1)

if argv[1] == "COPY":
    with open(argv[2]) as f:
        print(f.read())
    exit(0)

elif argv[1] == "ECHO":
    print(argv[2])
    print(argv[3])
    exit(0)

else:
    len_s = int(argv[1])
    len_t = int(argv[2])
    assert 1 <= len_s <= 1000
    assert 1 <= len_t <= 1000
    alphabet = argv[3]
    seed = int(argv[4])
    random.seed(seed)
    
    s = ''.join([random.choice(alphabet) for _ in range(len_s)])
    t = ''.join([random.choice(alphabet) for _ in range(len_t)])
    print(f"{len(s)} {len(t)}")
    print(s)
    print(t)

