/**
 *  Soluzione di for2_std
 *  Romeo Rizzi, last: 2020-03-24
 */
#include <stdio.h>
int main() {
    int N, i, j;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
       for(j = 1; j <= N; j++)
          printf("%d ", i*j);
       printf("\n");
    }
    return 0;
}

