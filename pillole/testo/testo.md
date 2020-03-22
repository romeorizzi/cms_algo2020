# Pillole di zia Lucilla (pillole)

Il dottore ha dato a Zia Lucilla un flaconcino che contiene esattamente $N$ pillole,
e le ha prescritto di assumere mezza pillola ogni giorno, alla sera prima di coricarsi.
La prima sera zietta prende una pillola dal flaconcino (inizialmente sono tutte intere), la spezza in due, ne ingerisce una metà, e rimette l’altra metà nel flaconcino.
Nei giorni seguenti zia prende un pezzo a caso del flaconcino (potrebbe essere una pillola intera
oppure una mezza pillola, il primo pezzo che le viene a tiro senza nemmeno mettersi gli occhiali). Se ha pescato una mezza pillola la ingerisce. Se ha pescato una pillola intera la spezza a metà, rimette una delle due metà nella bottiglietta, e ingerisce l’altra metà.

La zia può quindi svuotare la bottiglietta in tanti modi diversi. Rappresentiamo il trattamento come una stringa di $2N$ caratteri, il cui carattere $i$-esimo è 'I' se nel giorno $i$-esimo la zia ha pescato una pillola intera, e 'M' se la zia ha invece pescato una mezza pillola.
Ad esempio, qualora la bottiglia contenesse inizialmente $N=3$ pillole intere,
i possibili trattamenti sarebbero allora i seguenti:

```
IIIMMM IIMIMM IIMMIM IMIIMM IMIMIM
```

Scrivete un programma che, dato $N$, restituisca il numero di trattamenti possibili.

## Input (da stdin)
Il vostro programma riceve in input l’intero $N$, il numero di pillole presenti nella
bottiglia all’inizio della cura.

## Output (su stdout)
Restituite in output un unico intero: il numero di trattamenti possibili, ossia il numero di modi diversi in cui la zia può operare sulla bottiglietta fino a svuotarla completamente.

## Assunzioni nelle istanze da punti
- $1 ≤ N ≤ 32$
- L’output sarà abbastanza piccolo da poter essere mantenuto dentro un `long long int`

## Esempi di input/output

| input (da stdin) | output (su stdout) |
|---|---|
| 3 | 5 |

| input (da stdin) | output (su stdout) |
|---|---|
| 30 | 3814986502092304 |

## Subtasks
- **Subtask 1 [25pt]:** $N \leq 10$
- **Subtask 2 [25pt]:** $N \leq 20$
- **Subtask 3 [25pt]:** $N \leq 30$
- **Subtask 4 [25pt]:** $N \leq 32$
- **Subtask 5 [0pt]:** nell'ordine, le istanze $N = 0$, $N = 33$, $N = 34$, $N = 35$


