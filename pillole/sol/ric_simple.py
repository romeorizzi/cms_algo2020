#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Soluzione parziale (ricorsione semplice) di pillole, written by Romeo Rizzi 2020.03.18

def ric(I,M):
  """Ritorna il numero di modi diversi di svuotare un flaconcino che inizialmente contenga I pillole intere e M pillole mezze."""
  if I==0:
    return 1
  if M==0:
    return ric(I-1,1)
  return ric(I-1,M+1) + ric(I,M-1)

N = int(input())
print(ric(N,0))


