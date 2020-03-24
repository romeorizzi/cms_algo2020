#include <cstdio>
#include <cstdlib>

using namespace std;

int main( int argc, char *argv[] ) {
	if (argc != 4) {
		fprintf( stderr, "Numero di argomenti errato.\n");
		exit( EXIT_FAILURE );
	}
	
	//FILE *input = fopen(argv[1], "r");
	FILE *uff = fopen(argv[2], "r");
	FILE *stm = fopen(argv[3], "r");

	int i, j, tmp;
	int codice[4];
	
	// legge la configurazione di input
	int umaxAttempts, uAttempts;
	fscanf(uff, "%d %d", &umaxAttempts, &uAttempts);
	for (i = 0; i < 4; i++) {
		fscanf(uff, "%d", &tmp);
		codice[i] = tmp;
	}
	fclose(uff);
	
	// legge la soluzione sottomessa
	int maxAttempts, attempts;
	
	fscanf(stm, "%d %d", &maxAttempts, &attempts);

	if(attempts > maxAttempts){
		fprintf( stderr, "Troppi tentativi per questo subtask.\n");
		fprintf( stdout, "%.1f\n", 0.0);
		return 0;
	}

	for(i = 0; i < 4; i++){
		fscanf(stm, "%d", &tmp);
		if(tmp != codice[i]){
			fprintf( stderr, "Soluzione non corretta.\n");
			fprintf( stdout, "%.1f\n", 0.0);
			return 0;
		}
	}
	
	fclose(stm); 
	
	fprintf( stderr, "Soluzione corretta.\n");
	fprintf( stdout, "%.1f\n", 1.0);
	
	
	return 0;
	
}
