# Hey Bob, giochiamo a Gameia? (gameia)

## Descrizione del problema
Whitney e Bob si stanno annoiando.  
Allora Whitney propone di giocare a Gameia, un gioco che si è appena inventata.  
Dopo aver ascoltato le regole Bob, che conosce bene la scorrettezza di Whitney, accetta di giocare ma con delle ""piccole"" modifiche in suo favore.  
Whitney accetta.  

### Gameia
- Il tabellone di gioco di Gameia è inizialmente un albero con $N$ nodi.
- A turno i giocatori colorano un nodo nell'albero: **Bob** li colorerà di **nero**, **Whitney** di **bianco**.
- Quando tutti gli $N$ nodi sono stati colorati, se c'è almeno un nodo colorato di bianco, Whitney vince. Altrimenti la vittoria sarà di Bob
- Quando Bob colora un nodo, egli colora anche tutti i nodi collegati in automatico.
- Bob ha a disposizione $K$ mosse speciali che gli permettono in qualunque momento di eliminare un qualsivoglia arco all'interno del grafo (eventualmente trasformando l'albero in foresta).
- Usare la mossa speciale non fa saltare il turno a Bob. Potrebbe anche usarla nel turno di Whitney volendo.
- Whitney inizia SEMPRE per prima

_Sia Bob che Whitney giocheranno ottimamente._

## File di input

Il programma deve leggere da un file di nome `input.txt`.  
Nella prima riga sono presenti due interi: $N$ (il numero di vertici dell'albero) e $K$ (il numero di mosse speciali di Bob).  
La successiva riga contiene $N - 1$ interi separati da spazio: l'$i$-esimo numero contiene il padre $F_{i+1}$ del nodo $i+1$

I vertici sono numerati a partire da $1$, che rappresenta sempre la radice dell'albero.

## File di output

Il programma deve scrivere in un file di nome `output.txt`.  
file deve contenere un unico intero: $0$ se vince Whitney, $1$ se vince Bob


## Assunzioni

* $1 \leq N \leq 1000\, 000$
* $0 \leq K \leq N$
* L'albero fornito in input è un ben formattato (è connesso ed aciclico) ma non è garantito che $F_i \leq F_{i+1}$

## Subtask

- **Subtask 1 \[ 5 punti\]:** casi di esempio.
- **Subtask 2 \[35 punti\]:** $N \leq 50$.
- **Subtask 3 \[35 punti\]:** $N \leq 500$.
- **Subtask 4 \[25 punti\]:** $N \leq 100\,000$.


## Esempio di input/output

| File `input.txt` | &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; | File `output.txt` |
| :--------------- | :----------------------------------------: | :---------------- |
| 1 1<br>          |                   &nbsp;                   | 0                 |
| &nbsp;           |                   &nbsp;                   | &nbsp;            |
| 2 1<br>1         |                   &nbsp;                   | 1                 |
| &nbsp;           |                   &nbsp;                   | &nbsp;            |
| 3 1<br>2 1       |                   &nbsp;                   | 0                 |
| &nbsp;           |                   &nbsp;                   | &nbsp;            |
| 4 1<br>1 2 3     |                   &nbsp;                   | 1                 |
| &nbsp;           |                   &nbsp;                   | &nbsp;            |
| 4 0<br>1 2 3     |                   &nbsp;                   | 0                 |
## Note
Come leggere l'albero dell'input

```
6 1
3 1 5 1 3
```

Il nodo 2 è figlio del nodo 3;
Il nodo 3 è figlio del nodo 1;  
Il nodo 4 è figlio del nodo 5; 
Il nodo 5 è figlio del nodo 1;
Il nodo 6 è figlio del nodo 3;
```
            1
           / \
          5   3
        /    / \
       4    2   6

```

Sono disponibili dei suggerimenti.

