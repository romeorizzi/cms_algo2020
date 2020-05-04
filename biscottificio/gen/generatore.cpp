/*
 * GENERATORE task poldo
 * Usage: ./generatore N maxW seed
 *  N >= 1, il numero di panini
 *  maxW >= 0, i valori degli N panini saranno tutti compresi tra 0 e maxW
 *  Casi Particolari:
 *      se N==-2 allora si genera la sequenza 1 2 ... 1000
 *      se N==-1 allora si genera la sequenza 1000 999 ... 1
 */ 

#include <iostream>
#include <cassert>
#include <cstdlib>

#define REAL_MAX 1000000

using namespace std;

int main(int argc, char** argv) {
	assert(argc == 3);
	int N = atoi(argv[1]);
	int seed = atoi(argv[2]);
	srand(seed);
	cout << N << endl;
	for (int i = 0; i < N; i++)
	  cout << rand() % 10 << endl;
	return 0;
}
