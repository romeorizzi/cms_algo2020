#!/usr/bin/env python

# Generatore di input per somme
# genera solo input con somma totale pari a zero
# cercando di alternare il piu' possibile numeri
# negativi e positivi

from sys import argv, exit
from random import random, seed, shuffle

MaxN = 5000
MaxS = 100000

def dado( centro, raggio ):
    n = int( random() * raggio )
    return n - raggio/2 + centro

def main():

    if len( argv ) < 2:
        print 'Usage: %s N [seed]' % (argv[0],)
        exit(1)
        
    N = int( argv[1] )

    if len( argv ) > 2:
        seed( int(argv[2]) )
    else:
        seed()

    raggio = 10000
    centro = 0

    print N

    assert( 2 <= N and N <= MaxN )

    somma = 0
    for i in range( N - 1 ):
        num = dado( centro, raggio )
        print num,
        somma += num
        centro = -somma
        
    print -somma

    
if __name__ == '__main__':
    main()

