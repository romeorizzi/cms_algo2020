// Soluzione greedy di somme:
// prende la somma con valore assoluto minimo e la esegue
// fino alla fine della sequenza, quindi restituisce il
// massimo valore assoluto ottenuto
//
// Maurizio

#include <iostream>
#include <cassert>
#include <cmath>
#include <climits>

using namespace std;

inline int abs(int x) {
	return (x < 0 ? -x : x);
}

const int MaxN = 5000;
int N;

int V[MaxN];

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> N;

  assert( 2 <= N && N <= MaxN );

  for( int i = 0; i < N; ++i ) {
    cin >> V[i];
  }

  int sol = 0;

  // esegue N-1 somme
  for( int i = 0; i < N - 1; ++i ) {
    int M = N - i;
    
    int pi = 0;
    int pv = abs( V[0] + V[1] );

    // sceglie la somma meno costosa
    for( int j = 1; j < M - 1; ++j ) {
      int v = abs( V[j] + V[j+1] );
      if( v < pv ) {
	pi = j;
	pv = v;
      }
    }

    // esegue la somma e sposta tutti i numeri da destra
    // verso sinistra
    V[pi] += V[pi+1];
    for( int i = pi+1; i < M - 1; ++i ) {
      V[i] = V[i+1];
    }

    sol = max( sol, pv );    
  }

  // risolve e scrive l'output
  cout << sol << endl;
}
