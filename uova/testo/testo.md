# Uova di Pasqua (uova)

## Descrizione del problema

Mi hanno chiesto una consulenza agli LindtRobustEggs' Headquarters, un palazzone modernissimo di $n = 100$ piani in vetro e acciaio.
Nel prossimo spot pubblicitario su una nuova linea di uova di Pasqua che (forse all'inizio anche per sbaglio) gli sono uscite super-resistenti, vorrebbero far cadere delle uova da una delle finestre del palazzo. Sono convinti che il video diventerà virale e che il prodotto andrà poi a ruba. Mi hanno chiesto di stabilire quale sia l'altezza massima del piano da cui far cadere le uova in modo da non romperle. Le assunzioni e belief di chi mi ha impartito la consegna sono:
 1. gli esiti possibili di un lancio sono solo due: uovo che si rompe, uovo che resta perfettamente intero, come nuovo;
 2. le uova sono tutte perfettamente identiche ed il comportamento osservato dipende solo dal piano di lancio, gli altri fattori aleatori non riescono ad influire;
 3. se l'uovo si rompe quando lanciato dal piano $n'$ nel range $[1,n-1]$ allora si sarebbe rotto anche quando lanciato dal piano $n'+1$. Ogni uovo si romperà sicuramente quando lanciato dal piano $n'$ o superiore (l'ho ridetta più naturale, scusate la ripetizione).

Purtroppo ho solo $k = 2$ uova con cui condurre questa campagna di test, e, quando un uovo dovesse rompersi me lo sono giocato: non posso farne più nulla (se non mangiarmelo).
Sono interessato a minimizzare il numero di lanci per venire a conoscere quello che in gergo, alla LindtRobustEggs, viene chiamato il piano critico di rottura.


Questo problema ha i seguenti obiettivi:

* incoraggiare all'approccio ricorsivo nella soluzione dei problemi. E' l'approccio più generale che abbiamo nel risolvere i problemi di stampo matematico, definisce da fuori i confini della decidibilità (ossia dell'informatica) e governa quindi anche le situazioni di complessità subito proibitiva quali i giochi. Hint: dato che è il mistero ricorsivo del problema che và innanzitutto svelato, converrà allora vederlo come un gioco a 2 giocatori adottando da subito una prospettiva potente e fedele per mapparselo.  

* introdurre alla programmazione dinamica, ossia al progettare una famiglia di domande che cadano come i birilli, da quelle più piccole via via alle più grandi (bottom-up). Sia per costruire le intuizioni e scoperte con le mani sia per pervenire infine a metodi efficienti nell'impiego delle risorse computazionali.

Chi vuole risolvere un problema come questo, non disdegna affrontare prima i casi più piccoli:

| n | f(n) |
|---|---|
| 1  | 1 |
| 2  | 2 |
| 3  | 2 |
| 4  | ? |

Sei invitato a proseguire nella compilazione di questa tabella. In realtà sarebbe forse più proprio chiamarla vettore, ma quando poi passerai a studiare il caso di $k$ generico spunterà una seconda dimensione e sarà a tutti gli effetti una tabella. Ma il consiglio metodologico se davvero __vuoi fare__ matematica e/o informatica, parti prima con il caso $k = 2$.

*Nota 1:*: Sul CMS vi è data la possibilità di fornire voi le istanze sulle quali volete che la vostra sottomissione venga valutata. Questo può consentirvi di risolvere dei vostri dubbi in modo autonomo. Ad esempio quì, se volete ottenere conferma sul valore corretto di $f(4)$ e/o dei successivi, potete sottomettere quella specifica istanza e testare su di essa il vostro algoritmo (o magari un algoritmo più stupido e sicuro che si limiti a stampare la risposta che reputate corretta per quell'istanza).

*Nota 2:* Per altro non vi è vietato, anzi siete incoraggiati, a scambiarvi idee ed aiuto tra di voi, e/o a chiedere a noi (sia  sul Gruppo Telegram che privatamente, come reputate più opportuno).

## Due metodologie che se le portate a casa c'è di che essere soddisfatti per tutto il corso

Inutile che le ripeto quì, ne abbiamo parlato nel problema ric_bin2. Essendo metodologie generali sono poi sempre le stesse. Fatele vostre (serve anche il praticarle) ed avrete la competenza attiva, quello che vorremo riuscire a trasmettervi con questo corso.

## Esempi

Dalle risposte già riportate nella tabella sopra:

|input from stdin | output to stdout |
|----|---|
|2  1| 1 |

|input from stdin | output to stdout |
|----|---|
|2  2| 2 |

## Subtask
- **Subtask 1 [10 punti]:** $k = 2$, $n \leq 5$.
- **Subtask 2 [10 punti]:** $k = 2$, $n \leq 10$.
- **Subtask 3 [10 punti]:** $k = 2$, $n \leq 100$.
- **Subtask 4 [10 punti]:** $k = 2$, $n \leq 1000$.
- **Subtask 5 [10 punti]:** $k = 2$, $n \leq 1\,000\,000$.
- **Subtask 6 [10 punti]:** $k \leq 10$, $n \leq 5$.
- **Subtask 7 [10 punti]:** $k \leq 10$, $n \leq 10$.
- **Subtask 8 [10 punti]:** $k \leq 10$, $n \leq 100$.
- **Subtask 9 [10 punti]:** $k \leq 10$, $n \leq 1000$.
- **Subtask 10 [10 punti]:** $k \leq 10$, $n \leq 1\,000\,000$.
