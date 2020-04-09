#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Soluzione di find_subsequence

from __future__ import print_function, division
import sys

if sys.version_info < (3, 0):
    input = raw_input # in python2, l'equivalente di input è raw_input

########################################################

def find_subsequence(p, t):
    """Riceve in input due stringhe p e t e cerca la prima occorrenza di p entro t.
       Ritorna -1 se non ne trova nessuna.
       Altrimenti ritorna la prima posizione della prima occorrenza (quella più a sinistra).
    """
    pos_t = 0
    for urgent in p:
        while pos_t < len(t) and t[pos_t] != urgent:
            pos_t = pos_t + 1
        if pos_t == len(t):
            return -1
    return pos_t + 1

########################################################

p = input()
t = input()

print(find_subsequence(p, t))

