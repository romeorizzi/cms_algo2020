#!/usr/bin/python3
import sys
import re

subtask = 0
lower_bound = 1
risposta = 0
upper_bound = 0
outfile = None

def confronto_con(x):
    global subtask, outfile, risposta, lower_bound, upper_bound
    print(upper_bound)
    if subtask == 4:  # se posso cambiare numero segreto (contenuto nella variabile risposta)
        if x > lower_bound + (upper_bound - lower_bound) // 2:
            risposta = lower_bound;
        else:
            risposta = upper_bound;
        print("2 %d" % risposta, file = outfile)

    # comunico nel log la "confronto_con" dell'utente
    print("0 %d" % x, file = outfile);

    if x > risposta:
        upper_bound = min(upper_bound, x - 1)
        return 1
    elif x < risposta:
        lower_bound = max(lower_bound, x + 1)
        return -1
    else:
        return 0

def answer(x):
    global outfile
    print("1 %d" % int(x), file = outfile)
    sys.exit(0)

def ottieni_n():
    global subtask, outfile, risposta, upper_bound

    infile = open("input.txt", "r")
    _risposta, _upper_bound, _subtask = [int(s) for s in infile.read().split()]
    risposta = _risposta
    upper_bound = _upper_bound
    subtask = _subtask

    outfile = open("output.txt", "w")
    return upper_bound
