#!/usr/bin/python3

from grader import ottieni_num_balls, bigliaIntermedia, consegnaBiglieInOrdine

num_balls = ottieni_num_balls()
intermedia = bigliaIntermedia(0, 1, 2)

if intermedia == 0:
    consegnaBiglieInOrdine([1, 0, 2])
elif intermedia == 1:
    consegnaBiglieInOrdine([0, 1, 2])
elif intermedia == 2:
    consegnaBiglieInOrdine([0, 2, 1])
