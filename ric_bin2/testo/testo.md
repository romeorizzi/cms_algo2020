# Ricerca binaria: approfondimenti (ric_bin2)

## Descrizione del problema

Questo problema ha i seguenti obiettivi:

* sbloccare chi di voi sia rimasto in sospeso con l'esercizio ric_bin proposte precedentemente, in particore chiedendoti di concentrarti sulla determinazione sul minimo numero di chiamate alla funzione guess che sarà sempre sufficiente ad indovinare il numer incognito.

* introdurre alla programmazione dinamica e incoraggiare all'approccio ricorsivo nella soluzione dei problemi.

Devi scrivere un programma che, dato in input $n$,
ritorni il più piccolo numero $f(n)$ tale che esista
una strategia $S$ su come chiamare la funzione guess
che garantisca quanto segue:
qualsiasi sia il valore del numero incognito $x$, con $1\leq x \leq n$, allora, applicando $S$ nel fare le domande, riuscirai a stabilire il valore di $x$ in al più $f(n)$ domande.

Chi vuole risolvere un problema come questo, non disdegna affrontare prima i casi più piccoli:

| n | f(n) |
|---|---|
| 0  | 0 |
| 1  | 0 |
| 2  | 1 |
| 3  | ? |

Sei invitato a proseguire nella compilazione di questa tabella.

*Nota 1:*: Sul CMS vi è data la possibilità di fornire voi leistanze sulle quali volete che la vostra sottomissione venga valutata. Questo può consentirvi di risolvere dei vostri dubbi in modo autonomo. Ad esempio quì, se volete avere verifica sul valore corretto di $f(3)$ e/o dei successivi, potete sottomettere quella specifica istanza e testare su di essa il vostro algoritmo (o magari di un algoritmo più stupido e sicuro che si limiti a stampare la risposta che reputate corretta per quell'istanza).

*Nota 2:* Per altro non vi è vietato, anzi siete incoraggiati, a scambiarvi idee ed aiuto tra di voi, e/o a chiedere a noi (sia  sul Gruppo Telegram che privatamente, come reputate più opportuno). Questo perchè non vorrei fraintendeste il vero messaggio della nota sopra, che mira solo a fornirvi uno strumento in più per gestirvi in ogni situazione e magari anche per andare a scoprire e segnalarci eventuali errori nei nostri materiali, codici, e problemi.

## Due metodologie che se le portate a casa c'è di che essere soddisfatti per tutto il corso

Tornando al suggerimento di cominciare provando a stabilire uno per uno i valori nella tabella, partendo dai più piccoli (approccio bottom-up).

Approccio ricorsivo significa proprio questo: che ad un certo punto cerchi di trovare un modo semplice di mettere in relazione i valori di queste righe, riducendo il problema del computo di $f(n)$ per una certa riga (per un certo $n$) alla stessa questione già risolta per righe più piccole.
Questo è il grimaldello universale per la soluzione dei problemi nella Concrete Mathematics, ossia in quel ramo della matematica che offre gli sturmenti concettuali ed algoritmici portanti per l'informatica.

La ricorsione viene spesso associata all'approccio visto in rovesciato (approccio top-down), in quanto l'idea è poi quella di trovare il modo di decomporre il problema del computo di $f(n)$ in problemi più piccoli dello stesso tipo (ossia ricompresi nello stesso linguaggio, ossia domande del titpo $f(n')$ ma con $n' < n$).

Distinguiamo tra due piani: la comprensione della struttura del problema che conduce alla sua soluzione (scoperta del nesso ricorsivo, la chiave d'oro che apre il problema e lo spacca), e come poi questa comprensione strutturale possa andare a tradursi in un algoritmo, che è già un momento successivo.

Quando per rispondere alla domanda per una certa riga tu dovessi interrogare le risposte per più righe, un algoritmo di tipo ricorsivo (top down) risulterebbe subito inefficiente quando per rispondere ad ogni singola chiamata ne venissero attivate diverse.
Ma nessuno ti vieta di lavorare direttamente su una tale tabella (tabella di programmazione dinamica) entro il tuo algoritmo, determinando i valori riga per riga, una riga alla volta. Questo può farti passare da un algoritmo ricorsico che richeide tempo esponenziale (facendo un numero esponenziale di chiamate) ad un algoritmo che effettua solo un numero lineare di chiamate nella magnitudo di $n$, ossia che và molto veloce e funziona anche in pratica per valori già interessanti di $n$.

E se volessimo poi un algoritmo che gira in tempo polilogaritmico nella magnitudo di $n$, ossia polinomiale nella lunghezza della codifica binaria (ossia a bits) di $n$?
Riesci poi a produrre anche questo?




|input from stdin | output to stdout |
|---|---|
|3  | 0 |
|1 3 2 | |



## Subtask
- **Subtask 1 [10 punti]**: $n \leq 5$.
- **Subtask 2 [10 punti]**: $n \leq 10$.
- **Subtask 3 [20 punti]**: $n \leq 100$.
- **Subtask 12 [20 punti]**: $n \leq 1000$.
- **Subtask 12 [20 punti]**: $n \leq 1.000.000$.
- **Subtask 13 [20 punti]**: $n \leq 100.000.000.000$
