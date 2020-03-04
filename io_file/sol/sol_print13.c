#include <stdio.h>
int main() {
#ifdef EVAL
    freopen("output.txt", "w", stdout);
#endif
    printf("%d\n", 13);
    return 0;
}

