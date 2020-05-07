// problem: ordina_x, example solver format, Romeo Rizzi Mar 2015
#include "ourLibToPlay.h"

inline void swappa(long int *a, long int *b) { long int tmp = *a; *a = *b; *b = tmp; }

void ordina(long int n) {
  long int  biglia_in_pos[n];
  long int i;
  for(i = 0; i < n; i++) biglia_in_pos[i] = i;
  long int intermedio = bigliaIntermedia( (long int) 0, (long int) 1, (long int) 2);
  swappa( &biglia_in_pos[intermedio], &biglia_in_pos[(long int) 1] );
  consegnaBiglieInOrdine(biglia_in_pos);
}

