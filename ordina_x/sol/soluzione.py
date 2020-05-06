#!/usr/bin/python3

# problem: ordina_x, mergeSort, Romeo Rizzi Mar 2015

from grader import ottieni_num_balls, pesa, consegnaBiglieInOrdine

def mergeSort(biglia_in_pos, from_, to, tmp):
    if to <= from_:
        return
    middle = (from_ + to) // 2
    mergeSort(biglia_in_pos, from_, middle, tmp)
    mergeSort(biglia_in_pos, middle + 1, to, tmp)
    posL = from_
    posR = middle + 1
    pos = from_
    while (posL <= middle) and (posR <= to):
        if pesa(biglia_in_pos[posL], biglia_in_pos[posR]) < 0:
            tmp[pos] = biglia_in_pos[posL]
            pos += 1
            posL += 1
        else:
            tmp[pos] = biglia_in_pos[posR]
            pos += 1
            posR += 1

    while posL <= middle:
        tmp[pos] = biglia_in_pos[posL]
        pos += 1
        posL += 1

    while posR <= to:
        tmp[pos] = biglia_in_pos[posR]
        pos += 1
        posR += 1

    for pos in range(from_, to + 1):
        biglia_in_pos[pos] = tmp[pos]


n = ottieni_num_balls()

biglia_in_pos = [0] * n
tmp = [0] * n

for i in range(n):
    biglia_in_pos[i] = i

mergeSort(biglia_in_pos, 0, n - 1, tmp)
consegnaBiglieInOrdine(biglia_in_pos)


