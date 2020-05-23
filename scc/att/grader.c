#include <stdio.h>
#include <assert.h>

 
#define MAXN 10000
#define MAXE 100000

static int N, E;
static int da[MAXE], a[MAXE];

int scc(int N, int E, int da[], int a[]);

int main(){
  FILE *fin, *fout;
  
  assert(fin = fopen("input.txt", "r"));
  assert(fout = fopen("output.txt", "w"));
  assert(2==fscanf(fin, "%d %d", &N, &E));
  int i;
  for (i=0; i<E; i++) assert(2==fscanf(fin, "%d %d", &da[i], &a[i]));
  fprintf(fout, "%d\n", scc(N, E, da, a));
  return 0;
}
