/*
 * SOLUZIONE UFFICIALE - piastrelle2
 * Complessità temporale O(NK) dove N=size del corridoio e K=num piastrellature
 * Complessità in memoria O(N)
 * 
 * Romeo Rizzi
 */ 

#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

const int MAXN = 25;
int N;
int p[2][MAXN+1]; // p[0][n] = p[0][n] = 0 servono come sentinella.


int smallestDiff(int a) { return ( a != 1 )? 1 : 2; }
int smallestDiff(int a, int b) {
     if( (a != 1) && (b != 1) )
        return 1;
     else if( (a != 2) && (b != 2) )
        return 2;
     else
        return 3;
} // overloaded
int smallestDiff(int a, int b, int c) {
     if( (a != 1) && (b != 1) && (c != 1) )
        return 1;
     else if( (a != 2) && (b != 2) && (c != 2) )
        return 2;
     else if( (a != 3) && (b != 3) && (c != 3) )
        return 3;
     else return 4;
} // overloaded


void print() {
  for(int j = 0; j < 2; j++) {
     for(int i = N-1; i >= 0; i--)
        cout << p[j][i] << " ";
     cout << endl;
  }
  cout << endl;
}
/* spiegazione sul verso rovesciato di print:
   le celle di p[2][n+1] sono numerate:
   2 4 6 8     2n  2n+2
   1 3 5 7    2n-1 2n+1  
   (le celle p[0][n] = p[0][n] = 0 nella colonna a destra
    servono come sentinella).
   La cella che decide per prima (quella su cui avviene la decomposizione
   ricorsiva dello spazio delle piastrellature, e' quella ad etichetta
   maggiore).
   Dobbiamo quindi invertire destra/sinistra nella stampa se vogliamo
   perseguire l'ordine nell'esempio del testo.
*/

int nSol1SbeccatoTop(int n);
int nSol1SbeccatoBottom(int n);
int nSol2SbeccatoTop(int n);
int nSol2SbeccatoBottom(int n);

int nSol(int n) {
  assert( n >= 0 );
  if( n == 0 )  return 1;
  if( n == 1 )  return 2;

// ho tre ipotesi su come coprire la cella in alto a destra:
  return     nSol1SbeccatoTop(n) + nSol2SbeccatoTop(n)  +          nSol(n-1);
//le 3 hps:  uso piastrella 1x1    uso piastrella 1x2    uso piastrella 2x1
}

int nSol1SbeccatoTop(int n) {
  assert( n >= 1 );
  if( n == 1 )  return 1;

// ho due ipotesi su come coprire la cella in basso a destra:
  return              nSol(n-1) + nSol1SbeccatoBottom(n-1);
//le 2 hps:  uso piastrella 1x1         uso piastrella 1x2
}

int nSol1SbeccatoBottom(int n) {
  assert( n >= 1 );
  if( n == 1 )  return 1;

// ho due ipotesi su come coprire la cella in alto a destra:
  return              nSol(n-1) + nSol1SbeccatoTop(n-1);
//le 2 hps:  uso piastrella 1x1      uso piastrella 1x2
}

int nSol2SbeccatoTop(int n) {
  assert( n >= 2 );

// ho due ipotesi su come coprire la cella in basso a destra:
  return  nSol1SbeccatoTop(n-1)  +           nSol(n-2);
//le 2 hps:  uso piastrella 1x1     uso piastrella 1x2
}

int nSol2SbeccatoBottom(int n) {
  assert( n >= 2 );

// ho due ipotesi su come coprire la cella in alto a destra:
  return  nSol1SbeccatoBottom(n-1)  +           nSol(n-2);
//le 2 hps:     uso piastrella 1x1     uso piastrella 1x2
}


void listaPiastrellature1SbeccatoTop(int n);
void listaPiastrellature1SbeccatoBottom(int n);
void listaPiastrellature2SbeccatoTop(int n);
void listaPiastrellature2SbeccatoBottom(int n);

void listaPiastrellature(int n) {
  assert( n >= 0 );
  if( n == 0 ) { print(); return; }
// ho tre ipotesi su come coprire la cella in alto a destra:
    p[0][n-1] = smallestDiff(p[0][n]); 
    listaPiastrellature1SbeccatoTop(n); //uso piastrella 1x1
    if( n > 1 ) { // posso collocarla orizzontale, ma solo se ho spazio
       p[0][n-2] = p[0][n-1]; 
       listaPiastrellature2SbeccatoTop(n); //uso piastrella 1x2
    }
    p[0][n-1] = p[1][n-1] = smallestDiff(p[0][n],p[1][n]);
    listaPiastrellature(n-1); //uso piastrella 2x1
}

void listaPiastrellature1SbeccatoTop(int n) {
  assert( n >= 1 );
  if( n == 1 )  { p[1][0] = smallestDiff(p[0][0],p[1][1]); print(); return; }

// ho due ipotesi su come coprire la cella in basso a destra:
  p[1][n-1] = smallestDiff(p[0][n-1],p[1][n]); 
  listaPiastrellature(n-1); //uso piastrella 1x1
  p[1][n-2] = p[1][n-1];
  listaPiastrellature1SbeccatoBottom(n-1); //uso piastrella 1x2
}

void listaPiastrellature1SbeccatoBottom(int n) {
  assert( n >= 1 );
  if( n == 1 )  { p[0][0] = smallestDiff(p[1][0],p[0][1]); print(); return; }

// ho due ipotesi su come coprire la cella in alto a destra:
  p[0][n-1] = smallestDiff(p[1][n-1], p[0][n]); 
  listaPiastrellature(n-1); //uso piastrella 1x1
  p[0][n-2] = p[0][n-1];
  listaPiastrellature1SbeccatoTop(n-1); //uso piastrella 1x2
}

void listaPiastrellature2SbeccatoTop(int n) {
  assert( n >= 2 );
// ho due ipotesi su come coprire la cella in basso a destra:
  p[1][n-1] = smallestDiff(p[0][n-1], p[1][n]);   
  listaPiastrellature1SbeccatoTop(n-1); //uso piastrella 1x1
  p[1][n-2] = p[1][n-1] = smallestDiff(p[0][n-2], p[0][n-1], p[1][n]);   
  listaPiastrellature(n-2); //uso piastrella 1x2
}

void listaPiastrellature2SbeccatoBottom(int n) {
  assert( n >= 2 );
// ho due ipotesi su come coprire la cella in alto a destra:
  p[0][n-1] = smallestDiff(p[1][n-1], p[0][n]);   
  listaPiastrellature1SbeccatoBottom(n-1); //uso piastrella 1x1
  p[0][n-2] = p[0][n-1] = smallestDiff(p[1][n-2], p[1][n-1], p[1][n]);   
  listaPiastrellature(n-2); //uso piastrella 1x2
}


int main() {
   #ifdef EVAL
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
   #endif

   cin >> N;
   cout << nSol(N) << endl;
   listaPiastrellature(N);
}
