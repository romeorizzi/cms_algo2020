# La dieta di Poldo, ora ritorna la soluzione! (poldo\_sequenza)

## Descrizione del problema

In breve: come per il problema poldo ma sei ora chiamato a produrre e restituire una soluzione ottima, ossia una sottosequenza valida (conforme alla dieta prescritta dal dottore) di lunghezza massima, invece che limitarti a restituire solo la lunghezza massima. Una qualsiasi soluzione ottima verrà considerata buona come risposta.

Richiamo a tutto il problema:
Il dottore ordina a Poldo di seguire una dieta. Ad ogni pasto non può mai mangiare un panino che abbia un peso maggiore o uguale a quello appena mangiato.  
Quando Poldo passeggia per la via del suo paese, da ogni ristorante esce un cameriere proponendo il menù del giorno. Ciascun menù è composto da una serie di panini, che verranno serviti in un ordine ben definito, e dal peso di ciascun panino. Poldo, per non violare la regola della sua dieta, una volta scelto un menù, può decidere di mangiare o rifiutare un panino; se lo rifiuta il cameriere gli servirà il successivo e quello rifiutato non gli sarà più servito.  
Si deve scrivere un programma che permetta a Poldo, leggendo un menù, di capire qual è il numero massimo di panini che può mangiare per quel menù senza violare la regola della sua dieta.  
Riassumendo, Poldo può mangiare un panino se e solo se soddisfa una delle due condizioni:

- Il panino è il primo che mangia in un determinato pasto;
- Il panino non ha un peso maggiore o uguale all’ultimo panino che ha mangiato in un determinato
    pasto.

## File di input

Il programma deve leggere da un file di nome `input.txt`.
Nella prima riga è presente un intero $N$, il numero di panini nel menù.
Le successive $N$ righe contengono i pesi dei panini,
più precisamente: l'$i$-esima di queste righe contiene il numero intero $p_i$,
il peso dell'$i$-esimo panino presentato a Poldo espresso in grammi.
Poldo non può modificare tale ordine.

## File di output

Il programma deve scrivere in un file di nome `output.txt`.  
La prima riga deve contenere un intero $M$, il numero massimo di panini che Poldo può mangiare.
La seconda ed ultima riga deve contenere una possibile sequenza di $M$ panini che Poldo può mangiare.

## Assunzioni

* $1 \leq N \leq 10\,000$
* $0 \leq p < 10\,000$

## Subtask

- **Subtask 1 [ 5 punti]:** casi di esempio.
- **Subtask 2 [30 punti]:** $N \leq 100$.
- **Subtask 3 [25 punti]:** $N \leq 1000$.
- **Subtask 4 [25 punti]:** $N \leq 3000$.
- **Subtask 5 [15 punti]:** nessuna limitazione specifica.

## Esempio di input/output

| File `input.txt`                          | &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; | File `output.txt` |
| :---------------------------------------- | :----------------------------------------: | :---------------- |
| 5<br>3<br>6<br>7<br>5<br>3                |                   &nbsp;                   | 3<br>6 5  3       |
| &nbsp;                                    |                   &nbsp;                   | &nbsp;            |
| 8<br>0<br>9<br>8<br>5<br>1<br>8<br>4<br>7 |                   &nbsp;                   | 4<br>9 8 5 4      |


## Note
Ci possono essere più sequenze corrette. Nel file di output specificatene una (e una sola) qualsiasi.
