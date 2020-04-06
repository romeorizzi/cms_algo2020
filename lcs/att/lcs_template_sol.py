#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Template di soluzione di lcs

from __future__ import print_function, division
import sys

if sys.version_info < (3, 0):
    input = raw_input # in python2, l'equivalente di input è raw_input

########################################################
# INIZIO area entro la quale ti richiediamo/consigliamo di operare.

def lcs(s, t):
    """Ritorna la massima lunghezza di una stringa che sia sottosequenza comune delle stringhe s e t.
    """
    return 42

# FINE area entro la quale ti richiediamo/consigliamo di operare.
########################################################

len_s, len_t = map(int,input().split())
s = input()
t = input()
#print(f"{len_s} {len_t}")
#print(f"s={s}")
#print(f"t={t}")
print(lcs(s, t))

