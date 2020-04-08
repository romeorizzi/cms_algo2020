#!/usr/bin/env python3
from grader import inizializza, pensoCheCodiceSia, checkCode

inizializza()

sol = [1, 4, 5, 0]
res = [0, 0]

checkCode(sol, res)

if res[0] == 4:
    pensoCheCodiceSia(sol)
else:
    sol[0] = 1
    sol[1] = 2
    sol[2] = 3
    sol[3] = 4
    pensoCheCodiceSia(sol)
