/* pirellone *
   Da chiamare con
   ./generatore N M p 1 seed tipo  per una configurazione con soluzione
   ./generatore N M p 0 seed tipo  per una configurazione senza soluzione
   dove N e` il numero di righe e M e' il numero di colonne, 
   p in [1..99] e' la percentuale di sparsita' degli interruttori su cui agire,
   seed e' il seme iniziale per la funzione random,
   tipo = 0 genera l'input, tipo = 1 genera l'output
   Roberto Grossi  2005-02-25
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define  MaxM   5000
#define  MaxN   5000

char P[MaxN][MaxM];     // Luci del Pirellone
char R[MaxN], C[MaxM];  // Interruttori di riga e colonna
int N, M, p, solvable, seed, tipo;

void compriga( int i ){
  int j;
  for (j=0; j < M; j++)
    if (P[i][j])
      P[i][j] = 0;
    else
      P[i][j] = 1;
}

void compcol( int j ){
  int i;
  for (i=0; i < N; i++)
    if (P[i][j])
      P[i][j] = 0;
    else
      P[i][j] = 1;
}

int main(int argc, char *argv[]) {
  int i, j, ii, jj;

  if ( argc != 7 ||
       sscanf(argv[1], " %d", &N) != 1 ||
       sscanf(argv[2], " %d", &M) != 1 ||
       sscanf(argv[3], " %d", &p) != 1 ||
       sscanf(argv[4], " %d", &solvable) != 1 ||
       sscanf(argv[5], " %d", &seed) != 1 ||
       sscanf(argv[6], " %d", &tipo) != 1 ){
    printf("generatore N M p 1 seed tipo, per una configurazione con soluzione\n");
    printf("generatore N M p 0 seed tipo, per una configurazione senza soluzione\n");
    return 1;
  }

  srand( seed );
  
  assert( 1 <= N && N <= MaxN );
  assert( 1 <= M && M <= MaxM );
  assert( 1 <= p && p <= 99 );
  assert( 0 <= tipo && tipo <= 1 );

  for (i=0; i < N; i++)
    for (j=0; j < M; j++)
      P[i][j] = 0;
  for (i=0; i < N; i++)
    R[i] = 0;
  for (j=0; j < M; j++)
    C[j] = 0;


  for (i=0; i < (N*p)/100; i++)
    R[ rand() % N ] = 1;
  for (j=0; j < (M*p)/100; j++)
    C[ rand() % M ] = 1;

  for (i=0; i < N; i++)
    if (R[i])
      compriga( i );

  for (j=0; j < M; j++)
    if (C[j])
      compcol( j );

  if (!solvable){
    i = rand() % N;
    ii = rand() % N;
    j = rand() % M;
    jj = rand() % M;
    
    assert( i != ii && j != jj );

    P[i][j] = 0;
    P[i][jj] = 1;
    P[ii][j] = 1;
    P[ii][jj] = 1;
  }

  if (!tipo) { // genera l'input  
    printf("%d %d\n", N, M);
    for ( i = 0 ; i < N ; i++ ){
      printf("%d", P[i][0]);
      for (j=1; j < M; j++)
	printf(" %d", P[i][j]);
      printf("\n");
    }
  } else { // genera l'output
    if (!solvable){
      printf("0");
      for (i=1; i < N; i++)
	printf(" 0");
      printf("\n");
      printf("0");
      for (j=1; j < M; j++)
	printf(" 0");
      printf("\n");
    } else {
      printf("%d", R[0]);
      for (i=1; i < N; i++)
	printf(" %d", R[i]);
      printf("\n");
      printf("%d", C[0]);
      for (j=1; j < M; j++)
	printf(" %d", C[j]);
      printf("\n");
    }
  }

  return 0;
}
