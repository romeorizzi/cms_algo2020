/* pirellone *
   correttore input answer
   Roberto Grossi  2005-02-25

   Qualche modifica di Flavio 2005-02-28

   Riarchitetturato da Romeo 2016-05-11
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define  MaxM   5000
#define  MaxN   5000

int R[MaxN], C[MaxM];  // Sol. di Riferimento: Interruttori di riga e colonna
int RR[MaxN], CC[MaxM];  // Answer: Interruttori di riga e colonna

int N, M, NN, MM;

void ex( char *msg, float res ) {
   if (msg) fprintf(stderr, "%s\n", msg);

   printf("%f\n", res);

   exit(0);
}

void complement( int a[], int size ){
  int i;
  for (i=0; i < size; i++)
    a[i] =  1 -a[i];
}

int compare( int a[], int b[], int size ){
  int i;
  for (i=0; i < size; i++)
    if ( a[i] != b[i] )
      return 0;
  return 1;
}

int main(int argc, char *argv[]) {
  int i, j, f;
  char c;
  FILE *in, *rif, *an;

  if ( argc != 4 ){
    fprintf( stderr, "usage: %s input correct_answ user_answ\n", argv[0]);
    return -100000;
  }

  /* input */
  in = fopen( argv[1], "r");
  if ( in == NULL )
    ex("File di input mancante\n", 0.0);

  /* correct answer */
  rif = fopen( argv[2], "r");
  if ( rif == NULL)
    ex("File con output di riferimento mancante\n", 0.0);

  /* user answer */
  an = fopen( argv[3], "r");
  if ( an == NULL )
    ex("Output errato.", 0.0);


  /* Lettura parametri dell'input */
  if( fscanf(in, "%d", &N) != 1) ex("File di input errato.", 0.0);
  if( fscanf(in, "%d", &M) != 1) ex("File di input errato.", 0.0);

  /* Lettura output corretto */
  for(i=0; i < N; i++) {
    f = fscanf(rif, "%d", &R[i]);
    if (f != 1)
      ex("Output di riferimento errato.", 0.0);
  }
  for(i=0; i < M; i++) {
    f = fscanf(rif, "%d", &C[i]);
    if (f != 1)
      ex("Output di riferimento errato.", 0.0);
  }

  /* Lettura output da validare */

  for(i=0; i < N; i++) {
    f = fscanf(an, "%d", &RR[i]);
    if (f != 1)
      ex("Output errato.", 0.0);
  }
  for(i=0; i < M; i++) {
    f = fscanf(an, "%d", &CC[i]);
    if (f != 1)
      ex("Output errato.", 0.0);
  }

  if ( compare( R, RR, N ) || compare( C, CC, MM ) ) {
    ex("OK", 1.000);
  }

  complement( R, N );
  complement( C, M );

  if ( compare( R, RR, N ) || compare( C, CC, MM ) ) {
    ex("OK", 1.000);
  }

  ex("Output errato.", 0.0);

  return 0;
}
