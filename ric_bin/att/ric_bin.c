int confronto_con(long long int val);
void answer(long long int risp);

void ricerca(long long int n) {
  int g = confronto_con(n/2);
  if (g == 0) answer(n/2);
  if (g > 0) answer(1);
  if (g < 0) answer(n);
}
