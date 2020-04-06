#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# Soluzione di lcs

from __future__ import print_function, division
import sys

if sys.version_info < (3, 0):
    input = raw_input # in python2, l'equivalente di input è raw_input

########################################################

def lcs(s, t):
    """Ritorna la massima lunghezza di una stringa che sia sottosequenza comune delle stringhe s e t.
    """
    risp = [[0]*(len(t)+1) for _ in range(len(s)+1)]
    for i in range(len(s)):
      for j in range(len(t)):
          if s[i] == t[j]:
             risp[i+1][j+1] = 1 + risp[i][j]
          else:
             risp[i+1][j+1] = max(risp[i+1][j],risp[i][j+1])
    #print(risp)
    return risp[len(s)][len(t)]

########################################################
len_s, len_t = map(int,input().split())
s = input()
t = input()
#print(f"{len_s} {len_t}")
#print(f"s={s}")
#print(f"t={t}")
print(lcs(s, t))

