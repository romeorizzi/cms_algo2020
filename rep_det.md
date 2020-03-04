##Repetitions Detector (rep_det)

Mi arrivano in input $N$ numeri interi positivi $x_1, \ldots, x_N$ e devo trovare se ce ne sono due ripetuti. In caso negativo rispondo $0$, altrimenti il più piccolo numero che compare più volte.

###Esempi

|input from stdin | output to stdout |
|---|---|
|3  | 0 |
|1 3 2 | |

|input from stdin | output to stdout |
|---|---|
|8  | 3 |
|1 3 2 7 6 6 3 7 | |



###Subtasks

* [20pt]   $N \leq 100$.
* [20pt]   $N \leq 1.000.000$, $x_i \leq 1000$ per ogni $i=1,\ldots,N$.
* [20pt]   $N \leq 1.000.000$, solo l'ultimo numero $x_N$ potrebbe essere quello eventualmente ripetuto.
* [40pt]   $N \leq 1.000.000$
