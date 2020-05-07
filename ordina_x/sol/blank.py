#!/usr/bin/python3

from grader import ottieni_num_balls, pesa, consegnaBiglieInOrdine

num_balls = ottieni_num_balls()
intermedia = pesa(0, 1)

if intermedia < 0:
    consegnaBiglieInOrdine([0, 1])
else:
    consegnaBiglieInOrdine([1, 0])
