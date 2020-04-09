#!/usr/bin/env python

#
# Generatore di input per somme
#

from sys import argv, exit
from random import random, seed, shuffle

MaxN = 5000
MaxS = 100000

def main():

    if len( argv ) < 4:
        print 'Usage: %s N minS maxS [seed]' % (argv[0],)
        exit(1)
        
    N = int( argv[1] )
    minS = int( argv[2] )
    maxS = int( argv[3] )

    if len( argv ) > 4:
        seed( int(argv[4]) )
    else:
        seed()

    print N

    assert( 2 <= N and N <= MaxN )

    rS = maxS - minS + 1
    
    for i in range( N ):
        print int( random() * rS ) + minS,
    print

    
if __name__ == '__main__':
    main()

