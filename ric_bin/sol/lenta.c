void ricerca(long long int n) {
  long long int i;
  for (i=1; i<=n; i++) {
    if (guess(i) == 0) {
      answer(i);
    }
  }
}
