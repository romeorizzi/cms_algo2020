# Chococroch

Tu ed un tuo amico avete appena comprato su Amazon® una stecca di cioccolato, e dovete decidere come spartirla. 
Per evitare omicidi, decideten di procedere nel seguente modo: ognuno a turno spezza a metà la stecca di cioccolato, 
e può tenere solamente la parte più piccola delle due. 

Evidentemente si procederà in questo modo fino a che non rimarrà l'ultimo pezzo, unitario, non più divisibile. 
Ovviamente nessuno dei due vuole accollarsi l'onere di mangiare il pezzo della vergogna, pertanto vorrà fare
di tutto per lasciarlo all'avversario. 

Dovrai quindi trovare una strategia in grado di lasciare l'ultimo pezzo all'avversario, se questo è possibile. 
Altrimenti dovrai rassegnarti all'idea di essere stato fregato. 

### Funzioni
Dovrai implementare le seguenti funzioni.

#### win\_from

<description for="win_from">
La funzione riceverà in input due parametri:
- <param>n</param> la lunghezza della stecca
- <param>m</param> l'altezza della stecca

Dovrà restituire un booleano: vero se esiste una mossa vincente, falso altrimenti
</description>

Nel caso si risponda affermativamente alla precedente domanda, verranno chiamate le seguenti ulteriori funzioni.

#### cut\_direction

<description for="cut_direction">
La funzione prende i parametri m e n di prima. Essa deve restituire 1 se è necessario tagliare in verticale, 0 se in orizzontale
</description>

#### eat\_size

<description for="eat_size">
Deve restituire la distanza in termini di quadrati (verticalmente o orizzontalmente in base a quanto indicato precedentemente) 
dal punto (m, n) al bordo che viene tagliato.   
</description>
