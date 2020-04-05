
#include <bits/stdc++.h>

using namespace std;

struct cell {
  int d;
  int s;
};

pair<int, int> P[501][5001];
char digit[501][5001];


string backtrack(int d, int s) {
  vector<char> sol;

  while (d > 0 || s > 0) {
    sol.push_back(digit[d][s]);
    auto p = P[d][s];
    d = p.first;
    s = p.second;
  }

  return string(sol.rbegin(), sol.rend());
}


string calcola(int D, int S) {

  queue<cell> q;

  q.push({0, 0});
  digit[0][0] = 'X';

  while (q.size()) {
    cell front = q.front(); q.pop();

    for (int i = 0; i <= 9; i++) {
      int nd = (front.d * 10 + i) % D;
      int ns = front.s + i;
      if (!digit[nd][ns] && ns <= S) {
        digit[nd][ns] = i + '0';
        P[nd][ns] = {front.d, front.s};

        if (nd == 0 && ns == S) {
          return backtrack(nd, ns);
        }

        q.push({nd, ns});
      }
    }
  }
  return "-1";
}


int main() {
  int D, S;
  scanf("%d%d", &D, &S);
  printf("%s\n", calcola(D, S).c_str());
}
