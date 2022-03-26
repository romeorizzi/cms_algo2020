#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Soluzione (ricorsione con memoizzazione) di piastrelle_count, written by Romeo Rizzi 2022.03.26

def ric(N):
  """Ritorna il numero di modi diversi di piastrellare un bagno 1xn con piastrelle 1x1 e 1x2."""
  if hash_risp[N] == None:
    if N<=1:
      hash_risp[N] = 1
    else:
      hash_risp[N] = ric(N-1) + ric(N-2)
  return hash_risp[N]

N = int(input())
hash_risp = [None] * (N+1)
print(ric(N))


