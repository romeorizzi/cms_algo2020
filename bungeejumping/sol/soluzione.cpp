/**
 *  Soluzione di bungeejumping
 *
 *  Autore: Romeo Rizzi, 2018-03-20
 *
 *  Costo di questa soluzione: n log n.
 *
 *  Tecnica: binary search sul valore di delta
 * 
 */

#include <cassert>
#include <cstdio>
#include <algorithm>

using namespace std;


#define MAXN 500
#define MAXVAL 1000000

int N;
int v[MAXN]; // vettore in input


int is_connected(int delta) {
  // ritorna 1 se l'omino riesce a portarsi dalla cella 0 alle cella N-1
  // per il valore di tolleranza delta ricevuto come parametro;
  // ritorna 0 altrimenti.
  int reached[MAXN] = {0};
  int FIFOq[MAXN], posW = 0, posR = 0;

  reached[0] = 1; FIFOq[posW++] = 0;
  while (posR < posW) {
    //printf("posR = %d posW = %d\n", posR, posW);
    //for(int i = 0; i < posW; i++) {
    //  printf("FIFOq[%d] = %d\n", FIFOq[i], i);
    //}
    
    int i = FIFOq[posR++];
    for(int jump = v[i]; jump >= max(1, v[i]-delta); jump--) {
      for(int j=i-jump; j <= i+jump; j += 2*jump) {
	if( (j >= 0) && ( j<N ) && (reached[j] == 0) ) {
           reached[j] = 1; FIFOq[posW++] = j;
	}
      }	
    }  
  }
  return reached[N-1];
}

int min_delta(int left, int right) {
  // ritorna il piu' piccolo valore di delta > left tale che is_connected(delta == true) con la garanzia che is_connected(right == true)
  assert( right > left );

  //  printf("left = %d right = %d\n", left, right);
  
  if(right == left + 1)
    return right;
  assert(right >= left+2);
  int mid = (left+right)/2;
  assert(mid > left);
  assert(mid < right);
  if(is_connected(mid))
    return min_delta(left, mid);
  else
    return min_delta(mid, right);
}


int main() {
#ifdef EVAL
    assert( freopen("input.txt", "r", stdin) );
    assert( freopen("output.txt", "w", stdout) );
#endif
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
	assert( v[i] > 0 );
    }
    
    int risp = min_delta(-1, MAXVAL);

    printf("%d\n", risp);
    
    return 0;
}

