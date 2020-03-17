
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

typedef unsigned long long ull;

#define INF 10000000

map<pair<int, int>, int> M;

int calcola(int k, int n) {
    if (n == 0) return 0;
    if (k == 0) return INF;
    if (n == 1) return 1;

    if (M.find(make_pair(k, n)) != M.end()) return M[make_pair(k, n)];

    int best_moves = n;

    for (int m = 1; m < n; m++) {
        int remv = n % m;
        int rem = calcola(k, remv ? remv : m);
        int fnd = calcola(k - 1, m - 1);
        int moves = (n - 1) / m;
        best_moves = min(best_moves, max(rem, fnd) + moves);
    }

    M[make_pair(k, n)] = best_moves;
    return best_moves;
}


int main() {
  int K, N;
  scanf("%d%d", &K, &N);
  printf("%d\n", calcola(K, N));
}
