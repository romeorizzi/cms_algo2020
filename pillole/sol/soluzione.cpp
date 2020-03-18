/**
 *  Soluzione ufficiale di pillole
 *  tecnica: ricorsione con memoizzazione
 *  ultima revisione: Romeo Rizzi, 2020.03.18
 */
#include <iostream>
using namespace std;

const int MAXN;
int N;

#define lint long long int 

lint memo[MAXN+1][MAXN+1];

lint compute(int I,int M){
  //Ritorna il numero di modi diversi di svuotare un flaconcino che inizialmente contenga I pillole intere e M pillole mezze.  
  if(I==0)
    return 1;
  if(M<0)
    return 0;
  if(memo[I][M]==0)
    memo[I][M] = compute(I-1,M+1) + compute(I,M-1);
  return memo[I][M];
}

int main(){
  in >> N;
  out << compute(N,0) << endl;
  return 0;
}
