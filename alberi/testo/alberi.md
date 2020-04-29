# Alberi (alberi)

## Descrizione del problema

Per gli scopi di questo esercizio, un albero è un albero binario con radice in cui tutti i nodi che non sono foglie hanno esattamente due figli e in cui tutti i nodi (comprese le foglie) sono etichettati con numeri interi non negativi.  
Più precisamente, un albero con _N_ nodi avà i nodi etichettati con i numeri da 1 a _N_ , e nodi diversi hanno etichette diverse.  
Esistono tre modi standard per enumerare le etichette dei nodi di un albero, chiamati visita anticipata, simmetrica e posticipata.  
La versione ricorsiva (in pseudocodice) delle tre visite è la seguente:

```
void anticipata(T: albero);
begin
    if (T è vuoto) return;
    stampa(etichetta di T);
    anticipata(sottoalbero sx di T);
    anticipata(sottoalbero dx di T);
end;
```

```
void simmetrica(T: albero);
begin
    if (T e’ vuoto) return;
    simmetrica(sottoalbero sx di T);
    stampa(etichetta di T);
    simmetrica(sottoalbero dx di T);
end;
```

```
void posticipata(T: albero);
begin
    if (T e’ vuoto) return;
    posticipata(sottoalbero sx di T);
    posticipata(sottoalbero dx di T);
    stampa(etichetta di T);
end;
```

Il problema che dovete risolvere è il seguente: date l eenumerazioni prodotte dalla visite anticipata e posticipata, trovare quella prodotta dalla visita simmetrica.

## Dettagli di implementazione

Dovrai sottoporre un file con estensione.c o .cpp. Questo file deve implementare (in C o C++, rispettivamente) la funzione _visita_ come da seguente prototipo.

```
void visita(int N, int *PRE, int *POST, int *SIMM )

```

Il parametro _N_ è il numero di nodi dell’albero.  
Gli array _PRE_ e _POST_ contengono le permutazioni dei nodi prodotte dalla visita in preordine e postordine, l’array _SIMM_ è da riempire con la permutazione generata invece dalla visita simmetrica.

### Funzionamento del grader di esempio

Nella directory relativa a questo problema è presente una versione semplificata del grader usato durante la correzione, che potete usare per testare le vostre soluzioni in locale. Il grader di esempio legge i dati di input dal file _input.txt_ , a quel punto chiama la funzione _visita_ che dovete implementare, e scrive il risultato restituito dalla vostra funzione sul file _output.txt_ .  
Nel caso vogliate generare un input, il file _input.txt_ deve avere questo formato:

- Prima riga: il numero di nodi _N_.
- Seconda riga: _N_ interi rappresentanti la visita in preordine dell’albero.
- Terza riga: _N_ interi rappresentanti la visita in postordine dell’albero.

## Assunzioni

- 1 ≤ N ≤ 1 000 000.

## Subtask

- **Subtask 1 \[30 punti\]:** _N_ ≤1 000.
- **Subtask 2 \[30 punti\]:** _N_ ≤10 000.
- **Subtask 3 \[30 punti\]:** _N_ ≤100 000.
- **Subtask 4 \[10 punti\]:** nessuna limitazione specifica.

## Esempio di input/output


| File input.txt | &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; | File output.txt |
| :------------  | :----------------------------------: | :-------------- |
| 7<br>5 3 2 1 6 7 4<br>2 6 7 1 3 4 5 |  &nbsp; | 2 3 6 1 7 5 4 |

