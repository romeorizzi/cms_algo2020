# Trova il numero

## Descrizione del problema

Ti vengono dati due interi $d$ e $s$. Trova il più piccolo numero tale che sia divisibile per $d$ e abbia la somma delle cifre uguale ad $s$.


## Limiti
$1 \leq d \leq 500$
$1 \leq s \leq 5000$

## Input
I due interi $d$ ed $s$, separati da spazio.

## Output

Il numero richiesto o $-1$ se non esiste

## Esempi

|input from stdin | output to stdout |
|------|--------|
|13  50| 699998 |

|input from stdin | output to stdout |
|-----|---------------------------------|
|61  2| 1000000000000000000000000000001 |

|input from stdin | output to stdout |
|------|---------------------------------|
|15  50| -1 |

## Subtask
- **Subtask 1 [0 punti]:** i tre esempi quì sopra.
- **Subtask 2 [10 punti]:** $d = 2$, $n \leq 100$.
- **Subtask 3 [10 punti]:** $d = 3$, $n \leq 100$.
- **Subtask 4 [10 punti]:** $d = 7$, $n \leq 100$.
- **Subtask 5 [10 punti]:** $d = 13$, $n \leq 100$.
- **Subtask 6 [10 punti]:** $d = 17$, $n \leq 100$.
- **Subtask 7 [10 punti]:** $d \leq 10$, $n \leq 10$.
- **Subtask 8 [10 punti]:** $d \leq 100$, $n \leq 100$.
- **Subtask 9 [10 punti]:** $d \leq 200$, $n \leq 1000$.
- **Subtask 10 [10 punti]:** $d \leq 400$, $n \leq 3000$.
- **Subtask 11 [10 punti]:** $d \leq 500$, $n \leq 5000$.
