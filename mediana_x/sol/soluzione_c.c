// problem: ordina_x, mergeSort, Romeo Rizzi Mar 2015
#include "ourLibToPlay.h"

void mergeSort(long int biglia_in_pos[], long int from, long int to, long int tmp[]) {
  if( to <= from ) return;
  long int middle = (from + to)/2;
  mergeSort(biglia_in_pos, from, middle, tmp);
  mergeSort(biglia_in_pos, middle+1, to, tmp);
  long int posL = from;
  long int posR = middle+1;
  long int pos = from;
  while( (posL <= middle) && (posR <= to) )
    if( bigliaIntermedia(biglia_in_pos[posL], biglia_in_pos[0], biglia_in_pos[posR]) == biglia_in_pos[posL] )
       tmp[pos++] = biglia_in_pos[posL++];
    else
       tmp[pos++] = biglia_in_pos[posR++];
  while(posL <= middle)
    tmp[pos++] = biglia_in_pos[posL++];
  while(posR <= to)
    tmp[pos++] = biglia_in_pos[posR++];
  for(pos = from; pos <= to; pos++)
    biglia_in_pos[pos] = tmp[pos];
}


void ordina(long int n) {
  long int  biglia_in_pos[n];
  long int  tmp[n];
  long int i;
  for(i = 0; i < n; i++) biglia_in_pos[i] = i;
  long int myargmin = (long int) 0;
  long int myargmax = (long int) 1;
  for(i = 2; i < n; i++) {
    if( bigliaIntermedia(myargmin, myargmax, i) == myargmax ) myargmax = i;
    if( bigliaIntermedia(myargmin, myargmax, i) == myargmin ) myargmin = i;
  }
  tmp[0] = biglia_in_pos[0]; biglia_in_pos[0] = myargmin; biglia_in_pos[myargmin] = tmp[0];

  // da ora in poi so che la biglia in posizione 0 e` di peso estremo (massimo oppure minimo, ma diciamo mymin)
  // a questo punto vale la relazione a my< b se e solo se a e di peso intermedio tra (0,a,b)

  mergeSort(biglia_in_pos, 1, n-1, tmp);
  consegnaBiglieInOrdine(biglia_in_pos);
}

