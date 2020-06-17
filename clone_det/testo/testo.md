# Clone detector (clone\_det)

## Descrizione
Date in input due sequenze di $N$ numeri naturali $A$ e $B$ determinare il più grande numero contenuto in entrambe le liste. Entrambe le liste sono ordinate in ordine crescente ed iniziano con il valore $0$.

## Formato di input
Dovrai leggere da standard input tre righe:
- la prima contiene un singolo intero, $N$
- la seconda contiene $N$ interi $a_1, \ldots, a_N$
- la terza contiene $N$ interi $b_1, \ldots, b_N$

## Formato di output
Dovrai scrivere su standard output un solo numero intero, la risposta al problema.

## Esempi
|input da stdin | output su stdout |
|---|---|
|3  | 0 |
|0 3 5 |  |
|0 2 4  | |

|input da stdin | output su stdout |
|---|---|
|8  | 7 |
|0 1 2 2 6 6 7 8 | |
|0 0 2 3 5 7 9 9 | |

## Assunzioni
- le sequenze $A$ e $B$ sono ordinate in ordine crescente
- il primo elemento $a_0$ e $b_0$ di entrambe le sequenze è $0$
- $0 \leq a_i, b_i \leq 2^{63}$ per ogni $i = 1, \ldots N$
- $N \leq 1\,000\,000$

## Assegnazione del punteggio
- **Subtask 1 [20 punti]:** $N \leq 100$
- **Subtask 2 [20 punti]:** $N \leq 1\,000\,000$ e $a_i, b_i \leq 1\,000\,000$ per ogni $i = 1, \ldots N$
- **Subtask 3 [30 punti]:** $N \leq 500\,000$
- **Subtask 4 [30 punti]:** $N \leq 1\,000\,000$
