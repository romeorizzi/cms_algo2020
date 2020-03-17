
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

typedef unsigned long long ull;

#define INF 1000000

map<pair<int, int>, int> M;

int calcola(int k, int n) {
  if (n == 0) return 0;
  if (k == 0) return INF;
  if (n == 1) return 1;

  if (M.find(make_pair(k, n)) != M.end()) return M[make_pair(k, n)];

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

  M[make_pair(k, n)] = best_moves;
  return best_moves;
}


int main() {
  int K, N;
  scanf("%d%d", &K, &N);
  printf("%d\n", calcola(K, N));
}
