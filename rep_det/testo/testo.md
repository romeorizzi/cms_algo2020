# Repetitions Detector (rep\_det)

Data una sequenza di $N$ interi positivi $x_1, \ldots, x_N$ determinare se essa contiene ripetizioni,
ovvero se esistono $i$ e $j$ tali che $x_i = x_j$: in tal caso restituire in output il più piccolo
elemento della sequenza che compare più di una volta, in caso negativo restituire $0$.

## Formato di input
L'input avviene da `stdin` ed è composto da due righe:
- la prima contiene un solo intero $N$
- la seconda gli $N$ interi $x_1, \ldots, x_N$ che compongono la sequenza

## Formato di output
L'output avviene su `stdout` e consiste in una sola riga, contenente un solo numero intero: il più piccolo elemento ripetuto
nella sequenza, se questo esiste, altrimenti il valore $0$

## Esempi di input ed output

|input da stdin | output su stdout |
|---|---|
|3  | 0 |
|1 3 2 | |

|input da stdin | output su stdout |
|---|---|
|8  | 3 |
|1 3 2 7 6 6 3 7 | |

## Limiti
- $N \leq 1\,000\,000$
- $1 \leq x_i < 2^{63}$ per ogni $i = 0, \ldots, N$

## Subtasks
- **Subtask 1 [20pt]:** $N \leq 100$;
- **Subtask 2 [20pt]:** $N \leq 1\,000\,000$, $x_i \leq 1000$ per ogni $i = 1, \ldots, N$;
- **Subtask 3 [20pt]:** $N \leq 1\,000\,000$, solo l'ultimo numero $x_N$ potrebbe essere quello eventualmente ripetuto;
- **Subtask 4 [40pt]:** $N \leq 1\,000\,000$.
