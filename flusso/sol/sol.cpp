/*
  Giovanni Campagna <scampa.giovanni@gmail.com>

  Calcolo del flusso massimo in una rete
*/

#include <cassert>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <limits>
#include <algorithm>
#include <numeric>
#include <map>

using namespace std;

#ifdef EVAL
ifstream in("input.txt");
ofstream out("output.txt");
#else
istream &in(cin);
ostream &out(cout);
#endif

const int N_MAX = 10000;
const int M_MAX = 10000000;
const int W_MAX = numeric_limits<int>::max();

int N, M;

/*
struct arco {
  int to;
  int peso;
  int flusso;
  bool operator<(const arco& oth) const {
    return to < oth.to;
  }
};

int operator+(int v, const arco& a) {
  return v + a.flusso;
}
*/

// nodo -> (peso, flusso)
typedef map<int, pair<int, int> > vicini_t;
typedef vector<vicini_t> lista_vicini_t;
lista_vicini_t grafo;

// sentinelle: radice -1, sconosciuto -2
vector<int> padre_cammino;

int maxflusso;

int cammino_aumentante(int source, int target) {
  queue<pair<int, pair<int, int> > > coda;
  vector<int> maxcammino(N, 0);
  fill(padre_cammino.begin(), padre_cammino.end(), -2);

  coda.push(make_pair(source, make_pair(-1, numeric_limits<int>::max())));
  while(!coda.empty()) {
    const pair<int, pair<int, int> > &e(coda.front());
    int nodo = e.first;
    int padre = e.second.first;
    int flusso = e.second.second;

    coda.pop();

    // ignoro i nodi già visti e in particolare i cicli che contengono la sorgente
    if (padre_cammino[nodo] != -2)
      continue;

    padre_cammino[nodo] = padre;

    if (nodo == target)
      return flusso;

    vicini_t& vicini(grafo[nodo]);
    for (vicini_t::const_iterator i(vicini.begin()); i != vicini.end(); ++i) {
      // const arco &a (*i);
      const pair<int, int>& arco(i->second);
      if (arco.first > 0)
	coda.push(make_pair(i->first, make_pair(nodo, min(flusso, arco.first))));
    }
  }

  return 0;
}

/*
arco &get_arco(int da, int a) {
  arco key = { a, 0, 0 };
  vicini_t::iterator i(lower_bound(grafo[da].begin(), grafo[da].end(), key));

  assert(i != grafo[da].end());
  return *i;
}
*/

int acc_f(int v, const pair<int, pair<int, int> >& map_value) {
  return v + map_value.second.second;
}

int flusso(int source, int target) {
  while (true) {
    int cammino = cammino_aumentante(source, target);

    if (cammino == 0)
      break;

    int nodo = target;
    int padre = padre_cammino[nodo];
    while (padre != -1) {
      pair<int, int>& diretto(grafo[padre][nodo]);
      diretto.second += cammino;
      diretto.first -= cammino;
      assert(diretto.first >= 0);

      pair<int, int>& inverso(grafo[nodo][padre]);
      inverso.first += cammino;

      nodo = padre;
      padre = padre_cammino[nodo];
    }
  }

  const vicini_t& vicini(grafo[source]);
  return accumulate(vicini.begin(), vicini.end(), 0, acc_f);
}

int
main(void)
{
  int S, T;

  in >> N >> M;
  in >> S >> T;

  assert (N >= 1 && N <= N_MAX);
  assert (M >= 2 && M <= M_MAX);
  assert (S >= 1 && S <= N);
  assert (T >= 1 && T <= N);

  grafo.resize(N);
  padre_cammino.resize(N);

  for (int i(0); i < M; i++) {
    int u, v, w;
    in >> u >> v >> w;

    assert (u >= 1 && u <= N);
    assert (v >= 1 && v <= N);
    assert (w >= 1 && w <= W_MAX);

    /*
    {
      arco a = { v - 1, w, 0 };
      vicini_t::iterator ai(lower_bound(grafo[u-1].begin(), grafo[u-1].end(), a));
      if (ai == grafo[u-1].end())
	grafo[u-1].push_back(a);
      else
	ai->peso += a.peso;
    }

    {
      arco b = { u - 1, 0, 0 };
      vicini_t::iterator bi(lower_bound(grafo[v-1].begin(), grafo[v-1].end(), b));
      if (bi == grafo[v-1].end())
	grafo[v-1].push_back(b);
      else
	bi->peso += b.peso;
    }
    */
    grafo[u-1][v-1].first += w;
    grafo[v-1][u-1].first += 0;
  }

  /*
  for (int i(0); i < N; i++) {
    vicini_t& vicini(grafo[i]);
    sort(vicini.begin(), vicini.end());
  }
  */

  int sol = flusso(S-1, T-1);

  assert (sol <= W_MAX);

  out << sol << '\n';

  return 0;
}

