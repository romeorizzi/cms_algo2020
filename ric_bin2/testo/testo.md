# Ricerca binaria: approfondimenti (ric_bin2)

## Descrizione del problema

Questo problema ha i seguenti obiettivi:

* sbloccare chi di voi sia rimasto in sospeso con l'esercizio ric_bin proposto precedentemente, in particore chiedendo di concentrarti sulla determinazione del minimo numero di chiamate alla funzione guess che sarà sempre sufficiente ad indovinare il numero incognito.

* introdurre alla programmazione dinamica e incoraggiare all'approccio ricorsivo nella soluzione dei problemi.

Devi scrivere un programma che, dato in input un numero intero positivo n,
ritorni il più piccolo numero f(n) tale che esista
una strategia S(n) su come chiamare la funzione guess che garantisca quanto segue:
qualsiasi sia il valore del numero incognito x, con 1 <= x <= n, allora, applicando la strategia S(n), stabilirai il valore di x in al più f(n) domande.

Si noti che una strategia S(n) può essere vista come un albero la cui radice esprime la situazione del gioco prima di aver fatto la prima domanda (la prima chiamata a guess) e le foglie corrispondono alle situazioni in cui il valore di x è infine determinato. Le foglie sono esattamente n, una per ciascuno dei possibili valori di x. Ogni nodo dell'albero S(n) specifica quale sia la domanda che conviene fare (una delle domande ottime, in certi casi potrebbero essere più di una) e, se non è una foglia, ha tre figli, una per ogni possibile risposta della chiamata a guess.

In pratica, quando risolvi questo problema stai implicitamente progettando un tale albero che abbia altezza minima (altezza di un albero è la più lunga distanza di una foglia dalla radice).

Chi vuole risolvere un problema come questo, non disdegna affrontare prima i casi più piccoli:

| n | f(n) |
|---|---|
| 0  | 0 |
| 1  | 0 |
| 2  | 1 |
| 3  | ? |

Sei invitato a proseguire nella compilazione di questa tabella.

*Nota 1:* Sul CMS vi è data la possibilità di fornire voi le istanze sulle quali volete che la vostra sottomissione venga valutata. Questo può consentirvi di risolvere dei vostri dubbi in modo autonomo. Ad esempio quì, se volete ottenere conferma sul valore corretto di f(3) e/o dei successivi, potete sottomettere quella specifica istanza e testare su di essa il vostro algoritmo (o magari un algoritmo più stupido e sicuro che si limiti a stampare la risposta che reputate corretta per quell'istanza).

*Nota 2:* Per altro non vi è vietato, anzi siete incoraggiati, a scambiarvi idee ed aiuto tra di voi, e/o a chiedere a noi (sia  sul Gruppo Telegram che privatamente, come reputate più opportuno). Questo perchè non vorrei fraintendeste il vero messaggio della nota sopra, che mira solo a fornirvi uno strumento in più per gestirvi in ogni situazione e magari anche per andare a scoprire e segnalarci eventuali errori nei nostri materiali, codici, e problemi.

## Due metodologie che se le portate davvero a casa c'è di che essere soddisfatti sull'esito complessivo di tutto il corso

Torniamo al suggerimento di cominciare provando a stabilire uno per uno i valori nella tabella, partendo dai più piccoli (approccio bottom-up).
E' un suggerimento davvero molto importante. Un approccio che dovete fare vostro in questo corso dove miriamo a fare di voi dei problem solvers.

Approccio ricorsivo significa proprio questo: che ad un certo punto cerchi di trovare un modo semplice di mettere in relazione i valori di queste righe, riducendo il problema del computo di f(n) per una certa riga (per un certo n) alla stessa questione già risolta per righe più piccole.
Questo è il grimaldello universale per la soluzione dei problemi nella Concrete Mathematics, ossia in quel ramo della matematica che offre gli sturmenti concettuali ed algoritmici portanti per l'informatica.

La ricorsione viene spesso associata all'approccio visto in rovesciato (approccio top-down), in quanto l'idea è poi quella di trovare il modo di decomporre il problema del computo di f(n) in problemi più piccoli dello stesso tipo (ossia ricompresi nello stesso linguaggio, ossia domande del titpo f(n') ma con n' < n).

Distinguiamo tra due piani: la comprensione della struttura del problema che conduce alla sua soluzione (scoperta del nesso ricorsivo, la chiave d'oro che apre il problema e lo spacca), e come poi questa comprensione strutturale vada sfruttata coniugata in un algoritmo (un metodo generale per la soluzione di quel problema), che in in linea di massima è già un momento successivo che spesso risulta cruciale saper ben separare. (Il momento del progetto dell'implementazione è poi un ulteriore stadio, non stò parlando di questa seconda distinzione anche cruciale ma già secondaria a quella che intendo rimarcare ora.)

Quando per rispondere alla domanda per una certa riga tu dovessi interrogare le risposte per più righe, un algoritmo di tipo ricorsivo (top down) risulterebbe subito inefficiente quando per rispondere ad ogni singola chiamata ne venissero attivate diverse.
Ma nessuno ti vieta di lavorare direttamente su una tale tabella (tabella di programmazione dinamica) entro il tuo algoritmo, determinando i valori riga per riga, una riga alla volta. Questo può farti passare da un algoritmo ricorsivo che richiede tempo esponenziale (farebbe un numero esponenziale di chiamate) ad un algoritmo che effettua solo un numero lineare di chiamate nella magnitudo di n (ossia se n=100 fa al più O(n) chiamate), ossia che và molto veloce e funziona anche in pratica per valori già interessanti di n. (Se la scrittura O(n) ti è arabo devi andare a riguardarti l'uso della notazione asintotica. Per noi algoritmisti è uno degli strumenti base di lavoro.)

E se volessimo poi un algoritmo che gira in tempo polilogaritmico nella magnitudo di n, ossia polinomiale nella lunghezza della codifica binaria (ossia a bits) di n?
Riesci poi a produrre anche questo?


## Esempi

Dalle risposte già riportate nella tabella sopra:

|input from stdin | output to stdout |
|---|---|
|0  | 1 |

|input from stdin | output to stdout |
|---|---|
|2  | 1 |



## Subtask
- **Subtask 1 [10 punti]**: n  <= 5.
- **Subtask 2 [10 punti]**: n  <= 10.
- **Subtask 3 [20 punti]**: n  <= 100.
- **Subtask 12 [20 punti]**: n  <= 1000.
- **Subtask 12 [20 punti]**: n  <= 1.000.000.
- **Subtask 13 [20 punti]**: n  <= 100.000.000.000
