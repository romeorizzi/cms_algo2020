//Nicoletta: 3287595040
//Francesco: 3356783862

//#define NDEBUG
#include<cassert>
#include<fstream>
#ifndef NDEBUG
   #include<iostream>
#endif

using namespace std;

const int UNKNOWN = -1;
const int MAX_N = 100; int n;
int t[MAX_N][MAX_N];
int memoRisp[MAX_N+1][MAX_N+1];

int mymax(int a, int b) {
   if( a < b ) return b;
   else return a;
}

void displayTriangle() {
  for(int i = 0; i < n; i++) {
     for(int j = 0; j <= i; j++)
        cout << t[i][j] << " ";
    cout << endl;
  }
}

int maxPathFrom(int r, int c) {
/* ritorna il massimo peso di un cammino che parta da (r,c)
   e scenda fino all'ultima riga del triangolo
*/
 if( r >= n ) return 0;
 if( memoRisp[r][c] != UNKNOWN )  return memoRisp[r][c];
 return memoRisp[r][c] = t[r][c] + mymax( maxPathFrom(r+1, c), maxPathFrom(r+1, c+1) );
}

int main() {
  ifstream fin("input.txt"); assert( fin );
  fin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j <= i; j++)
       fin >> t[i][j];
  fin.close();

//  displayTriangle();
  for(int i = 0; i < n; i++)
    for(int j = 0; j <= i; j++)
       memoRisp[i][j] = UNKNOWN;


  for(int j = 0; j <= n; j++)
     memoRisp[n][j] = 0;
  for(int i = n-1; i >= 0; i--)
    for(int j = 0; j <= i; j++)
       memoRisp[i][j] = t[i][j] + max( memoRisp[i+1][j], memoRisp[i+1][j+1] );

  ofstream fout("output.txt"); assert( fout );
//  fout << maxPathFrom( 0, 0 ) << endl;
  fout << memoRisp[0][0] << endl;
  fout.close();

  return 0;
}
