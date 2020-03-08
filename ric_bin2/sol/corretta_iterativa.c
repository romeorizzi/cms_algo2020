#include <stdio.h>

typedef unsigned long long ull;

int main(void) {
  ull N = 0;
  scanf("%lld", &N);

  int steps = 0;

  while (N > 1) {
    ull rem = N - 1;
    N = rem / 2 + rem % 2;
    steps++;
  }

  printf("%d\n", steps);
  return 0;
}
