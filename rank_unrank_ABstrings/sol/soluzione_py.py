# -*- coding: utf-8 -*-
# Soluzione di rank_unrank_ABstrings, written by Romeo Rizzi 2018.12.04

from __future__ import print_function
import sys

if sys.version_info < (3, 0):
    input = raw_input # in python2, l'equivalente di input è raw_input


def ABstring2rank(s):
    if len(s) == 0:
        return 0
    if s[-1]=='A':
        return 2*ABstring2rank(s[:-1])
    else:
        return 1 + 2*ABstring2rank(s[:-1])

def ABstring_of_len_and_rank(length, r):
    # print("length = %d, r = %d, r.mod.2 = %d" % (length, r, r%2) )
    if length==0:
        return ""
    if (int(r) % 2) == 0:
        return ABstring_of_len_and_rank(length-1, r/2) + "A"
    else:
        return ABstring_of_len_and_rank(length-1, r/2) + "B"

input_string = raw_input()

if input_string[0] == 'A' or input_string[0] == 'B':
   print( ABstring2rank(input_string) )
else:
   length, r = input_string.split()
   print( ABstring_of_len_and_rank(int(length), int(r)) )


