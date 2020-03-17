
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

#define INF 10000000

int calcola(int k, int n) {
  if (n == 0) return 0;
  if (k == 0) return INF;
  if (n == 1) return 1;

  int best_moves = n;
  for (int i = 1; i < n; i++) {
    best_moves = min(best_moves, max(
      calcola(k, n - i),
      calcola(k - 1, i - 1)
    ) + 1);
  }
  return best_moves;
}

/*
 * 3 -> 1 x 1
*/

int main() {
  int K, N;
  scanf("%d%d", &K, &N);
  printf("%d\n", calcola(K, N));
}
