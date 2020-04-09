#include <iostream>
#include <fstream>

using namespace std;

const int MAXN = 105;

char mappa[MAXN][MAXN];

int N, M;

int solve(int x, int y) {
	if (x == M-1 && y == N-1)
		return 1;
	if (x >= M || y >= N)
		return 0;
	int sum = 0;
	if (mappa[x+1][y] == '*')
		sum += solve(x+1, y);
	if (mappa[x][y+1] == '*')
		sum += solve(x, y+1);
	return sum;
}

int main() {
	#ifdef EVAL
	ifstream in("input.txt");
	ofstream out("output.txt");
	#else
	#define in cin
	#define out cout
	#endif
	
	in >> N >> M;
	
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			in >> mappa[j][i];
	
	out << solve(0, 0) << endl;
}
