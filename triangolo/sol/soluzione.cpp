/*
 * SOLUZIONE task triangolo
 * Edoardo Morassutto
 */ 

#include <iostream>
#include <fstream>

using namespace std;
// il triangolo tutto in una riga
// x|xx|xxx|xxxx|xxxxx|.......
int tri[5100];
// programmazione dinamica! memorizzo il massimo dalla cella i alla fine
int sol[5100];
// N numero di livelli, c lunghezza del vettore = (N*(N+1)/2)
int N, c;

// ritorna il costo massimo dal nodo i (nel livello l) fino alla fine
int solve(int i, int l) {
	// se è l'ultimo livello ritorno il peso del nodo
	if (i >= c-N) return tri[i];
	// se l'ho gia calcolato
	if (sol[i] != 0) return sol[i];
	// il massimo tra prendere quello a sinistra e quello a destra
	int res = max(
		solve(i+l+1, l+1), 
		solve(i+l+2, l+1));
	// a cui aggiungo il peso del nodo
	return sol[i] = res+tri[i];
}

int main() {
	#ifdef EVAL
	ifstream in("input.txt");
	ofstream out("output.txt");
	#else
	#define in cin
	#define out cout
	#endif
	
	in >> N;
		
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			in >> tri[c++];
	// inizio dal nodo 0 e livello 0
	out << solve(0, 0);
	return 0;
}
