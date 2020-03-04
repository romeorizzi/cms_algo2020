/**
 *  Soluzione di io
 *
 *  Autore: Romeo Rizzi
 *
 *  Descrizione: Banale
 */
#include <stdio.h>
int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a;
    scanf("%d", &a);
    printf("%d\n", a);
    return 0;
}

