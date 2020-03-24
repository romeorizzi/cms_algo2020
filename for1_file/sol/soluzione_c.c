/**
 *  Soluzione di for1_file
 *
 *  Romeo Rizzi, last: 2020-03-24
 */
#include <stdio.h>
int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int N, i;
    scanf("%d", &N);
    for(i = 1; i <= N; i++)
       printf("%d ", i);
    printf("\n");
    return 0;
}

