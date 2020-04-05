#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Soluzione (ricorsione con memoizzazione) di pillole, written by Romeo Rizzi 2004.04.18

def ric(I,M):
  """Ritorna il numero di modi diversi di svuotare un flaconcino che inizialmente contenga I pillole intere e M pillole mezze."""
  if I==0:
    return 1
  if hash_risp[I][M] == None:
    if M==0:
      hash_risp[I][M] = ric(I-1,1)
    else:
      hash_risp[I][M] = ric(I-1,M+1) + ric(I,M-1)
  return hash_risp[I][M]

N = int(input())
hash_risp = [ [None] * (N+1) for _ in range(N+1) ]
print(ric(N,0))


