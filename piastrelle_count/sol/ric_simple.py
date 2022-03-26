#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Soluzione parziale (ricorsione semplice) di piastrelle_count, written by Romeo Rizzi 2022.03.26

def ric(N):
    """Ritorna il numero di modi diversi di piastrellare un bagno 1xn con piastrelle 1x1 e 1x2."""
    if N<=1:
      return 1
    else:
      return ric(N-1) + ric(N-2)

N = int(input())
print(ric(N))


