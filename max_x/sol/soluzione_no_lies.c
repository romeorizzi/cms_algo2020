// problem: max_x, nel caso di nessuna bugia, Romeo Rizzi Jan 2015
#include "ourLibToPlay.h"
void individua(long int n, long int maxLies) {
    long int i, max_so_far = 0;
    for(i = 1; i < n; i++)
      if( pesa(i, max_so_far) )
        max_so_far = i;
    pensoCheMaxSia(max_so_far);
}

