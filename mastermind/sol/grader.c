#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static int maxAttempts;
static int guesses;
static FILE *file;

static int secretCode[4] = {0}; //Codice da scoprire

#define min(a, b) (((a) > (b)) ? (b) : (a))

extern void solve();

#define CRAND_MAX 0x7fffffff
static int rseed;
int rand_cp() {
	return rseed = (rseed * 1103515245 + 12345) & CRAND_MAX;
}

void checkCode(int attempt[], int result[]) {
    int black = 0, white = 0;

    int fr_att[6] = {0};
    int fr_hist[6] = {0};

    for(int i = 0; i < 4; i++) {
        if(attempt[i] == secretCode[i]) {
            black++;
        }
        else {
          assert(attempt[i] >= 0 && attempt[i] <= 5);
          assert(secretCode[i] >= 0 && secretCode[i] <= 5);
          fr_att[attempt[i]]++;
          fr_hist[secretCode[i]]++;
        }
    }

    for(int i = 0; i < 6; i++) {
      white += min(fr_att[i], fr_hist[i]);
    }
    result[0] = black;
    result[1] = white;

	if (result[0] != 4) guesses++;
}

void pensoCheCodiceSia(int risposta[]){
	fprintf(file, "%d %d\n", maxAttempts, guesses);

	for (int j = 0; j < 4; j++) {
			fprintf(file, "%d ", risposta[j]);
	}
	fprintf(file, "\n");
	fclose(file);

	exit(0);
}

int main(){

	#ifdef EVAL
    file = fopen("input.txt", "r");
	#else
  	file = stdin;
	#endif

    int subtask, seed;

	fscanf(file, "%d", &subtask);
	fscanf(file, "%d", &seed);

	fclose(file);

	#ifdef EVAL
    file = fopen("output.txt", "w");
	#else
    file = stdout;
	#endif

  rseed = seed;

 	if(subtask == 0) maxAttempts = 1000000;
	if(subtask == 1) maxAttempts = 10;
	if(subtask == 2) maxAttempts = 6; // soluzione ottima (6 errate)

	for(int i = 0; i < 4; i++){
		secretCode[i] = rand_cp() % 6;
	}

    guesses = 0;

	solve();

    return 0;
}
