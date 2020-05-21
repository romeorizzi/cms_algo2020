# Hey Bob, giochiamo a Gameia? (gameia)

## Descrizione del problema
Whitney e Bob si stanno annoiando.  
Allora Whitney propone di giocare a Gameia, un gioco che si è appena inventata.  
Dopo aver ascoltato le regole, Bob, che conosce bene la scorrettezza di Whitney, accetta di giocare ma con delle ""piccole"" modifiche in suo favore.  
Whitney ci riflette per qualche secondo, ma poi accetta le modifiche di Bob ben volentieri.  

### Gameia
- Il tabellone di gioco di Gameia è inizialmente un albero di $N$ nodi labellati coi numeri da $1$ a $N$.
- A turno i giocatori scelgono un nodo del tabellone:
  - se il turno è di **Whitney** il nodo viene colorato di **bianco**,
  - se il turno è di **Bob** quel nodo e tutti i nodi ad esso adiacenti vengono colorati di **nero** (compresi quelli già precedentemente colorati di bianco).
- Un giocatore non può mai scegliere un nodo che sia già stato scelto dall'avversario.
- La partita finisce non appena ciascun nodo possiede un qualche colore: vince Whitney se a quel punto almeno un nodo è bianco, altrimenti vince Bob.
- In qualunque momento del gioco, Bob, senza per questo dover rinunciare al proprio turno,
  può impiegare uno dei suoi $K$ gettoni di intervento straordinario accordatigli ad inizio partita
  per eliminare un arco a sua scelta (il primo intervento trasforma l'albero in foresta).
- Whitney inizia SEMPRE per prima.

Assunto che _Bob e Whitney giocheranno entrambi ottimamente,_ chi dei due vincerà la partita?

## File di input

Il programma deve leggere da un file di nome `input.txt`.  
Nella prima riga sono presenti due interi: $N$ (il numero di nodi dell'albero) e $K$ (il numero massimo di interventi straordinari consentiti a Bob).  
La successiva riga contiene $N - 1$ interi separati da spazio: l'$i$-esimo numero contiene il padre $F_{i+1}$ del nodo $i+1$.

I nodi sono labellati coi numeri da $1$ a $N$. Il nodo $1$ rappresenta sempre la radice dell'albero che è stato radicato al solo scopo di consentire questa rappresentazione compatta.

## File di output

Il programma deve scrivere in un file di nome `output.txt`
e contenente solamente una cifra binaria: $0$ se vince Whitney, $1$ se vince Bob.


## Assunzioni

* $1 \leq N \leq 1000\, 000$
* $0 \leq K \leq N$
* L'albero fornito in input è un ben formato (è un grafo connesso ed aciclico) ma non è garantito che $F_i \leq F_{i+1}$

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
| 3 1<br>1 2       |                   &nbsp;                   | 0                 |
| &nbsp;           |                   &nbsp;                   | &nbsp;            |
| 4 1<br>1 2 3     |                   &nbsp;                   | 1                 |
| &nbsp;           |                   &nbsp;                   | &nbsp;            |
| 4 0<br>1 2 3     |                   &nbsp;                   | 0                 |

## Note
Come leggere l'input

```
6 1
3 1 5 1 3
```
L'albero ha $6$ nodi. Bob ha a disposizione $1$ solo gettone "intervento straordinario".

Il nodo $2$ è figlio del nodo $3$;  
Il nodo $3$ è figlio del nodo $1$;  
Il nodo $4$ è figlio del nodo $5$;  
Il nodo $5$ è figlio del nodo $1$;  
Il nodo $6$ è figlio del nodo $3$;

```
            1
           / \
          5   3
        /    / \
       4    2   6

```

Sono disponibili dei suggerimenti.
