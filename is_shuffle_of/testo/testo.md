# Can a deck of cards be obtained as the shuffle of two? (is\_shuffle\_of)

Date due liste totalmente ordinate $L_1$ ed $L_2$, rispettivamente di $|L_1|$ ed $|L_2|$ elementi, un loro _shuffle_ è una qualsiasi lista $S$ di $|L_1|+|L_2|$ elementi dove ogni elemento di $L_1$ o $L_2$ ha trovato il suo posto. Deve però essere rispettato l'ordine entro le due liste di provenienza:
per $i=1,2$, se da $S$ tolgo gli $|L_i|$ elementi provenuti da $L_i$, allora ritrovo la lista $L_{3-i}$.
Le due concatenazioni $L_1+L_2$ e $L_2+L_1$ sono pertanto due casi molto particolari di shuffle ma, a differenza dell'operatore di concatenazione, quello di shuffle è non-deterministico e simmetrico.  
Ma cerchiamo ora di chiarire il concetto attraverso un esempio:

**shuffle:** partendo da due mazzi di carte, l’operazione di shuffle compone un unico mazzo inframmezzando le carte dei due in un unico ordine.  
Di solito viene eseguita ponendo i due mazzi a faccia in giù sul tavolo verde, avvicinando due angoli dei mazzi fino a toccarsi ed aderendovi coi pollici, scorrendo quindi i pollici verso l’alto (come a far frusciare dollaroni) facendo in modo che le carte dei due mazzi, ricadendo in basso, si inframmezzino a pettine.


Ad esempio, partendo dai due mazzi:

```
Mazzo x : 7, 2, K
Mazzo y : K, 7, 2, 7
```

Alcuni possibili shuffle di $x$ ed $y$ sono:

- 7, 2, K, K, 7, 2, 7 (semplice concatenazione)
- 7, 2, K, 7, K, 2, 7 (unico shuffle palindromo?)
- 7, 2, K, 7, 2, K, 7 (anche il 2 scavalca il K)


... ohi, ohi, le possibilità andranno a crescere in modo esponenziale, ma ora provo a formalizzare il
concetto:  
data una sequenza $x$ (il primo mazzo) di $m$ numeri naturali $x_ 1,\ldots , x_m$ ed una sequenza $y$ (il secondo mazzo) di $n$ numeri naturali $y_ 1,\ldots ,y_n$, ed una sequenza binaria $b$ di $m + n$ bits di non-determinismo, potremmo definire _lo shuffle di $x$ ed $y$ dettato da $b$_ come quella stringa $w$ di lunghezza $m + n$ tale che  

```
       ┌
       | x[t - num_ones(bₜ)] if b[t] = 0
w[t] = |
       | y[t - num_zeros(bₜ)] if b[t] = 1
       └
```

dove abbiamo indicato con $b_t$ il prefisso di $b$ di lunghezza $t$, mentre le funzioni `num_ones(·)` e `num_zeros(·)` ritornano, rispettivamente, il numero di uni e di zeri entro la stringa binaria presa ad argomento.  

Definito cosa sia lo shuffle, eccovi il problema:  

> &nbsp; il crupier doveva fare lo shuffle di due mazzi a me noti, $x$ ed $y$, e dice di aver prodotto un
mazzo $w$. Dice la verità o è un baro?  
E se dice la verità, sapresti offrire una spiegazione di come sia potuto succedere specificando
una stringa binaria $b$ tale che $w$ sia lo shuffle di $x$ ed $y$ dettato da $b$?


## Dati di input

La prima riga del file `input.txt` contiene tre numeri interi e positivi: $m$, $n$, e $t$, come nell’ordine, dove $t\in \{0,1\}$ precisa  il tipo di output desiderato.  
La seconda (terza, quarta; rispettivamente) riga contiene $m$ ($n$, $m+n$; rispettivamente) numeri naturali l'$i$-esimo dei quali è $x[i]$ ($y[i]$, $w[i]$; rispettivamente).
Ovviamente, tutti i numeri sulla riga sono separati da spazi.


## Dati di output

Nella prima riga del file `output.txt` si scriva un unico numero: $1$ se $w$ può essere ottenuto come shuffle di $x$ e di $y$, altrimenti $0$.  
Se $t = 0$ il file non deve contenere ulteriori righe. Se $t = 1$ ed il numero scritto nella prima riga del file `output.txt` è anche esso un $1$, allora, nella seconda ed ultima riga del file `output.txt` si riportino, separati da spazi, gli $m + n$ bits della sequenza $b$ lessicograficamente minima tale che $w$ è lo shuffle di $x$ ed $y$ dettato da $b$.

## Esempio di input/output

| File input.txt | &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; | File output.txt |
| :------------  | :----------------------------------: | :-------------- |
| 3 4 0<br>7 2 13<br>13 7 2 7<br>13 7 7 2 2 7 13 | &nbsp; | 1 |
| &nbsp; | &nbsp; | &nbsp; |
| 3 4 1<br>7 2 13<br>13 7 2 7<br>13 7 2 7 2 7 13 | &nbsp; | 1<br>1 0 0 1 1 1 0 |
| &nbsp; | &nbsp; | &nbsp; |
| 3 4 1<br>7 2 13<br>13 7 2 7<br>13 7 7 7 2 2 13 | &nbsp; | 0 |

## Assunzioni

- $m,n \leq 1000$, i numeri nelle sequenze sono interi nell’intervallo $[0 , 10 000]$.

## Subtask

- **Subtask 1 \[0 punti\]:** i tre esempi del testo.
- **Subtask 2 \[20 punti\]:** $m + n \leq 20$, tipo $0$.
- **Subtask 3 \[10 punti\]:** $m + n \leq 20$, tipo $1$.
- **Subtask 4 \[20 punti\]:** $x = 0^m$ ossia la prima sequenza contiene solo zeri, tipo $0$.
- **Subtask 5 \[10 punti\]:** $x = 0^m$ ossia la prima sequenza contiene solo zeri, tipo $1$.
- **Subtask 6 \[25 punti\]:** $m,n \leq 1000$, tipo $0$.
- **Subtask 7 \[15 punti\]:** $m,n \leq 1000$, tipo $1$.
