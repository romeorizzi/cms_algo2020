#include <stdio.h>

void individua(long int n, long int maxLies) {
  fscanf(fopen("input.txt", "r"), "%lld", &n);
  pensoCheMaxSia(n);
}
