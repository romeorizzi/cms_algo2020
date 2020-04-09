// Soluzione mangiapunti di somme:
// restituisce la somma dei numeri
//
// Maurizio

#include <iostream>
#include <cassert>

using namespace std;

const int MaxN = 5000;
int N;

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  cin >> N;

  assert( 2 <= N && N <= MaxN );

  int somma = 0;
  for( int i = 0; i < N; ++i ) {
    int a;
    cin >> a;
    somma += a;
  }

  cout << somma << endl;
}
