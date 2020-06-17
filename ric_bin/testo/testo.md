# Ricerca binaria (ric\_bin)

## Descrizione del problema

Devi scrivere un programma che indovina un numero naturale da $1$ a $n$. Il tuo programma dovrà contenere una funzione:

```c
void ricerca(long long int n)
```
che, il grader del sistema di valutazione lancerà dopo aver scelto un numero naturale $x$ compreso tra $1$ e $n$. Compito della tua funzione è ricostruire quale sia il numero $x$ a lei incognito raccogliendo informazioni tramite apposite chiamate alla funzione:

```c
int confronto_con(long long int g)
```

che, servita dal grader, ritorna:
- $1$ se $g > x$
- $0$ se $g = x$
- $-1$ se $g < x$

Non appena ha tutti gli elementi necessari per conoscere il numero da indovinare, il tuo programma dovrà consegnare la sua risposta definitiva con una chiamata alla funzione:

```c
void answer(long long int risposta)
```

la partita tra il tuo programma ed il nostro di correzione finisce quì,
  col controllo che 'risposta'='x', ossia che la risposta definitiva prodotta dal tuo algoritmo sia sempre corretta!

## Subtask
- **Subtask 0 [5 punti]**: il numero $x$ da indovinare è 42.
- **Subtask 1 [7 punti]**: non vi è limite sul numero di chiamate a `confronto_con`.
- **Subtask 2 [12 punti]**: vengono consentite solo $n/2$ chiamate a `confronto_con`.
- **Subtask 3 [33 punti]**: viene permesso solo quel minimo numero di chiamate a `confronto_con` che pur di giocare ottimamente consenta sempre, anche se sfortunati (caso peggiore), di individuare il numero misterioso $x$.
- **Subtask 4 [35 punti]**: come sopra, ma l'avversario è ora libero di cambiare il numero che ha in mente in corso di partita, purché rispetti le informazioni già date nel corso della partita.

## Assunzioni
- Il programma termina dopo la prima chiamata alla funzione `answer` oppure allo scadere del tempo limite.
- $1 \leq n \leq 100\,000\,000\,000$

### Cosa deve contenere il File da Sottomettere, e come viene gestito dal server

L'estensione del file che sottometti, *.c, *.cpp oppure *.pas, determina se esso viene compilato col compilatore del C (gcc),
del c++ (g++) oppure del PASCAL (fpc).

Le opzioni di compilazione, specifiche al linguaggio, sono riportate nel dettaglio sulla pagina "Descrizione" del problema in modo che tu possa simulare esattamente in locale cosa succede sul server.

I comandi di compilazione riportati assumono che il nome del file sottomesso (privato di estensione) coincida col nome del problema, tu comunque in locale puoi usare i nomi che preferisci anche se avrà per questo i suoi piccoli vantaggi attenersi a questi.

In questo caso la struttura del file `<nome_problema>.<estensione_linguaggio>` che devi sottomettere è la seguente:

```c
int confronto_con(long long int val);
void answer(long long int risp);

void ricerca(long long int n) {
 // TODO
}
```
Sempre in attachment alla pagina del problema trovi già un _template_ di soluzione parziale già compilabile.:

```c
int confronto_con(long long int val);
void answer(long long int risp);

void ricerca(long long int n) {
  int g = confronto_con(n/2);
  if (g == 0) answer(n/2);
  if (g > 0) answer(1);
  if (g < 0) answer(n);
}
```
Come vedi i template sono purtroppo specifici al linguaggio scelto, e tipicamente noi ne offriamo solo alcuni. Non aspettarti che risolva molte istanze e faccia punti, ma \`e compilabile sia in locale (se nella stessa cartella collocate anche il grader, vedere sotto) che poi sul server. Provare per credere. (Potete sottomettere quante volte volete. Se vi premono i punti sappiate che vale la regola del max.)
Partire dal template ti è comodo in quanto copre per tè gli aspetti più rutinari della programmazione evitando però di spoilerare il problema e la sua soluzione. Sono queste logiche che ti chiediamo di produrre come parte finale del tuo percorso sul problema. Anche quando forniti solo per un altro linguaggio, i template possono comunque aiutarti nel disambiguare i dettagli più tecnici della consegna. Inoltre, partire da essi nell'ottenere il tuo codice rende più probabile che una volta che la tua soluzione gira bene in locale allora girerà senza problemi anche sul server di correzione.

Resta il fatto che ti conviene sempre fare (ed organizzarti) un lavoro di sperimentazione in locale quando metti a punto la tua soluzione, prima di sottometterla. Invece: può avere senso sottomettere una soluzione non pensata per fare tutti (o anche nessuno dei) punti se questo ti aiuta a capire cosa non funziona. Anche a queso servono i casi di prova. L'atteggiamento sperimentale è chiave, ed è esso stesso una competenza preziosa che affinerai con questi problemi.

Nel caso di un problema di natura interattiva come questo, dove il tuo programma interagisce con un ambiente più ampio (il grader, e talvolta anche con delle librerie o degli headers da includere), i comandi di compilazione riportati alla pagina del problema compilano ed assemblano i vari pezzi (il tuo programma, il grader, gli eventuali headers) se avrai collocato questi componenti entro la stessa cartella (in locale ti conviene farti una cartella per problema).

Quando alla pagina del problema ti viene fornito il nostro grader (o la versione semplificata dello stesso) devi scaricartelo in locale entro questa cartella se vuoi testare il comportamento del tutto in locale. Comprendere meglio a cosa servono ti può aiutare nel fare i tuoi test in locale, che è l'approccio corretto col quale andrai lontano. In questo caso tra gli allegati trovi anche un file README.txt che prova a fornire ulteriori chiarimenti proprio su questo punto.
