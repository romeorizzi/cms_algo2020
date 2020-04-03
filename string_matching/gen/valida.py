#!/usr/bin/env python2

from sys import argv, exit, stderr
import os

def usage():
    print >> stderr, "Usage: %s file_input.txt" % \
        os.path.basename(argv[0])
    exit(1)

def run(f):
	f1 = f[0].split()
	
	if(len(f1) != 2) :
		print >> stderr, "Numero argomenti in input non corretto"
		return 1

	if not(int(f1[0])>=0 and int(f1[1])>=0) :
		print >> stderr, "Input non corretto, numeri non interi"
		return 1
	
	return 0

if __name__ == "__main__":
    if len(argv) < 2:
        usage()

    f = open(argv[1]).readlines()
			
    exit(run(f))
