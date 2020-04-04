#!/usr/bin/python3

# confronto_con(val)
# answer(risp)

from grader import ottieni_n, confronto_con, answer

def ricerca(n):
	min = 1
	max = n + 1
	while min < max - 1:
		mid = (min + max) // 2
		g = confronto_con(mid)
		if g == 0:
			min = mid
			break
		elif g < 0:
			min = mid + 1
		else:
			max = mid
	answer(min)

n = ottieni_n()
ricerca(n);
