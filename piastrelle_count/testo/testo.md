# Numero di piastrellature di bagno 1xn (piastrelle_count)

Pippo ha un corridoio di dimensione $1 \times N$ da piastellare utilizzando solo piastrelle quadrate di dimensioni $1 \times 1$ e piastrelle rettangolari di dimensioni $1 \times 2$.

Scrivete un programma che, dato $N$, restituisca il numero di piastrallature possibili.

## Input (da stdin)
Il vostro programma riceve in input l'intero $N$, la lunghezza del corridoio da piastrellare.

## Output (su stdout)
Restituite in output un unico intero: il numero di tutte le diverse piastrallature possibili di un corridoio di lunghezza $N$.

## Assunzioni sulle istanze da punti
- $1 ≤ N ≤ 32$
- L’output sarà abbastanza piccolo da poter essere mantenuto dentro un `long long int`

## Esempi di input/output

| input (da stdin) | output (su stdout) |
|---|---|
| 3 | 3 |

| input (da stdin) | output (su stdout) |
|---|---|
| 4 | 5 |

## Subtasks
- **Subtask 1 [25pt]:** $N \leq 10$
- **Subtask 2 [25pt]:** $N \leq 20$
- **Subtask 3 [25pt]:** $N \leq 30$
- **Subtask 4 [25pt]:** $N \leq 32$
- **Subtask 5 [0pt]:** nell'ordine, le istanze $N = 0$, $N = 33$, $N = 34$, $N = 35$


