#include <stdio.h>
#include <assert.h>
#define MAXN 1000010

static int N,i ;
static int preordine [MAXN] ;
static int postordine[MAXN] ;
static int simmetrica[MAXN] ;

void visita(int N, int *PRE, int *POST, int *SIMM);

int main(){
  FILE *fin, *fout;
#ifdef EVAL
  assert(fin = fopen("input.txt", "r"));
  assert(fout = fopen("output.txt", "w"));
#else
  fin = stdin;
  fout = stdout;
#endif
  assert(1==fscanf(fin, "%d", &N));
  
  for( i = 0 ; i < N ; i++ ) assert( 1 == fscanf(fin,"%d",preordine+i) );
  for( i = 0 ; i < N ; i++ ) assert( 1 == fscanf(fin,"%d",postordine+i) );
  
  visita(N,preordine,postordine,simmetrica);
  
  for( i = 0 ; i < N ; i++ ) fprintf(fout,"%d ",simmetrica[i]);
  fprintf(fout,"\n");
  
  return 0;
}

