// problem: ordina_x, Romeo Rizzi Mar 2015

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

extern void ordina(long int n);

#define MAX_N_BALLS 100000

static FILE *file;
static long int nBalls;
static long int order[MAX_N_BALLS];
static long int nPesate = 0;
static long int maxPesate;
static int subtask;
static int seed;

#define CRAND_MAX 0x7fffffff
static int rseed;
int rand_cp() {
	return rseed = (rseed * 1103515245 + 12345) & CRAND_MAX;
}

inline void swap38454(long int *a, long int *b) { long int tmp = *a; *a = *b; *b = tmp; }

static void generaPerm_random_uniform(long int *perm, long int n) {
   long int i;
   for(i = 0; i < n; i++)  perm[i] = i;
   for(i=n-1; i > 0; i--)
     swap38454( &perm[i], &perm[ (rand_cp() % i) ] );
}


long int bigliaIntermedia(long int bigliaA, long int bigliaB, long int bigliaC) {
  nPesate++;
  if(order[bigliaA] >= order[bigliaB]) {
    if(order[bigliaB] >= order[bigliaC]) return bigliaB;
    if(order[bigliaA] <= order[bigliaC]) return bigliaA;
    return bigliaC;
  }
  else {
    if(order[bigliaB] <= order[bigliaC]) return bigliaB;
    if(order[bigliaA] >= order[bigliaC]) return bigliaA;
    return bigliaC;
  }
}

void consegnaBiglieInOrdine( long int biglia_in_pos[] ) {
   long int i;
   int well_ordered = 1;
   for(i = 0; i < nBalls; i++)
     if( (order[biglia_in_pos[i]] != i) && (order[biglia_in_pos[i]] != nBalls-i-1) ) well_ordered = 0;
   fprintf(file, "%d %ld %ld\n", well_ordered, nPesate, maxPesate);
   /* only for debugging
   for(i = 0; i < nBalls; i++)
     fprintf(file, "%ld ", order[i] );
   fprintf(file, "\n");
   for(i = 0; i < nBalls; i++)
     fprintf(file, "%ld ", biglia_in_pos[i] ); */
   exit(0);
}

int main() {

#ifdef EVAL
  file = fopen("input.txt", "r");
#else
  file = stdin;
#endif

  fscanf(file, "%ld %d %d", &nBalls, &subtask, &seed);
  fclose(file);

  int LOG_UP = 1;
  long int guy = 2;
  while( guy < nBalls ) { LOG_UP++; guy *= 2; }

  rseed = seed;
  generaPerm_random_uniform(order, nBalls); //genera permutazione

#ifdef EVAL
  file = fopen("output.txt", "w");
#else 
  file = stdout;
#endif

  maxPesate = 1000*nBalls*nBalls;
     long int i;
  if(subtask == 1)
     for(i = 0; i < nBalls; i++)  order[i] = i;
  if(subtask == 2)
     for(i = 0; i < nBalls; i++)  order[i] = nBalls-i-1;
  if(subtask == 5) { maxPesate = nBalls*(nBalls-1)/2; }
  if(subtask == 6) { maxPesate = 3*nBalls*LOG_UP; }
  if(subtask == 7) { maxPesate = nBalls+nBalls*(LOG_UP); } 

  ordina(nBalls);

  fclose(file);
}
