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
 * Alice Cortinovis
 *
 * MST con algoritmo di Kruskal
 */

#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <fstream>
#include <stdio.h>

#define MAXN 10001
#define MAXM 1000000

using namespace std;

struct archi{
    int a, b;
    long long w;
};

vector< pair<int, long long int> > G[MAXN];
archi ARCHI[MAXM];
long long sol;
vector<pair<int, int> > archi_sol;
// int N, M;
int p[MAXN];

bool comp(archi x, archi y) {
    if (x.w != y.w) return (x.w < y.w);
    if (x.a != y.a) return (x.a < y.a);
    return (x.b < y.b);
}

int FIND(int x) {
    if (x == p[x]) return x;
    else return p[x] = FIND(p[x]);
}

void UNION(int x, int y) {
    int px = FIND(x);
    int py = FIND(y);
    if (px == py) return;
    p[px] = py;
}

int mst(int N, int M, int A[], int B[], int P[], int C[], int D[]) {
    ::N = N;
    ::M = M;
    for (int i=0; i<M; i++) {
        ARCHI[i].a = A[i];
        ARCHI[i].b = B[i];
        ARCHI[i].w = P[i];
        G[ARCHI[i].a].push_back(make_pair(ARCHI[i].b, ARCHI[i].w));
        G[ARCHI[i].b].push_back(make_pair(ARCHI[i].a, ARCHI[i].w));
    }
    sort(ARCHI, ARCHI+M, comp);
    for (int i=0; i<N; i++) p[i] = i;
    for (int i=0; i<M; i++) {
        if (FIND(ARCHI[i].a) != FIND(ARCHI[i].b)) {
            UNION(ARCHI[i].a, ARCHI[i].b);
            sol = sol + ARCHI[i].w;
            archi_sol.push_back(make_pair(ARCHI[i].a, ARCHI[i].b));
        }
    }

    for (int i=0; i<(int)archi_sol.size(); i++) {
        C[i] = archi_sol[i].first;
        D[i] = archi_sol[i].second;
    }

    return sol;
}
