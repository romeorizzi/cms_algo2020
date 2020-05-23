#include <cstdio>
#include <cassert>
#include <cstdlib>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int M;
static int* A;
static int* B;
static int* P;
static int* C;
static int* D;
static int minimo;

// Declaring functions
int mst(int N, int M, int* A, int* B, int* P, int* C, int* D);

int main() {
	fr = stdin;
	fw = stdout;

	// Reading input
	fscanf(fr, " %d %d", &N, &M);
	A = (int*)malloc((M) * sizeof(int));
	B = (int*)malloc((M) * sizeof(int));
	P = (int*)malloc((M) * sizeof(int));
	for (int i0 = 0; i0 < M; i0++) {
		fscanf(fr, " %d %d %d", &A[i0], &B[i0], &P[i0]);
	}

	// Calling functions
	C = (int*)malloc((N-1) * sizeof(int));
	D = (int*)malloc((N-1) * sizeof(int));
	minimo = mst(N, M, A, B, P, C, D);

	// Writing output
	fprintf(fw, "%d\n", minimo);
	for (int i0 = 0; i0 < N-1; i0++) {
		fprintf(fw, "%d %d\n", C[i0], D[i0]);
	}

	fclose(fr);
	fclose(fw);
	return 0;
}

/*
  Giovanni Campagna <scampa.giovanni@gmail.com>

  Minimum Spanning Tree - implementazione con Prim
*/

#include <cassert>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

const int N_MAX = 10000;
const int M_MAX = 10000000;
const int W_MAX = numeric_limits<int>::max();

// int N, M;
typedef vector<pair<int, int> > vicini_t;
typedef vector<vicini_t> lista_vicini_t;
lista_vicini_t lista_vicini;
vector<bool> visto;
int wsol;
stack<pair<int, int> > soluzione;

void prim() {
  priority_queue<pair<int, pair<int, int> > > coda;

  coda.push(make_pair(0, make_pair(0, -1)));
  while (!coda.empty()) {
    const pair<int, pair<int, int> >& e(coda.top());
    int peso = -e.first;
    int nodo = e.second.first;
    int from = e.second.second;

    coda.pop();
    if (visto[nodo])
      continue;

    visto[nodo] = true;
    wsol += peso;
    if (from != -1)
      soluzione.push(make_pair(from, nodo));

    const vicini_t& vicini(lista_vicini[nodo]);
    for (vicini_t::const_iterator i(vicini.begin()); i != vicini.end(); ++i) {
      int figlio = i->first;
      int peso = i->second;
      if (figlio != from && !visto[figlio])
	coda.push(make_pair(-peso, make_pair(figlio, nodo)));
    }
  }
}

int mst(int N, int M, int A[], int B[], int P[], int C[], int D[]) {
  ::N = N;
  ::M = M;

  assert (N >= 1 && N <= N_MAX);
  assert (M >= 2 && M <= M_MAX);

  lista_vicini.resize(N);
  visto.resize(N, false);
  for (int i(0); i < M; i++) {
    lista_vicini[A[i]].push_back(make_pair(B[i], P[i]));
    lista_vicini[B[i]].push_back(make_pair(A[i], P[i]));
  }

  prim();

  assert (wsol <= W_MAX);

 /* int x = 0;
  while(!soluzione.empty()) {
    const pair<int, int>& arco(soluzione.top());
    C[x] = arco.first;
    D[x] = arco.second;
    x++;
    soluzione.pop();
  }*/

  return wsol;
}

