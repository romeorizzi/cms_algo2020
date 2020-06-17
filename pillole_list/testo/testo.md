# Pillole di zia Lucilla, ora si elenchi (pillole\_list)

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

Scrivete un programma che, dato $N$, restituisca tutti i trattamenti possibili.

## Input (da stdin)
Il vostro programma riceve in input l’intero $N$, il numero di pillole presenti nella
bottiglia all’inizio della cura.

## Output (su stdout)
Dovrai scrivere in output $S+1$ righe:
- la prima contiene l'intro $S$, il numero di soluzioni possibili
- le successive $S$ righe contengono le possibili sequenze valide

Potrai scrivere le righe dell'output nell'ordine che preferisci

## Assunzioni
- $1 ≤ N ≤ 10$
- L’output sarà abbastanza piccolo da poter essere mantenuto dentro un `long long int`

## Esempi di input/output

| input (da stdin) | output (su stdout) |
|---|---|
| 1 | 1 |
|   | IM |

| input (da stdin) | output (su stdout) |
|---|---|
| 3 | 14 |
|| IIIIMMMM |
|| IIIMIMMM |
|| IIIMMIMM |
|| IIIMMMIM |
|| IIMIIMMM |
|| IIMIMIMM |
|| IIMIMMIM |
|| IIMMIIMM |
|| IIMMIMIM |
|| IMIIIMMM |
|| IMIIMIMM |
|| IMIIMMIM |
|| IMIMIIMM |
|| IMIMIMIM |


## Subtasks
- **Subtask 1 [25pt]:** $N \leq  4$
- **Subtask 2 [25pt]:** $N \leq  6$
- **Subtask 3 [25pt]:** $N \leq  8$
- **Subtask 4 [25pt]:** $N \leq 10$
