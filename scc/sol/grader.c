#include <stdio.h>
#include <assert.h>

/*

  Note for grader writers: please, do not assume that have C99
  available. For example, use:

    int i;
    for (i = 0; i < N; i++) {

  instead of:

    for (int i = 0; i < N; i++) {

  You may also consider the option to delete this comment when you
  actually write a grader!

 */
 
#define MAXN 10000
#define MAXE 100000

static int N, E;
static int da[MAXE], a[MAXE];

int scc(int N, int E, int da[], int a[]);

int main(){
  FILE *fin, *fout;
  fin = stdin;
  fout = stdout;
  assert(2==fscanf(fin, "%d %d", &N, &E));
  int i;
  for (i=0; i<E; i++) assert(2==fscanf(fin, "%d %d", &da[i], &a[i]));
  fprintf(fout, "%d\n", scc(N, E, da, a));
  return 0;
}

