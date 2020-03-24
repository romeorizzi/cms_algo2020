// problem: max_x, example of a solution file, Romeo Rizzi Jan 2015
#include "ourLibToPlay.h"
void individua(long int n, long int maxLies) {
  if( pesa(0,n-1) > 0)  pensoCheMaxSia(0); 
  else pensoCheMaxSia(n-1); 
}
