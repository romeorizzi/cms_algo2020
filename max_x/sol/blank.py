#!/usr/bin/python3


from grader import ottieni_valori, pesa, pensoCheMaxSia

(num_balls, max_lies) = ottieni_valori()

if pesa(0, 1) == -1:
    pensoCheMaxSia(1)
else:
    pensoCheMaxSia(0)
