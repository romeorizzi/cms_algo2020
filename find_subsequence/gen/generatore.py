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
    len_p = int(argv[1])
    len_t = int(argv[2])
    n_occurrences = int(argv[3])
    
    assert 1 <= len_p <= len_t <= 1000000
    if n_occurrences == 0:
        p = ''.join([random.choice(string.ascii_uppercase) for _ in range(len_p-1)])
        p = p + 'Z'
        t = ''.join([random.choice(string.ascii_uppercase[0:-1]) for _ in range(len_t)])
    else:
        p = ''.join([random.choice(string.ascii_uppercase) for _ in range(len_p)])
        pos = random.randint(0, len_t - len_p +1)
        t = ''.join([random.choice(string.ascii_uppercase[0:-1]) for _ in range(pos -1)])
        t = t + p
        t = t + ''.join([random.choice(string.ascii_uppercase) for _ in range(len_t - len(t))])
    print(p)
    print(t)

