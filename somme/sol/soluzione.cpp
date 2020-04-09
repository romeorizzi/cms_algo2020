// Soluzione con memoization di somme
//
// Maurizio

#include <iostream>
#include <cassert>
#include <cmath>
#include <climits>

using namespace std;

const int MaxN = 5000;
int N;

int V[MaxN];
int S[MaxN][MaxN];
int inc[MaxN+1];  // somme parziali V[0, i]

inline int somma( int start, int end );
int risolvi( int start, int end );

inline int abs(int x) {
	return (x < 0 ? -x : x);
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  // lettura dell'input
  cin >> N;

  assert( 2 <= N && N <= MaxN );

  inc[0] = 0;
  for( int i = 0; i < N; ++i ) {
    cin >> V[i];
    inc[i+1] = inc[i] + V[i];
  }

  // inizializza la cache
  for( int i = 0; i < N; ++i ) {
    for( int j = 0; j < N+1; ++j ) {
      S[i][j] = -1;
    }
  }

  // risolve e scrive l'output
  cout << risolvi( 0, N ) << endl;
}

inline int somma( int start, int end )
{
  return inc[end] - inc[start];
}

int risolvi( int start, int end )
{
  if( start + 1 >= end ) {
    return 0;
  } else if( start + 2 == end ) {
    return abs( V[start] + V[start+1] );
  } else if( S[start][end] != -1 ) {
    return S[start][end];
  } else {
    int sol = INT_MAX;

    for( int i = start + 1; i < end; ++i ) {
      int r = max( risolvi( start, i ), risolvi( i, end ) );
      sol = min( sol, r ); 
    }
    sol = max( sol, abs( somma( start, end ) ) );
    S[start][end] = sol;
    return sol;
  }
}
