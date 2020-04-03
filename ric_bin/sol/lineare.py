#!/usr/bin/python3

# confronto_con(val)
# answer(risp)

from grader import ottieni_n, confronto_con, answer

def ricerca(n):
	min = 1
	max = n + 1
	for x in range(min, max):
		g = confronto_con(x)
		if g == 0:
			answer(x)
			break

n = ottieni_n()
ricerca(n);
