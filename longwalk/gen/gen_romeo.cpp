/* FILE: randQuasiTournament.cpp  last change: 5-Sept-2012  author: Romeo Rizzi
 * randomly generates a DAG if dag=1, a digraph with an unique dicircuit if dag=0.
 * Usage syntax:
 *   > randQuasiTournament out_file n m dag seed
 */

#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_N =  100000; int n; // numero nodi.
const int MAX_M = 1000000; int m; // numero archi.
bool dag; // =true se e' richiesto di generare un DAG, false altrimenti.
int perm_n[MAX_N+1], perm_m[MAX_M+1]; // nodi ed archi sono numerati partendo da 1 
const int TAIL=0, HEAD=1;
int arc[MAX_M +1][2]; // l'arco j-esimo e' (arcs[j][TAIL], arcs[j][HEAD])

// perm_n ci viene utile per permutare i nodi solo alla fine, appena prima dell'output. E con perm_m permutiamo gli archi.

inline void swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }

void generaPerm_random_uniform(int *perm, int n) {
   for(int i=n; i > 1; i--)
     swap( perm[i], perm[ (rand() % i) + 1 ] );
}

int RandNumber(int min, int max) {
  /* returns an integer in [min, max]
   * see Stroustrup "The c++ Programming Language" 3th edition pg. 685
   * for comments on the following manipulation choice.
   * In particular, considerations on the bad quality of low bits come into account.
   */
 return min + (int) ( (max-min) * (double(rand()) / RAND_MAX) );
}

int main(int argc, char** argv) {
  n = atoi(argv[1]); m = atoi(argv[2]); dag = atoi(argv[3]);
  srand(time(NULL));  if(argc > 4) srand( atoi(argv[4]) );

  if(dag)
    for(int j = 1; j <= m; j++) {
      int a = RandNumber(1,n); int b = RandNumber(a+1,n); 
      arc[j][TAIL] = a; arc[j][HEAD] = b;
    } // abbiamo generato un DAG compatibile al total order 1,2,3, ..., n
  else {
    int min_node_circ = n/3+1, max_node_circ = 2*n/3+1;
    assert( min_node_circ > 1 ); assert( min_node_circ < max_node_circ ); assert( max_node_circ < n ); 
    int j = 1;
    for(int v = min_node_circ; v < max_node_circ; v++, j++) {
      arc[j][TAIL] = v; arc[j][HEAD] = v+1;
    }
    arc[j][TAIL] = max_node_circ; arc[j++][HEAD] = min_node_circ;
    for( ; j <= m; j++) {
      int a = RandNumber(1,n); int b = RandNumber(a+1,n);
      if( ( a >= min_node_circ ) & ( a <= max_node_circ ) ) {
	if (RandNumber(0,1))  a = RandNumber(1,min_node_circ-1);
        else  b = RandNumber(max_node_circ+1,n);
      }
      arc[j][TAIL] = a; arc[j][HEAD] = b;
    }    
  }

  for(int i = 1; i <= n; i++)  perm_n[i] = i;
  generaPerm_random_uniform(perm_n, n);
  for(int i = 1; i <= m; i++)  perm_m[i] = i;
  generaPerm_random_uniform(perm_m, m);

  cout << n << " " << m << endl;
  for(int j = 1; j <= m; j++)
      cout << perm_n[ arc[perm_m[j]][TAIL] ] << " " << perm_n[ arc[perm_m[j]][HEAD] ] << endl;

  return 0;
}
