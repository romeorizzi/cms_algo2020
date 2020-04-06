# Ricerca della più lunga sottosequenza comune a due stringhe (lcs)

Una stringa è una sequenza finita di caratteri presi da un qualche alfabeto di riferimento.
Ad esempio, $p=GATTA$ è una stringa sull'alfabeto $\{A,C,G,T\}$, come anche sull'alfabeto $\{A,G,T\}$.
Tuttavia, l'alfabeto impiegato in questo esercizio è quello italiano coi soli caratteri maiuscoli (e non accentati).
Indichiamo con `len`$(p)$ il numero di caratteri della stringa~$p$, in questo caso $5$.
Si noti che la stringa $p$ appare come sottosequenza dentro la stringa $t=TGGTTCAAGTCGTCACA$,
cosa che quì preferiamo mettere in evidenza tramite il seguente riallineamento:

|        ||||||||||||||||||
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
|  stringa testo $t$       |T|*G*|G|T|T|C|*A*|A|G|*T*|C|G|*T*|C|*A*|C|A|
|  prima occorrenza di $p$ in $t$  |-|G|-|-|-|-|A|-|-|T|-|-|T|-|A|-|-|  
|        ||||||||||||||||||


Date due stringhe $t_1$ e $t_2$, ti chiediamo di trovare la massima lunghezza di una stringa pattern $p$ che sia contenuta sia in $t_1$ che in $t_2$.

Implementa il tuo metodo per fare questo entro la seguente funzione:

```
def lcs(t1, t2):  # questa è la funzione che devi perfezionare
    # inserisci quì la tua logica/metodo per risolvere il problema
```

Trovi un template della soluzione nel file `lcs\_template\_sol.py`

Dovrai solo risistemare l'implementazione della funzione richiesta che al momento si limita a ritornare solo e sempre il valore $42$.

## Input (da stdin)
La prima riga di input contiene i due numeri `len`$(t_1)$ `len`$(t_2)$.
La seconda riga di input contiene la stringa $t_1$.
La terza ed ultima riga di input contiene la stringa $t_2$.

## Output (su stdout)
IL tuo programma deve restituire un unico numero naturale:
la massima lunghezza di una stringa $p$ che sia sottosequenza comune a $t_1$ e $t_2$.

**NOTA:** viene fornita una descrizione del formato di input/output soltanto
per facilitarvi il test sul vostro computer. Per sottomettere il problema è obbligatorio
utilizzare il template che potete scaricare fra gli allegati del problema, avendo
cura di modificare solamente l'implementazione delle funzioni richieste. Questo
è necessario per garantire la compatibilità del vostro programma con il sistema
di valutazione, che potrebbe utilizzare una versione di python diversa.

## Esempi di input/output

| input (da stdin) | output (su stdout) |
|---|---|
| 5 5 | 2 |
| AAAAA |  |
| BABAB |  |

| input (da stdin) | output (su stdout) |
|---|---|
| 6 6 | 3 |
| CGCCCT |  |
| CACATC |  |

| input (da stdin) | output (su stdout) |
|---|---|
| 8 10 | 3 |
| CCCCTAAC |  |
| TATCGTGCTT |  |



## Subtasks
- **Subtask 1 [0pt]:** i tre casi di esempio
- **Subtask 2 [25pt]:** `len`$(s)\leq 10$,`len`$(t)\leq 10$
- **Subtask 3 [25pt]:** `len`$(s)\leq 10$,`len`$(t)\leq 1000$
- **Subtask 4 [25pt]:** `len`$(s)\leq 100$,`len`$(t)\leq 100$
- **Subtask 5 [25pt]:** `len`$(s)\leq 1000$,`len`$(t)\leq 1000$
