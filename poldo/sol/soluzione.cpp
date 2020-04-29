/*
 * SOLUZIONE task poldo
 * Alessio Mazzetto boss :P
 */ 

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

const int MAXN = 10005;
const int MAXW = 10005;
// il peso dei panini
int pesi[MAXN];
int LIS[MAXN],q;
int N;
int main() {
//	#ifdef EVAL
	ifstream in("input.txt");
	ofstream out("output.txt");
//	#else
//	#define in cin
//	#define out cout
//	#endif
	
	in >> N;
	for (int i = 0; i < N; i++)
		in >> pesi[i];
	reverse(pesi,pesi+N);
	
	for(int i = 0; i < N; ++i){
		int pos = lower_bound(LIS,LIS+q,pesi[i]) - LIS;
		if( pos == q) q++;
		LIS[pos] = pesi[i];
	}
	out << q << endl;

	return 0;
}
