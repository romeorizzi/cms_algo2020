#!/usr/bin/python3


from grader import ottieni_valori, pesa, pensoCheMaxSia

(num_balls, max_lies) = ottieni_valori()

heaviest = 0

for i in range(1, num_balls):
    res = [0, 0]
    while True:
        new_vote = pesa(i, heaviest)
        if new_vote < 0:
            new_vote = 0

        res[new_vote] += 1
        if res[new_vote] >= (max_lies + 1):
            break

    if res[0] > res[1]:
        max_lies -= res[1]
    else:
        max_lies -= res[0]
        heaviest = i

pensoCheMaxSia(heaviest)
