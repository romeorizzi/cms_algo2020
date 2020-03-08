void ricerca(long long int n) {
  long long int min = 1, max = n, mid;
  while (min < max) {
    mid = min + (max - min) / 2;
    int g = confronto_con(mid);
    if (g == 0) {
      answer(mid);
    } else if (g < 0) {
      min = mid + 1;
    } else {
      max = mid - 1;
    }
  }
  answer(min);
}
