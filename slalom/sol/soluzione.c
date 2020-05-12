/*
  Questo programma trova il node cover pesato pesato di un albero.
  (la parte per il node cover non pesato e` stata commentata)

  Da controllare.
  Scritto da Flavio.
*/

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>



#define  MaxN   400000

#define min(a, b) ( ((a) <= (b)) ? (a) : (b) )

/* --- */

typedef struct nn {
  int node;
  struct nn *next;
} edge;

/* --- */

void input(FILE *in);
void output(FILE *out);

void eval(int node, int parent);
void choose(int node, int parent);

int readInt(FILE *in);

/* --- */
 
int N;
int *weight;

edge **adj;

int *coverer, *covered;
int *cover;

/* --- */

int main() {
  FILE *in, *out;

#ifdef EVAL
  in = fopen("input.txt", "r");
  out = fopen("output.txt", "w");
#else
  in = stdin;
  out = stdout;
#endif

  input(in);

  cover = (int*) calloc(N+1, sizeof(int));
  coverer = (int*) calloc(N+1, sizeof(int));
  covered = (int*) calloc(N+1, sizeof(int));

  /* Weighted */

  eval(0, 0);
#ifdef DEBUG
  for ( i = 0 ; i < N ; i++ ) 
    fprintf(stderr, "%d %d %d %d %d\n", i + 1, coverer[i], covered[i], weight[i]);
#endif
  choose(0, 0);
  output(out);

  /*
    Non Weighted

  for ( i = 0 ; i < N ; i++ )
    weight[i] = 1;
  
  eval(0, 0);
  choose(0, 0);
  output(out);
  */


  fclose(in);
  fclose(out);

  return 0;
}

void eval(int node, int parent) {
  edge* tmp;

  coverer[node] = weight[node];
  covered[node] = 0;

  for ( tmp = adj[node] ; tmp != NULL ; tmp = tmp->next )
    if ( tmp->node != parent ) {
      eval(tmp->node, node);

      coverer[node] += min(covered[tmp->node], coverer[tmp->node]);
      covered[node] += coverer[tmp->node];
    }
}

void choose(int node, int parent) {
  edge* tmp;

  if ( node == parent )
    /* Root */
    cover[node] = ( coverer[node] < covered[node] );
  else
    cover[node] = ( coverer[node] < covered[node] || !cover[parent] );

  for ( tmp = adj[node] ; tmp != NULL ; tmp = tmp->next )
    if ( tmp->node != parent )
      choose(tmp->node, node);
}

/* --- */

void input(FILE *in) {
  int i, a, b;
  edge* tmp;
  
  N = readInt(in);

  assert( 1 <= N && N <= MaxN );


  weight = (int*) calloc(N+1, sizeof(int));
  for ( i = 0 ; i < N ; i++ )
    weight[i] = readInt(in);

  adj = (edge**) calloc(N+1, sizeof(edge*));
  for ( i = 0 ; i < N - 1 ; i++ ) {
    a = readInt(in) - 1;
    b = readInt(in) - 1;

    tmp = (edge*) malloc(sizeof(edge));
    tmp->node = a;
    tmp->next = adj[b];
    adj[b] = tmp;

    tmp = (edge*) malloc(sizeof(edge));
    tmp->node = b;
    tmp->next = adj[a];
    adj[a] = tmp;
  }
}

int readInt(FILE *in) {
  int tmp;

  if ( fscanf(in, " %d", &tmp) != 1 ) {
    printf("Impossibile leggere l'input.");
    exit(1);
  }

  return tmp;
}

void output(FILE *out) {
  int i, c;

  c = 0;
  for ( i = 0 ; i < N ; i++ )
    if ( cover[i] )
      c++;

  fprintf(out, "%d\n", c);

  for ( i = 0 ; i < N ; i++ )
    if ( cover[i] )
      fprintf(out, "%d ", i + 1);

  fprintf(out, "\n");
}

