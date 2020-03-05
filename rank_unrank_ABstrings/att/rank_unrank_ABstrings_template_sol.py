# -*- coding: utf-8 -*-
# Template di soluzione per il problema rank_unrank_ABstrings

from __future__ import print_function
import sys

if sys.version_info < (3, 0):
    input = raw_input # in python2, l'equivalente di input è raw_input

# INIZIO area entro la quale ti richiediamo/consigliamo di operare.

def ABstring2rank(s):
    return 42

def ABstring_of_len_and_rank(length, r):
    return "ABBA"        

# FINE area entro la quale ti richiediamo/consigliamo di operare.

input_string = input()

if input_string[0] == 'A' or input_string[0] == 'B':
   print( ABstring2rank(input_string) )
else:
   length, r = input_string.split()
   print( ABstring_of_len_and_rank(int(length), int(r)) )

