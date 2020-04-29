/*
 * SOLUZIONE task poldo
 * Edoardo Morassutto
 */ 

#include <iostream>
#include <fstream>
using namespace std;

const int MAXN = 10005;
const int MAXW = 10005;
// il peso dei panini
int pesi[MAXN];
// il numero di panini che mangio se prendo l'i-esimo panino
int res[MAXN];

int N;
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
		in >> pesi[i];
	
	// sicuramente almeno un panino lo mangia
	int sol = 1;
	// parto dall'ultimo
	for (int i = N-1; i >= 0; i--) {		
		res[i] = 0;
		// controllo tra i panini successivi quali posso prendere
		for (int j = i; j < N; j++) 
			// li posso prendere se rispettano la dieta e se sono vantaggiosi
			if (pesi[i] > pesi[j] && res[i] < res[j])
				res[i] = res[j];
		// prendo il panino corrente
		res[i]++;
	}
	// cerco il massimo numero di panini
	for (int i = 0; i < N; i++)
		sol = max(sol, res[i]);
	out << sol;
	return 0;
}
