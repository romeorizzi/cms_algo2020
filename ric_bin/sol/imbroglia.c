#include <stdio.h>

void ricerca(long long int n) {
  fscanf(fopen("input.txt", "r"), "%lld", &n);
  answer(n);
}
