/*
 * SOLUZIONE UFFICIALE - task pazzo
 * Complessità temporale O(M)
 * Complessità in memoria O(1)
 * 
 * Alessio Mazzetto
 */ 

#include <iostream>
#include <fstream>
using namespace std;
int N;
int b[1500];

#ifdef EVAL
ifstream in;
ofstream out;
#else
#define in cin
#define out cout
#endif
void stampa(int q){
	out << "[" ;
	for(int i = 0; i < 1 + (q-1)*3; ++i)
		out << "O";
	out << "]";
}

void print(int pos, int q){
	if(pos > N) return;
	if(pos == N){ 
		for(int i = 0; i < q; ++i)
			stampa(b[i]);
		out << endl;
	}
	b[q] = 1;
	print(pos+1,q+1);
	b[q] = 2;
	print(pos+2,q+1);
}

int main() {
	#ifdef EVAL	
	in.open("input.txt");
	out.open("output.txt");
	#endif
	in >> N;
	print(0,0);
}
