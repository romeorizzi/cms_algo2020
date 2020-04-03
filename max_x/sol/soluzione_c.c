// problem: max_x, nel caso di nessuna bugia, Romeo Rizzi Jan 2015
#include "ourLibToPlay.h"
long int abs(long int a) { return ( a >= 0 ) ? a : -a; }
void individua(long int n, long int maxLies) {
    long int i, max_so_far = 0;
    for(i = 1; i < n; i++) {
      long int sum_votes = 0;
      while( abs(sum_votes) <= maxLies ) {
         int new_vote = pesa(i, max_so_far);
         if( new_vote * sum_votes < 0 )
            maxLies--;
         sum_votes += new_vote;
      }
      if( sum_votes > 0 )   max_so_far = i;
    }
    pensoCheMaxSia(max_so_far);
}

