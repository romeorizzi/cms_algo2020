# io_file
## Gestire input ed output da file

Ricevete in input un numero intero e,
in output, dovete ritornare lo stesso identico numero. Nessuna elaborazione è richiesta (è un esercizio di test ed acclimatamento).

Mi spiego meglio:
nella stessa cartella in cui il vostro programma verrà messo in esecuzione
si trova un file di testo di nome `input.txt`.
In questo file è scritto solamente un intero.
Voi dovete creare un file di testo di nome `output.txt`
e ricopiarci dentro lo stesso identico valore intero.
In pratica, col file `output.txt`,
creerete una copia del file `input.txt`.


### Esempi
|input|output|
|-----|------|
| `17`| `17` |

### Assunzioni
- il numero intero in questione ha valore assoluto al massimo $1000$, può quindi essere convenientemete memorizzato nelle
 usuali variabili offerte dal tuo linguaggio di programmazione preferito (come le variabili di tipo `int` del C o
 C++, oppure quelle di tipo integer in Pascal).

### Subtask
- **Subtask 1 [30 punti]**: il tuo programma deve risolvere correttamente il caso d'esempio del testo (non vi serve nemmeno leggere l'input).
- **Subtask 2 [30 punti]**: il numero fornito in input è $13$.
- **Subtask 3 [40 punti]**: nessuna restrizione (oltre quella sul valore assoluto espressa nella sezione di "Assunzioni" generali).

#### Note generali sul sistema di sottoposizione (con valutazione a feedback immediato) delle vostre soluzioni

Al sistema di sottoposizione va sottomesso solo il file sorgente del vostro programma. Il nostro server compiler\`a tale sorgente avvalendosi del compilatore
suggerito dall'estensione del file da voi sottomesso.

| linguaggio adottato | estensione file sottomesso | compilatore/interprete utilizzato dal server
|-|-|-|
| python  | .py  | python3
| bash    | .sh  | bash
| C++     | .cpp | g++
| C       | .c   | gcc
| Pascal  | .pas | fpc

Consigliamo di testare la soluzione in locale prima di sottometterla.
Se riscontrate difformità di comportamento tra quanto in locale a quanto sul server, le esatte opzioni di compilazione utilizzate dal server sul singolo problema sono riportate nella pagina del problema sul sito.
