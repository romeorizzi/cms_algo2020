/*
 * Soluzione (ricorsione con memoizzazione) di piastrelle_count, written by Romeo Rizzi 2022.03.26
 */ 

#include <iostream>
#include <fstream>
using namespace std;

#define in cin
#define out cout

const int MAXN = 1000;
int MEMOrisp[MAXN+1];

int N;

int risp(int n) {
  if(MEMOrisp[n]==0)
    if(n<=1)
      MEMOrisp[n] = 1;
    else
      MEMOrisp[n] = risp(n-1)+risp(n-2);
  return MEMOrisp[n];
}

int main() {
  in >> N;
  cout << risp(N) << endl;
}
