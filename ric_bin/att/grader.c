#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void ricerca(long long int n);

static FILE *file;
static long long int risposta;
static long long int lower_bound = 1;
static long long int upper_bound;
static int subtask;
static long long int min(long long int a, long long int b) { return a < b ? a : b; }
static long long int max(long long int a, long long int b) { return a > b ? a : b; }

int confronto_con(long long int x) {
  if (subtask == 4) {  // se posso cambiare numero segreto (contenuto nella variabile risposta)
    if (x > lower_bound + (upper_bound - lower_bound)/2 )
      risposta = lower_bound;
    else
      risposta = upper_bound;
    fprintf(file, "2 %lld\n", risposta);
  }

  // comunico nel log la "confronto_con" dell'utente
  fprintf(file, "0 %lld\n", x);

  if (x > risposta) {
    upper_bound = min(upper_bound, x - 1);
    return 1;
  } else if (x < risposta) {
    lower_bound = max(lower_bound, x + 1);
    return -1;
  } else {
    return 0;
  }
}

void answer(long long int x) {
  fprintf(file, "1 %lld\n", x);
  exit(0);
}

int main() {

#ifdef EVAL
  file = fopen("input.txt", "r");
#else
  file = stdin;
#endif

  assert( fscanf(file, "%lld %lld %d", &risposta, &upper_bound, &subtask) == 3);
  fclose(file);

#ifdef EVAL
  file = fopen("output.txt", "w");
#else
  file = stdout;
#endif

  ricerca(upper_bound);
  fclose(file);
}
