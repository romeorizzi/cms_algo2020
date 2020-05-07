#!/usr/bin/python3

from grader import ottieni_num_balls, bigliaIntermedia, consegnaBiglieInOrdine

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
        if bigliaIntermedia(biglia_in_pos[posL], biglia_in_pos[0], biglia_in_pos[posR]) == biglia_in_pos[posL]:
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

myargmin = 0
myargmax = 1

for i in range(2, n):
    if bigliaIntermedia(myargmin, myargmax, i) == myargmax:
        myargmax = i
    if bigliaIntermedia(myargmin, myargmax, i) == myargmin:
        myargmin = i

tmp[0] = biglia_in_pos[0]
biglia_in_pos[0] = myargmin
biglia_in_pos[myargmin] = tmp[0]

# da ora in poi so che la biglia in posizione 0 e` di peso estremo (massimo oppure minimo, ma diciamo mymin)
# a questo punto vale la relazione a my< b se e solo se a e di peso intermedio tra (0,a,b)

mergeSort(biglia_in_pos, 1, n - 1, tmp)
consegnaBiglieInOrdine(biglia_in_pos)
