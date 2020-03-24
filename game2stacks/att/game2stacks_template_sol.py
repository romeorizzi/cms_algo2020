# -*- coding: utf-8 -*-
# Template di soluzione di game2stacks

from __future__ import print_function
import sys

if sys.version_info < (3, 0):
    input = raw_input # in python2, l'equivalente di input è raw_input


n1 = int(input())
n2 = int(input())

# INIZIO area entro la quale ti richiediamo/consigliamo di operare.

def play(n1, n2):  # questa è la funzione che devi perfezionare
    return (0,0)   # non arrenderti sempre!
    
# FINE area entro la quale ti richiediamo/consigliamo di operare.

togli1, togli2 = play(n1, n2)
print(togli1)
print(togli2)

