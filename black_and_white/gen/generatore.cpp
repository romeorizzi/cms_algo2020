/*
GENERATORE task black_and_white

arg1 --> N
arg2 --> MAX_M
arg3 --> SEED
[arg 4] --> PROBABILITY

Special usage:
arg1 --> 0, all zero query. max M
arg1 --> 1, almost all 1 query (only one zero at the end). max M

*/

#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

#define MAXN 100000

int PROBABILITY = 70;

int main(int argc, char** argv) {
	assert(argc >= 2);
	int temp;
	if(argc == 2) {
		assert(argv[1][0] == '0' || argv[1][0] == '1');
		cout << MAXN << endl;
		
		if(argv[1][0] == '0') srand(12345);
		else srand(54321);

		for (int i = 0; i < MAXN; i++) {
			temp = rand() % 100;
			if(temp < PROBABILITY) {
				cout << 1 << " ";
			} else {
				cout << 0 << " ";
			}
		}
		cout << endl << MAXN << endl;
		if(argv[1][0] == '0') {
			for(int i = 0; i < MAXN; i++) {
				temp = (rand() % MAXN);
				cout << 0 << " " << temp + 1 << " ";
				cout << (temp + 1 + (rand() % (MAXN - temp))) << endl;
			}

		} else {
			for(int i = 0; i < MAXN - 1; i++) {
				temp = (rand() % MAXN);
				cout << 1 << " " << temp + 1 << " ";
				cout << (temp + 1 + (rand() % (MAXN - temp))) << endl;
			}
			temp = (rand() % MAXN);
			cout << 0 << " " << temp + 1 << " ";
			cout << (temp + 1 + (rand() % (MAXN - temp))) << endl;
		}
		return 0;
	}
	assert(argc >= 4);
	int N = atoi(argv[1]);
	int M = atoi(argv[2]);
	int seed = atoi(argv[3]);
	assert(N > 0 && M > 0 && seed >= 0);
	if(argc == 5) {
		PROBABILITY = atoi(argv[4]);
		assert(PROBABILITY > 0);
	}
	
	srand(seed);
	cout << N << endl;
	for (int i = 0; i < N; i++) {
		temp = rand() % 100;
		if(temp < PROBABILITY) {
			cout << 1 << " ";
		} else {
			cout << 0 << " ";
		}
	}
	
	int maxM = M/2 + (rand() % (M/2 + 1));
	cout << endl << maxM << endl;
	
	for (int i = 0; i < maxM - 1; i++) {
		temp = (rand() % N);
		cout << (rand() & 1) << " " << temp + 1 << " ";
		cout << (temp + 1 + (rand() % (N - temp))) << endl;
	}
	temp = (rand() % N);
	cout << 0 << " " << temp + 1 << " ";
	cout << (temp + 1 + (rand() % (N - temp))) << endl;
	return 0;
}
