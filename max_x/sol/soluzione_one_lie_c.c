// problem: max_x, nel caso di nessuna bugia, Romeo Rizzi Jan 2015
#include "ourLibToPlay.h"
void individua(long int n, long int maxLies) {
    long int i, max_so_far = 0, lie_spotted = 0;
    for(i = 1; i < n; i++) {
      int sum_of_1_2_or_3votes = pesa(i, max_so_far);
      if(!lie_spotted) sum_of_1_2_or_3votes += pesa(i, max_so_far);
      if( sum_of_1_2_or_3votes == 0 ) {
        lie_spotted = 1;
        sum_of_1_2_or_3votes += pesa(i, max_so_far);
      }
      if( sum_of_1_2_or_3votes > 0 )   max_so_far = i;
    }
    pensoCheMaxSia(max_so_far);
}

