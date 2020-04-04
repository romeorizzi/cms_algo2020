#!/usr/bin/python3

# confronto_con(val)
# answer(risp)

from grader import ottieni_n, confronto_con, answer

def ricerca(n):
	g = confronto_con(n/2)
	if g == 0:
		answer(n/2)
	if g > 0:
		answer(1)
	if g < 0:
		answer(n)

n = ottieni_n()
ricerca(n);
