/*
  Funziona se i nodi vengono numerati secondo una visita pre-order o 
  una in ampiezza (sostanzialmente il primo nodo deve essere la radice
  della visita, e scelte due etichette i < j, j non puo` essere un
  antenato di i nella visita).
*/
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define STDSTREAM
/*#define DEBUG*/

#define UNDEFINED -1


/* --- */

int readInt();

void eval();
void choose();
void print();

/* --- */
 
FILE *in, *out;
int n;
int *weight, *weightForInputNames, *count, *deg, *countPrefix;
int *first, *second, *firstSorted, *secondSorted, *leaves, *order, *name;
int *daddy, *childrenList, *firstChild;
int tmp, neigh, leaf;


int *setCover;
int *included, *excluded, *best;

/* --- */

int main() {

#ifdef STDSTREAM
  in = stdin;
  out = stdout;
#else
  in = fopen("input.txt", "r");
  out = fopen("output.txt", "w");
#endif

  int i,a,b,pos, nLeaves;

  /* Input */

  n = readInt();
  //fprintf(out, "n = %d \n", n);

  weightForInputNames  = (int*) calloc(n+1, sizeof(int));
  count  = (int*) calloc(n+1, sizeof(int));

  for (i = 1 ; i <= n ; i++ ) {
    weightForInputNames[i] = readInt();
    //fprintf(out, "weightForInputNames[%d] = %d \n", i, weightForInputNames[i]);
    count[i] = 0;
  }

  first  = (int*) calloc(2*n, sizeof(int));
  second  = (int*) calloc(2*n, sizeof(int));
  firstSorted  = (int*) calloc(2*n, sizeof(int));
  secondSorted  = (int*) calloc(2*n, sizeof(int));
  for (i = 0; i < n-1 ; i++ ) {
     a = readInt();   b = readInt();
     if(b<a) { tmp = a; a = b; b = tmp; }
     first[i] = a;
     second[i] = b;
     first[i+n-1] = b;
     second[i+n-1] = a;
     count[a]++;
     count[b]++;
  }

  //for (i = 0; i < 2*n-2 ; i++ ) {
  //   fprintf(out, "a[%d] = %d   ", i, first[i]);
  //   fprintf(out, "b[%d] = %d \n", i, second[i]);
  //}


  deg  = (int*) calloc(n+1, sizeof(int));
  order  = (int*) calloc(n+1, sizeof(int));
  leaves = (int*) calloc(n+1, sizeof(int));
  countPrefix  = (int*) calloc(n+1, sizeof(int));

  nLeaves = 0;
  countPrefix[0] = 0;
  for (i = 1 ; i <= n ; i++ ) {
    deg[i] = count[i];
    countPrefix[i] = count[i] + countPrefix[i-1];
    //fprintf(out, "deg[%d] = %d \n ", i, deg[i]);
    if(deg[i] == 1) {
      leaves[nLeaves] = i;
      nLeaves++;
    }
  }

  for (i = 0; i < 2*n-2 ; i++ ) {
     a = first[i];
     b = second[i];
     countPrefix[a]--;
     firstSorted[countPrefix[a]] = a;
     secondSorted[countPrefix[a]] = b;
  }

  //for (i = 0; i < 2*n-2 ; i++ ) {
  //   fprintf(out, "a[%d] = %d   ", i, firstSorted[i]);
  //   fprintf(out, "b[%d] = %d \n", i, secondSorted[i]);
  //}

  int leafPos = 0; int survivingNodes = n;
  while(survivingNodes > 1) {
    leaf = leaves[leafPos]; leafPos++;
    survivingNodes--;
    order[leaf] = survivingNodes;
    //fprintf(out, "leaf = %d, order[leaf] = %d \n", leaf, order[leaf]);
    for(pos = 0; pos < deg[leaf]; pos++) {
      neigh = secondSorted[countPrefix[leaf] + pos];
      //fprintf(out, "neigh = %d \n", neigh);
      if(count[neigh] > 1) {
        count[neigh]--;
        if(count[neigh] == 1) {
          leaves[nLeaves] = neigh;
          nLeaves++;
        }
      }
    }
  } order[leaves[leafPos]] = 0;
  //fprintf(out, "leaf = %d, order[leaf] = %d \n\n", leaves[leafPos], order[leaves[leafPos]]);

  weight = (int*) calloc(n, sizeof(int));
  name  = (int*) calloc(n, sizeof(int));
  for (i = 1 ; i <= n ; i++ ) {
    //fprintf(out, "order[%d]=%d\n", i, order[i]);
    weight[order[i]] = weightForInputNames[i];
    name[order[i]] = i;
  }

  daddy = (int*) calloc(n, sizeof(int));
  firstChild   = (int*) calloc(n, sizeof(int));
  childrenList = (int*) calloc(2*n, sizeof(int));

  daddy[0] = UNDEFINED;
  for (a = 0, pos = 0; a < n ; a++ ) {
     firstChild[a] = pos;
     //fprintf(out, "firstChild[%d]=%d\n", a, pos);
     for(i = 0; i < deg[name[a]]; i++) {
        neigh = secondSorted[countPrefix[name[a]] + i];
        b = order[neigh];
        if ( a < b ) {
	  //        fprintf(out, "neigh=%d, b=%d\n", neigh, b);
	  daddy[b] = a;
          childrenList[pos] = b; pos++;
        }
     }
     childrenList[pos] = 0; pos++;
  }

  setCover = (int*) calloc(n, sizeof(int));
  included = (int*) calloc(n, sizeof(int));
  excluded = (int*) calloc(n, sizeof(int));
  best = (int*) calloc(n, sizeof(int));

  /* Weighted */

  eval();
  choose();
  print();

  //  /* Non Weighted */
  //
  //  /*
  //  for (i = 0 ; i < n ; i++ )
  //    weight[i] = 1;
  //  
  //  eval();
  //  choose();
  //  print();
  //  */

  return 0;
}

void print() {
  int i;
  int size = 0;
  for (i = 0 ; i < n ; i++ )
    if ( setCover[i] )
      size++;

  fprintf(out, "%d\n", size);

  for (i = 0 ; i < n ; i++ )
    if ( setCover[i] )
      fprintf(out, "%d ", name[i]);

  fprintf(out, "\n");
}

void choose() {
  int i;
  for (i = 0 ; i < n ; i++ ) {
     setCover[i] = 0;
     if( included[i] <= best[i] ) setCover[i] = 1;
     if( i>0 )
       if( setCover[daddy[i]] == 0 )
         setCover[i] = 1;
  }
}

void eval() {
  int i,j;
  for ( i = n - 1 ; i >= 0 ; i-- ) {
     excluded[i] = 0;
     included[i] = weight[i];
     for(j=firstChild[i] ; childrenList[j] > 0 ; j++) {
        int child = childrenList[j];
        included[i] += best[child];
        excluded[i] += included[child];
     }
     if( included[i] < excluded[i])  best[i] = included[i];
     else best[i] = excluded[i];

#ifdef DEBUG
     fprintf(out, "%d: in = %d, out = %d,  best = %d\n",
             i + 1, included[i], excluded[i], best[i]);
#endif

  }
}

int readInt() {
  int spoon;

  if ( fscanf(in, " %d", &spoon) != 1 )
    exit(1);

  return spoon;
}
