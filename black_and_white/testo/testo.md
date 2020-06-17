# Bianco e Nero (black\_and\_white)

## Descrizione del problema

Vi viene fornita in unput una lunga sequenza di bit.
Vi verrà poi chiesto di effetture varie operazioni su quei bit.  
Le operazioni sono:
- Restituisci il maggior numero di '1' consecutivi presenti nell'intervallo $[i,j]$
- Inverti il valore di tutti i bit nell'intervallo $[i,j]$
In entrambe le operazioni $i$ e $j$, $1\leq i\leq j \leq N$ (dove $N$ è la lunghezza della sequenza), rappresentano delle posizioni nella sequenza.
Attenzione **le posizioni partono da 1** !!

## File di input

Il programma deve leggere da un file di nome `input.txt`. Nella prima riga è presente un intero $N$, il numero di bit della sequenza. La successiva riga contiene tutti i bit separati da spazio, per poterne facilitare la lettura.  
Nella terza riga è presente un intero $M$, il numero di operazioni da effettuare. Le successive $M$ righe contengono $3$ interi ciascuna $t,i,j$:
- $t$,il tipo di operazione
    - $0$ per la stampa del maggior numero di '1' consecutivi nell'intervallo dato
    - $1$ per invertire il valore dei bit nell'intervallo dato
- $i$, l'estremo sinistro dell'intervallo
- $j$, l'estremo destro dell'intervallo

## File di output

Il programma deve scrivere in un file di nome `output.txt`.  

Per ogni operazione di tipo $0$, scrivere una riga contenente il risultato dell'operazione.  
(Non stampare niente per le operazioni di tipo $1$.)

## Assunzioni

* $1 \leq N \leq 100\, 000$
* $1 \leq M \leq 100\, 000$
* $t \in \{0,1\}$
* $1 \leq i \leq N$
* $i \leq j \leq N$
* Almeno una query di tipo $0$

## Subtask

- **Subtask 1 \[ 5 punti\]:** Alcuni dei casi di esempio$.
- **Subtask 2 \[20 punti\]:** $N \leq 10$, $M \leq 100$.
- **Subtask 3 \[30 punti\]:** $N \leq 100$, $M \leq 1000$.
- **Subtask 4 \[20 punti\]:** $N \leq 1000$, $M \leq 1000$.
- **Subtask 5 \[15 punti\]:** $N \leq 30000$, $M \leq 50\,000$.
- **Subtask 6 \[10 punti\]:** nessuna limitazione specifica.

## Esempio di input/output

| File `input.txt`                                                                | &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; | File `output.txt` |
| :------------------------------------------------------------------------------ | :----------------------------------------: | :---------------- |
| 4<br>1 0 1 0<br>5<br>0 1 4<br>1 2 3<br>0 1 4<br>1 3 3<br>0 4 4                  |                   &nbsp;                   | 1<br>2<br>0       |
| &nbsp;                                                                          |                   &nbsp;                   | &nbsp;            |
| 5<br>0 0 0 1 0<br>3<br>0 2 3<br>0 2 5<br>0 1 5                                  |                   &nbsp;                   | 0<br>1<br>1       |
| &nbsp;                                                                          |                   &nbsp;                   | &nbsp;            |
| 8<br>0 1 0 0 1 0 1 0<br>6<br>0 4 8<br>1 6 8<br>0 2 5<br>0 8 8<br>1 5 8<br>0 8 8 |                   &nbsp;                   | 1<br>1<br>1<br>0  |

## Note
Sono disponibili dei suggerimenti.
