# Indovina il codice segreto! (mastermind)

## Descrizione del problema

Immaginati nelle vesti di un “decodificatore”. Il tuo avversario, un “codificatore”, ha scritto un codice segreto di quattro cifre, ognuna delle quali può assumere un valore tra 0 e 5.  
Per sconfiggere il tuo avversario, devi scrivere una procedura che individui il suo codice segreto, effettuando il minor numero di tentativi. Il file da sottomettere deve avere la seguente struttura:

```
#include "ourLibToPlay.h"

void solve() {
   ...
}
```

Durante la fase di gioco, per capire quanto il tuo codice si avvicina a quello del tuo avversario, potrai servirti della seguente funzione:

```
void checkCode(int attempt[ ], int result[ ])
```

La funzione _checkCode_ richiede in input:

- l’array _attempt_ \[ \] di quattro cifre contenente il codice da te proposto;
- un array _result_ \[ \] di due elementi in cui verrà salvato il risultato.

Il primo elemento di _result_ \[ \] indica il **numero di cifre giuste al posto giusto** che hai indovinato, mentre il secondo elemento di _result_ \[ \] indica **il numero di cifre giuste al posto sbagliato** che hai indovinato, ovvero quelle cifre che sono presenti nel codice del tuo avversario, ma non nella posizione da te proposta.

Ricorda che il tentativo che ti porta alla soluzione corretta, ovvero a scoprire il codice del tuo avversario,  **NON** è conteggiato nel massimo numero di tentativi a tua disposizione. Ad esempio, se per scoprire il codice del tuo avversario hai 10 tentativi, significa che puoi indovinare fino a 10 codici **errati** prima di arrivare alla soluzione corretta.

Vi sono diversi subtask, divisi a seconda del numero massimo di tentativi a tua disposizione.

Una volta individuato senza alcun margine di dubbio il codice del tuo avversario, devi consegnarlo invocando la funzione:

```
void pensoCheCodiceSia(int risposta [ ])
```

dove l’array _risposta_ \[ \] contiene il codice di Alice da te scoperto.

## Subtask

- **Subtask 0 \[20 punti\]:** nessuna limitazione sul numero di tentativi.
- **Subtask 1 \[40 punti\]:** hai a disposizione al più 10 tentativi.
- **Subtask 2 \[40 punti\]:** hai a disposizione al più 6 tentativi.

## Assunzioni

- Il programma termina dopo la prima chiamata alla funzione _pensoCheCodiceSia_ oppure allo scadere
    del tempo limite.
- Tempo Limite: 1 sec.
- Spazio Limite: 256 MB.

## Cosa deve contenere il File da Sottomettere, e come viene gestito dal server

L’estensione del file che sottometti, \*.c oppure \*.cpp, determina se esso viene compilato col compilatore del C (gcc) oppure del C++ (g++).  
Le opzioni di compilazione, specifiche al linguaggio, sono riportate nel dettaglio sulla pagina "Descrizione" del problema in modo che tu possa simulare esattamente in locale cosa succede sul server. I comandi di compilazione riportati assumono che il nome del file sottomesso (privato di estensione) coincida col nome del problema.  
Nel caso di un problema interattivo come questo, dove il tuo programma interagisce con altri da noi predisposti (il grader ed anche un header da includere), i comandi di compilazione riportati compilano ed assemblano i vari pezzi (il tuo programma, il grader, e l’header). Se vuoi testare il comportamento del tutto in locale, devi allora scaricarti il nostro grader e l’header che rendiamo disponibile tra gli allegati alla pagina del problema.  
Tra gli allegati potremmo inoltre fornire una soluzione di esempio che, pur essendo compilabile sia in locale che dal server (ove ad esso sottomessa), faccia pochi o nessun punto in quanto non significativa per il problema in questione.  
In questo caso l’esempio compilabile reso disponibile al sito è il seguente:

```
// problem: mastermind, example of a dumb solution file

#include "ourLibToPlay.h"

void solve(){
    int sol[4] = {1, 4, 5, 0};
    int res[2];
    checkCode(sol, res);
    if(res[0]==4){
        pensoCheCodiceSia(sol);
    } else {
        sol[0] = 1; sol[1] = 2; sol[2] = 3; sol[3] = 4;
        pensoCheCodiceSia(sol);
    }
}
```

Ovviamente questa soluzione di esempio non risolverà molte istanze ma spero serva ad illustrare come potete muovervi ed è comunque compilabile sia in locale (se nella stessa cartella collocate anche il grader e l’header resi disponibili alla pagina del problema) sia ove sottoposta al server.


