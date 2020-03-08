#include <stdio.h>
#include <math.h>

typedef long long ll;

int max(int a, int b) { if (a > b) return a; else return b; }

int calcola(ll s, ll e) {
  if (e - s <= 1) return 0;

  int diff = (e - s);
  int m = s + diff / 2;

  return max(calcola(s, m), calcola(m + 1, e)) + 1;
}

int main(void) {
  ll N = 0;
  scanf("%lld", &N);

  printf("%d\n", calcola(0, N));
  return 0;
}
