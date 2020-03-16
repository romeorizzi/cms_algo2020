
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

#define INF 1000000

int M[11][1000001];
int B[11][1000001];

int calcola(int k, int n) {

  for (int i = 0; i <= n; i++) {
    M[0][i] = INF;
    B[0][i] = INF;
  }

  for (int i = 0; i <= k; i++) {
    for (int j = 0; j <= 1; j++) {
      M[i][j] = 0;
      B[i][j] = 0;
    }
  }

  int best_moves = n;
  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {

    M[i][j] = max(B[i][j-1], B[i-1][j]);

    best_moves = min(best_moves, max(
      calcola(k, n - i),
      calcola(k - 1, i - 1)
    ) + 1);
    }
  }
  M[k][n] = best_moves + 1;
  return best_moves;
}


int main() {
  int K, N;
  scanf("%d%d", &K, &N);
  printf("%d\n", calcola(K, N));
}
