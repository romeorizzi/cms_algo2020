# Trova il numero

## Descrizione del problema

Ti vengono dati due interi `d` e `s`. Trova il più piccolo numero tale che sia divisibile per `d` e abbia la somma delle cifre uguale ad `s`.


## Limiti
`1 <= d <= 500`
`1 <= s <= 5000`

## Input
I due interi `d` ed `s`, separati da spazio.

## Output

Il numero richiesto o `-1` se non esiste

## Esempi

|input from stdin | output to stdout |
|------|--------|
|13  50| 699998 |

|input from stdin | output to stdout |
|-----|---------------------------------|
|61  2| 1000000000000000000000000000001 |

|input from stdin | output to stdout |
|------|---------------------------------|
|15  50| 1000000000000000000000000000001 |

## Subtask
- **Subtask 1 [10 punti]:** `d = 2`, `n <= 100`.
- **Subtask 2 [10 punti]:** `d = 3`, `n <= 100`.
- **Subtask 3 [10 punti]:** `d = 7`, `n <= 100`.
- **Subtask 4 [10 punti]:** `d = 13`, `n <= 100`.
- **Subtask 5 [10 punti]:** `d = 17`, `n <= 100`.
- **Subtask 6 [10 punti]:** `d <= 10`, `n <= 10`.
- **Subtask 7 [10 punti]:** `d <= 100`, `n <= 100`.
- **Subtask 8 [10 punti]:** `d <= 200`, `n <= 1000`.
- **Subtask 9 [10 punti]:** `d <= 400`, `n <= 3000`.
- **Subtask 10 [10 punti]:** `d <= 500`, `n <= 5000`.
