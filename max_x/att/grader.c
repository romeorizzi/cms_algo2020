// problem: max_x, Romeo Rizzi Jan 2015

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

extern void individua(long int n, long int maxLies);

#define MAX_N_BALLS 1000000

static FILE *file;
static long int nBalls;
static long int goodBall;
static long int nPesate = 0;
static long int maxLies = 0;
static long int maxPesate;
static int subtask;
static long int perm[MAX_N_BALLS];

#define CRAND_MAX 0x7fffffff
static int rseed;
int rand_cp() {
	return rseed = (rseed * 1103515245 + 12345) & CRAND_MAX;
}

static long int min(long int a, long int b) { return a < b ? a : b; }
static long int max(long int a, long int b) { return a > b ? a : b; }

inline void swap(long int *a, long int *b) { long int tmp = *a; *a = *b; *b = tmp; }

static void generaPerm_random_uniform(long int *perm, long int n) {
   long int i;
   for(i = 0; i < n; i++)  perm[i] = i;
   for(i=n-1; i > 0; i--)
     swap( &perm[i], &perm[ (rand() % i) ] );
}


int pesa(long int bigliaA, long int bigliaB) {
  nPesate++;
  int invert = 1;
  if( maxLies > 0 )
    if( rand() % nBalls - nPesate < maxLies) {
       invert = -1;
       maxLies--;
    }
  if(perm[bigliaA] > perm[bigliaB]) return invert;
  if(perm[bigliaA] < perm[bigliaB]) return -invert;
  return 0;
}

void pensoCheMaxSia(long int risp) {
  fprintf(file, "%ld %ld %ld\n", risp, nPesate, maxPesate);
  exit(0);
}

int main() {

#ifdef EVAL
  file = fopen("input.txt", "r");
#else
  file = stdin;
#endif

  fscanf(file, "%ld %ld %d %d", &goodBall, &nBalls, &subtask, &rseed);
  fclose(file);

  generaPerm_random_uniform(perm, nBalls -1); //genera permutazione di tutte eccetto la piu' pesante
  perm[nBalls -1] = perm[goodBall]; //sposto in fondo quella che occupa la posizione predestinata
  perm[goodBall] = nBalls -1; //colloco la piu' pesante al suo posto

#ifdef EVAL
  file = fopen("output.txt", "w");
#else
  file = stdout;
#endif

  maxPesate = 10*nBalls;
  if(subtask == 0) { assert(goodBall==2); }
  if(subtask == 1) { assert(nBalls==2); }
  if(subtask == 2) { maxPesate = nBalls; }
  if(subtask == 3) { maxPesate = nBalls-1; }
  if(subtask == 4) { maxLies = 1; }
  if(subtask == 5) { maxLies = 1; maxPesate = 3*nBalls -3; }
  if(subtask == 6) { maxLies = 1; maxPesate = 2*nBalls; }
  if(subtask == 7) { maxLies = 1; maxPesate = 2*nBalls -1; }
  if(subtask == 8) { maxLies = 2+(rand() % 7) ; maxPesate = (maxLies+1)*(nBalls -1) +maxLies; }

  individua(nBalls, maxLies);
  fclose(file);
}
