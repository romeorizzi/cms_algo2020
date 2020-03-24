// problem: ordina_x, example solver format, Romeo Rizzi Mar 2015
#include "ourLibToPlay.h"

void ordina(long int n) {
  long int  biglia_in_pos[n];
  long int i;
  for(i = 0; i < n; i++) biglia_in_pos[i] = i;
  if(pesa( (long int) 0, (long int) 1) > 0 )
    for(i = 0; i < n; i++) biglia_in_pos[i] = n-i-1;
  consegnaBiglieInOrdine(biglia_in_pos);
}

