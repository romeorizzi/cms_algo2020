#include<cassert>
#include<iostream>

using namespace std;

const int MAX_M = 1000;
const int MAX_N = 1000;
int m,n,q;

//int mosche[MAX_M + 1][MAX_N + 1];

int ft[MAX_M + 1][MAX_N + 1];

int lsb(int a) {
  return a & (-a);
}

int prefix_sum(int a) {
  assert( a >= 0 );
  if( a == 0)
    return 0;
  return ft[1][a] + prefix_sum(a-lsb(a));
}

int interval_sum(int a, int b) {
  assert(1 <= a);
  assert(a <= b);
  assert(b <= MAX_N);
  return prefix_sum(b) - prefix_sum(a-1);
}
/*
int sum_rectangle(int i1, int i2, int j1, int j2) {
  assert(1 <= i1);
  assert(i1 <= i2);
  assert(i2 <= MAX_M);
  assert(1 <= j1);
  assert(j1 <= j2);
  assert(j2 <= MAX_N);
  return prefix_sum(i2, j2) - prefix_sum(i1 - 1, j2) - prefix_sum(i2, j1 - 1) + prefix_sum(i1 - 1, j1 - 1);
}
*/


/*
int prefix_sum(int i, j) {
  assert( i >= 0 );
  assert( j >= 0 );
  if(i == 0 || j == 0)
    return 0;
  return ft(a) + prefix_sum(a-lsb(a));
}
*/

void rec_update(int diff, int pos) {
  if (pos <= MAX_N) {
      ft[1][pos] += diff;
      rec_update(diff, pos + lsb(pos));
  }
}

void update(int new_val, int pos) {
  assert(pos >= 1);
  assert(pos <= MAX_N);
  int diff = new_val - interval_sum(pos, pos);
  rec_update(diff, pos + lsb(pos));

  for (int i = 1; i <= n; i++ )
    cout << ft[1][i] << ' ';

  cout << endl;
}

int main() {
  cin >> m >> n >> q;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int tmp;
      cin >> tmp;
      assert(i = 1);
      //update(i, j, tmp);
      update(tmp, j);
    }
  }

  for (int i = 0; i < q; i++) {
    int type;
    std::cin >>  type;

    if (type == 0) {
      int i1, i2, j1, j2;
      cin >> i1 >> i2 >> j1 >> j2;
      //cout << interval_sum(i1, i2, j1, j2);
      cout << interval_sum(j1, j2) << '\n';
    }
    else{
      int i, j, new_val;
       cin >> i >> j >> new_val;
       //update(i, j, new_val);
       update(new_val, j);
    }
  }
  return 0;
}
