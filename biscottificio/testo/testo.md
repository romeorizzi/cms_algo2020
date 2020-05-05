# Biscottificio Biscogusto (biscottificio)

## Descrizione del problema
Il biscottificio Biscogusto produce biscotti ripieni di $10$ diverse varietà di creme.
I vari gusti dei riempimenti dei biscotti si ottengono mescolando in quantità diverse Cioccolato, Panna e Marmellata secondo questa tabella

|  Riempimento   | Codice | #Cioccolato | #Panna | #Marmellata |
| :------------: | :----: | :---------: | :----: | :---------: |
|  Superciocco   |   0    |      3      |   0    |      0      |
|  Cioccoblank   |   1    |      2      |   1    |      0      |
|     Sacher     |   2    |      2      |   0    |      1      |
|   Purapanna    |   3    |      0      |   3    |      0      |
|   Pannaciok    |   4    |      1      |   2    |      0      |
|    Dolcepiu    |   5    |      0      |   2    |      1      |
|   Marmellata   |   6    |      0      |   0    |      3      |
|   MarmeCacao   |   7    |      1      |   0    |      2      |
| MarmellataSoft |   8    |      0      |   1    |      2      |
| GustoMiscuglio |   9    |      1      |   1    |      1      |

L'ordine degli ingredienti non è importante:
ciò che conta sono solo le loro quantità.

Il contenitore dell'impastatrice viene riempito tramite 3 tubi i quali vengono via via collegati ai serbatoi di Cioccolato, Panna o Marmellata in base alla necessità.
Se per esempio si vuole produrre il gusto MarmellataSoft si dovrà collegare un tubo al serbatoio della Panna e 2 a quello della Marmellata (perchè MarmellataSoft è 2 parti marmellata 1 parte panna).

Normalmente la gestione della produzione è totalmente automatizzata, ma purtroppo l'altro giorno si è guastata la centralina.  
Il povero dipendente Mario deve quindi programmare l'intera produzione dei lotti dei riempimenti dei biscotti manualmente.  
Per farlo Mario ha a disposizione un piccolo schermo e 4 pulsanti con le seguenti funzioni:

- aggiungere Cioccolata alla ricetta
- aggiungere Panna alla ricetta
- aggiungere Marmellata alla ricetta
- aggiungi ricetta corrente alla pianificazione

Il computer della produzione memorizza in un buffer circolare solo gli ultimi 3 ingredienti aggiunti.  
Quindi se per esempio gli ultimi 3 ingredienti aggiunti sono stati (in ordine cronologico da sx verso dx)

```
C P P
```

e si vuole aggiungere alla produzione il riempimento Superciocco (CCC), dovremo necessariamente premere almeno 3 volte il pulsante C (cioccolato) secondo questa sequenza:

```
C P P (gli ingredienti in quel momento selezionati)
P P C (aggiungendo Cioccolato)
P C C (aggiungendo Cioccolato)
C C C (aggiungendo Cioccolato)
```
e poi premere il pulsante per aggiungere la ricetta alla pianificazione.

Aggiungere una ricetta **non** svuota il buffer. Quindi se volessimo aggiungere un ulteriore lotto di Superciocco alla pianificazione basterebbe adesso premere nuovamente il pulsante per aggiungere la ricetta.

Ovviamente Mario vorrebbe finire il prima possibile quindi si chiede quale sia il **numero minimo di pulsanti che deve premere per completare la pianificazione della produzione**.

## File di input

Il programma deve leggere da un file di nome `input.txt`.  
Nella prima riga è presente un intero $N$, il numero di lotti di riempimento da produrre.  
Le successive $N$ righe contengono il codice $C$ del riempimento da produrre.  
L'ordine di produzione va rispettato.

## File di output

Il programma deve scrivere in un file di nome `output.txt`.  
file deve contenere un unico intero, il numero minimo di pulsanti che Mario dovrà premere per completare l'intera pianificazione.


## Assunzioni

* $1 \leq N \leq 1000\, 000$
* $0 \leq C \leq 9$
* Il "buffer" del computer dell'azienda è inizialmente vuoto

## Subtask

- **Subtask 1 [ 5 punti]:** casi di esempio.
- **Subtask 2 [30 punti]:** $N \leq 100$.
- **Subtask 3 [25 punti]:** $N \leq 1000$.
- **Subtask 4 [25 punti]:** $N \leq 100\,000$.
- **Subtask 5 [15 punti]:** nessuna limitazione specifica.


## Esempio di input/output

| File `input.txt`                          | &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; | File `output.txt` |
| :---------------------------------------- | :----------------------------------------: | :---------------- |
| 5<br>3<br>6<br>7<br>5<br>3                |                   &nbsp;                   | 16                |
| &nbsp;                                    |                   &nbsp;                   | &nbsp;            |
| 8<br>0<br>9<br>8<br>5<br>1<br>8<br>4<br>7 |                   &nbsp;                   | 24                |

## Note
Indicando con $C$ il pulsante del cioccolato, $M$ quello della marmellata, $P$ quello della panna e infine con $L$ il pulsante di conferma,
nel primo esempio il risultato $16$ si potrebbe ottenere così:

```
PPPL MMML CL MPPL PL
```

Nel secondo esempio il risultato $24$ si potrebbe ottenere così:

```
CCCL MPL ML PL CCL MMPL PCL MML
```
