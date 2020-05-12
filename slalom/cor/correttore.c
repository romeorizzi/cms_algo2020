/*
  Correttore per Slalom
  Flavio
*/
#include <stdio.h>
#include <stdlib.h>

#define INVALIDCOVER -1
#define INVALIDLIST -2

#define min(a, b) ( ((a) <= (b)) ? (a) : (b) )

typedef struct {
  int a, b;
} edge;

/* --- */

void readInput(FILE *in);
int readInt(FILE *in);


/*
  >= 0  answer e` un node cover ed il suo valore e` restituito
  == NOCOVER (-1)  answer non e` un node cover
  == INVALIDLIST (-2)  answer non contiene (all'offset in cui e`) una valida lista di nodi distinti
*/
int readCoverValue(FILE *answer);

/*
  1  se il test cover e` ottimo
  0  se il test cover non e` un cover ottimo
 -1  se il test cover non e` un cover

  getScore puo` terminare questo correttore se la lista del test cover non e` valida (punteggio 0)
*/
int getScore(char *kind, FILE *correct, FILE *test);

void ex(char *msg, float res);

/* --- */
 
int n;
int *weight, *cover;

edge *edges;

/* --- */

int main(int argc, char *argv[]) {
  FILE *input, *correct, *test;
  int i;
  int weightScore, cardinalityScore;

  char buffer[1000];

  if (argc < 4) {
    printf("Uso: %s <input> <correct output> <test output>\n", argv[0]);
    exit(1);
  }

  input = fopen(argv[1], "r");
  correct = fopen(argv[2], "r");
  test = fopen(argv[3], "r");

  if ( input == NULL || correct == NULL ) {
    printf("Impossibile aprire %s o %s.\n", argv[1], argv[2]);
    exit(1);
  }

  if ( test == NULL )
    ex("Impossibile aprire il file output.txt generato dal codice sottoposto al sistema.", 0.0);

  /* Leggiamo l'input */
  
  readInput(input);

  /* Valutiamo il cover pesato */
  weightScore = getScore("pesato", correct, test);

  if ( weightScore == 1 )
    ex("Risposta corretta.", 1.0);
  else if ( weightScore == 0 )
    ex("Il costo totale degli snodi selezionati non e` minimo (nel file output.txt generato dal codice sottoposto al sistema).", 0.0);
  else
    ex("Gli snodi selezionati (nel file output.txt generato dal codice sottoposto al sistema) non garantiscono la copertura televisiva di tutti i tratti della pista.", 0.0);

  /*
  for ( i = 0 ; i < n ; i++ )
    weight[i] = 1;
  cardinalityScore = getScore("di cardinalita`", correct, test);

  sprintf(buffer, "La versione pesata %s. La versione non pesata %s.",
	  (weightScore == 1) ? "e` ottima" : ((weightScore == 0) ? "non e` ottima" : "non copre l'albero"),
	  (cardinalityScore == 1) ? "e` ottima" : ((cardinalityScore == 0) ? "non e` ottima" : "non copre l'albero"));

  if ( weightScore == 1 && cardinalityScore == 1 )
    ex(buffer, 1.0);
  else if ( weightScore == 1 && cardinalityScore != 1 )
    ex(buffer, 0.5);
  else if ( weightScore != 1 && cardinalityScore == 1 )
    ex(buffer, 0.5);
  else
    ex(buffer, 0.0);
  */

  return 0;
}

int getScore(char *kind, FILE *correct, FILE *test) {
  int correctValue, testValue;
  char buffer[1000];

  correctValue = readCoverValue(correct);
  if ( correctValue == INVALIDCOVER ) {
    printf("Il node cover %s del file di output corretto non e` un node cover!\n", kind);
    exit(1);
  } else if ( correctValue == INVALIDLIST ) {
    printf("Impossibile leggere il node cover %s del file di output corretto!\n", kind);
    exit(1);
  }

  testValue = readCoverValue(test);
  if ( testValue == INVALIDCOVER )
    return -1; 
  else if ( testValue == INVALIDLIST ) {
    sprintf(buffer, "Impossibile leggere gli snodi della copertura %s (nel file output.txt generato dal codice sottoposto al sistema).", kind);
    ex(buffer, 0.0);
  } else if ( testValue < correctValue ) {
    printf("Il node cover %s di test e` migliore di quello corretto!\n", kind);
    exit(1);
  } else if ( testValue == correctValue )
    return 1;
  else
    return 0;
}

void ex(char *msg, float res) {
   if ( msg )
     fprintf(stderr, "[\x1b[1m\x1b[31m%s\x1b[m] ", msg);

   printf("%f\n", res);
   exit(0);
}

int readCoverValue(FILE *answer) {
  int total;
  int i, m, a;

  for ( i = 0 ; i < n ; i++ )
    cover[i] = 0;

  if ( fscanf(answer, " %d", &m) != 1 || m < 0 || m > n )
    /* Non abbiamo letto una valida lunghezza della lista */ 
    return INVALIDLIST;

  total = 0;

  for ( i = 0 ; i < m ; i++ ) {
    if ( fscanf(answer, " %d", &a) != 1 || a < 1 || a > n )
      /* Non abbiamo letto un identificatore valido */
      return INVALIDLIST;

    a--;
    
    if ( cover[a] )
      /* Un nodo non puo` essere ripetuto nella lista */
      return INVALIDLIST;

    cover[a] = 1;
    total += weight[a];
  }

  for ( i = 0 ; i < n - 1 ; i++ )
    if ( ! (cover[ edges[i].a ] || cover[ edges[i].b ]) )
      /* Un arco non e` coperto: questo non e` un node cover */
      return INVALIDCOVER;

  return total;
}

void readInput(FILE *in) {
  int i, a, b;
  edge* tmp;
  
  n = readInt(in);

  weight = (int*) calloc(n, sizeof(int));
  for ( i = 0 ; i < n ; i++ )
    weight[i] = readInt(in);

  edges = (edge*) calloc(n - 1, sizeof(edge));
  for ( i = 0 ; i < n - 1 ; i++ ) {
    edges[i].a = readInt(in) - 1;
    edges[i].b = readInt(in) - 1;
  }

  cover = (int*) calloc(n, sizeof(int));
}

int readInt(FILE *in) {
  int tmp;

  if ( fscanf(in, " %d", &tmp) != 1 ) {
    printf("Impossibile leggere l'input.\n");
    exit(1);
  }

  return tmp;
}
