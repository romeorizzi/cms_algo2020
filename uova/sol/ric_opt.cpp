
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

#define INF 10000000

int M[11][1000001];

int calcola(int k, int n) {
  if (n == 0) return 0;
  if (k == 0) return INF;
  if (n == 1) return 1;

  if (M[k][n]) return M[k][n] - 1;

  int lb = 1;
  int ub = n;

  while (ub - lb > 1) {
    int m = (lb + ub) / 2;
    int rem = calcola(k, n - m);
    int fnd = calcola(k - 1, m - 1);
    if (rem >= fnd) {
      lb = m;
    }
    else {
      ub = m;
    }
  }

  int best_moves_a = max(calcola(k, n - lb), calcola(k - 1, lb - 1));
  int best_moves_b = max(calcola(k, n - ub), calcola(k - 1, ub - 1));
  int best_moves = min(best_moves_a, best_moves_b) + 1;

  M[k][n] = best_moves + 1;
  return best_moves;
}


int main() {
  int K, N;
  scanf("%d%d", &K, &N);
  printf("%d\n", calcola(K, N));
}
