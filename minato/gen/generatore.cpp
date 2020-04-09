/*
 * GENERATORE task minato
 */ 

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;


int N, M;
char D[105][105];

void genera(int theta) {
	int i = 0, j = 0;
	while (i != N && j != M) {
		int r = rand() % 1000;
		if (r<theta && i < N) {
			i++;
			D[i][j] = '*';
		}
		else if (r >= theta && j < M) {
			j++;
			D[i][j] = '*';
		}
		if (i == N-1 || j == M-1)
			break;
	}
	if (i == N-1)
		for (; j < M; j++)
			D[i][j] = '*';
	else
		for (; i < N; i++)
			D[i][j] = '*';
}

int main(int argc, char** argv) {
	N = atoi(argv[1]);
	M = atoi(argv[2]);
	int seed = atoi(argv[3]);
	srand(seed);
    
    for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			D[i][j] = '+';
	D[0][0] = '*';
	
	int nperc = N/M*3+1;
	
	for (int i = 0; i < nperc; i++)
		genera(rand()%1000);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (rand() % 100 < 15)
				D[i][j] = '*';
	
	cout << N << " " << M << endl;
	for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j)
            cout  << D[i][j];
        cout << endl;
	}
	return 0;
}
