#include <stdio.h>
int main() {
#ifdef EVAL
    freopen("output.txt", "w", stdout);
#endif
    printf("%d\n", 17);
    return 0;
}

