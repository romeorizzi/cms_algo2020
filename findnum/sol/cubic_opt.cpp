
#include <bits/stdc++.h>

using namespace std;

struct cell {
  int d;
  int s;
  string num;
};

bool V[501][5001];

string calcola(int D, int S) {

  queue<cell> q;

  q.push({0, 0, string("")});
  V[0][0] = 1;

  while (q.size()) {
    cell front = q.front(); q.pop();

    if (front.d == 0 && front.s == S) {
      return front.num;
    }

    for (int i = 0; i <= 9; i++) {
      int nd = (front.d * 10 + i) % D;
      int ns = front.s + i;
      if (!V[nd][ns]) {
        q.push({nd, ns, front.num + (char)(i + '0')});
        V[nd][ns] = 1;
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
