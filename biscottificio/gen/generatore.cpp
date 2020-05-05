/*
 * GENERATORE task biscottificio
 * Usage: ./generatore N seed
 *  N >= 1, il numero di lotti da pianificare
 *
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
