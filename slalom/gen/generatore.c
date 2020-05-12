/*
  Generatore per il node cover.

  uso: ./generatore [numero nodi] [seed]

  Il generatore funziona cosi`:

  1 stampa dei pesi a caso tra MIN_WEIGHT e MAX_WEIGHT
  2 mette la radice
  3 se non ci sono abbastanza nodi nell'albero
  4   sceglie uniformemente a caso un nodo dell'albero
  5   attacca un nuovo nodo al nodo scelto in 3
  6 "mischia" le etichette dei nodi 
  7 stampa gli archi dell'albero

  Da controllare.
  Scritto da Flavio.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int a, b;
} edge;

#define MIN_WEIGHT 1
#define MAX_WEIGHT 100

int *parent;
int *weight;
int *permutation;
edge *edges;

int n, tipo;
unsigned int seed;

int cmp(const void *x, const void *y);

int main(int argc, char **argv) {
  int i, j;
  int tmp;

  if ( argc < 4 || sscanf(argv[1], " %d", &tipo) != 1 || sscanf(argv[2], " %d", &n) != 1 || sscanf(argv[3], " %u", &seed) != 1 ) {
    fprintf(stderr, "%s [tipo] [numero nodi] [seed]\n", argv[0]);
    return 1;
  }

  if (tipo == 0) {
    printf("5\n1 2 1 1 1\n4 2\n1 2\n3 2\n5 4\n");
    return 0;
  }
  srand( seed );

  /* --- */

  if ( n == 0 ) {
    printf("0\n");
    return 0;
  }

  printf("%d\n", n);

  /* --- */

  parent = (int*) calloc (n, sizeof(int));
  weight = (int*) calloc (n, sizeof(int));
  permutation = (int*) calloc (n, sizeof(int));
  edges = (edge*) calloc (n, sizeof(edge));

  /* --- */

  for ( i = 0 ; i < n ; i++ )
    weight[i] = rand() % (MAX_WEIGHT - MIN_WEIGHT + 1) + MIN_WEIGHT;

  for ( i = 0 ; i < n ; i++ )
    printf("%d ", weight[i]);
  printf("\n");

  /* --- */ 

  parent[0] = 0;
  for ( i = 1 ; i < n ; i++ )
    parent[i] = rand() % i;

  for ( i = 0 ; i < n ; i++ )
    permutation[i] = i;

  for ( i = 0 ; i < n ; i++ ) {
    j = rand() % (n - i) + i;
    tmp = permutation[i];
    permutation[i] = permutation[j];
    permutation[j] = tmp;
  }

  /* --- */

  for ( i = 0 ; i < n ; i++ ) {
    edges[i].a = permutation[ i ];
    edges[i].b = permutation[ parent[i] ];

    if ( edges[i].b < edges[i].a ) {
      tmp = edges[i].a;
      edges[i].a = edges[i].b;
      edges[i].b = tmp;
    }
  }

  qsort(edges, n, sizeof(edge), cmp);

  for ( i = 0 ; i < n ; i++ )
    if ( edges[i].a != edges[i].b )
      printf("%d %d\n", edges[i].a + 1, edges[i].b + 1);

  return 0;
}

int cmp(const void *x, const void *y) {
  edge *X = (edge*) x;
  edge *Y = (edge*) y;

  if ( X->a != Y->a )
    return X->a - Y->a;
  else
    return X->b - Y->b;
}
