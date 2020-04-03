#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main( int argc, char *argv[] ) {
	if (argc != 4) {
		fprintf( stderr, "Numero di argomenti errato.\n");
		exit( EXIT_FAILURE );
	}
	
	//FILE *input = fopen(argv[1], "r");
	FILE *uff = fopen(argv[2], "r");
	FILE *stm = fopen(argv[3], "r");

	int i, tmp;
	
	// legge la soluzione ufficiale
	int umaxCompare, uCompare;
	fscanf(uff, "%d %d", &umaxCompare, &uCompare);
	vector<int> soluff;	
	while (!feof(uff)) {
		fscanf(uff, "%d", &tmp);
		soluff.push_back(tmp);
	}
	fclose(uff);
	
	// legge la soluzione sottomessa
	int maxCompare, compare;
	
	fscanf(stm, "%d %d", &maxCompare, &compare);

	if(compare > maxCompare){
		fprintf( stderr, "Troppi tentativi per questo subtask.\n");
		fprintf( stdout, "%.1f\n", 0.0);
		return 0;
	}

	i = 0;
	while (!feof(stm)) {
		fscanf(stm, "%d", &tmp);
		if(tmp != soluff.at(i)) {
			fprintf( stderr, "Soluzione non corretta.\n");
			fprintf( stdout, "%.1f\n", 0.0);
			return 0;
		}
		i++;
	}
	fclose(stm); 
	
	fprintf( stderr, "Soluzione corretta.\n");
	fprintf( stdout, "%.1f\n", 1.0);
	
	
	return 0;
	
}
