# Jump Jump (bungeejumping)

Un jumper deve portarsi dalla prima cella $v[0]$ di un vettore $v$ all'ultima cella $v[N-1]$, tramite una sequenza di salti.
I salti avvengono secondo le seguenti regole:
Quando il jumper di trova nella cella $i$-esima del vettore ($0\leq i \leq N-1$)
egli può portarsi nella cella $i\pm (v[i] - r)$ correndo un rischio di gravità $r\geq 0$. La compagnia di assicurazioni gli chiede un premio pari al massimo valore di rischio $r$ incorso da un salto lungo il percorso stabilito (classe di rischio).
Aiuta il jumper ad individuare un percorso che mantenga il rischio il più basso possibile.


## Dati di input
La prima riga del file `input.txt` contiene un interi positivo $N$, la lunghezza del vettore.
La seconda riga del file contiene gli $N$ valori del vettore, nell'ordine, e separati da spazi.
Si vedano i due esempi.

## Dati di output
Nel file `output.txt` si scriva un'unica riga contenente
un unico numero naturale: il minimo premio possibile da pagare per la polizza.


## Esempio di input/output
|input|output|
|-|-|
`7 3 3 3 3 3 3 3` |`0`|
`8 3 3 3 3 3 3 3 3` | `1`|


## Assunzioni
- $1 \le N \le 500$.

## Subtask
- **Subtask 1 [0 punti]**: i due esempi del testo.
- **Subtask 2 [20 punti]**:} $N \leq 10$.
- **Subtask 3 [40 punti]**:} $v[i] \leq 100$ per ogni $i = 0,1,\ldots, N-1$.
- **Subtask 4 [40 punti]**: nessuna restrizione.

