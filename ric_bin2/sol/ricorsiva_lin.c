#include <stdio.h>
#include <math.h>
#include <math.h>

typedef long long ll;

int max(int a, int b) { if (a > b) return a; else return b; }

int calcola(ll n) {
  if (n <= 1) return 0;
  return calcola((n - 1) / 2 + (n - 1) % 2) + 1;
}

int main(void) {
  ll N = 0;
  scanf("%lld", &N);
  printf("%d\n", calcola(N));
  return 0;
}
