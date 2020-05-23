/*
  Luca Wehrstedt

  Calcola il numero di componenti connesse e le stampa tutte.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>
#include <cassert>

using namespace std;

#ifdef EVAL
ifstream lettura("input.txt");
ofstream scrittura("output.txt");
#else
istream &lettura(cin);
ostream &scrittura(cout);
#endif

int n, m;

vector< vector<int> > archi;

void leggi ()
{
	lettura >> n >> m;

	assert (1 <= n && n <= 10000);
	assert (1 <= m && m <= 1000000);

	archi.assign (n, vector<int> ());

	int u, v;
	for (int i = 0; i < m; i += 1)
	{
		lettura >> u >> v;

		assert (1 <= u && u <= n);
		assert (1 <= v && v <= n);

		archi[u-1].push_back (v-1);
	}
}

vector< vector<int> > componenti;

vector<int> stack;

vector<int> frontindex;
vector<int> backindex;

vector<bool> ancestor;

int nextindex = 0;

void tarjan (int node)
{
	frontindex[node] = nextindex;
	backindex[node] = nextindex;
	nextindex += 1;
	stack.push_back (node);
	ancestor[node] = true;

	for (int i = 0; i < archi[node].size(); i += 1)
	{
		if (frontindex[archi[node][i]] == -1) // Il nodo e' nuovo
		{
			tarjan (archi[node][i]);
			backindex[node] = min (backindex[node], backindex[archi[node][i]]);
		}
		else if (ancestor[archi[node][i]]) // Il nodo e' un mio antenato
		{
			backindex[node] = min (backindex[node], frontindex[archi[node][i]]);
		}
	}

	if (frontindex[node] == backindex[node])
	{
		componenti.push_back (vector<int> ());
		while (stack.back() != node)
		{
			componenti.back().push_back (stack.back ());
			ancestor[stack.back ()] = false;
			stack.pop_back ();
		}
		componenti.back().push_back (stack.back ());
		ancestor[stack.back ()] = false;
		stack.pop_back ();
	}
}

void elabora ()
{
	frontindex.assign (n, -1);
	backindex.assign (n, -1);

	ancestor.assign (n, false);

	for (int i = 0; i <= n; i += 1)
	{
		if (frontindex[i] == -1)
		{
			tarjan (i);
		}
	}
}

void scrivi ()
{
	scrittura << componenti.size () << endl;

	for (int i = 0; i < componenti.size (); i += 1)
	{
		scrittura << componenti[i].size () << endl;

		for (int j = 0; j < componenti[i].size (); j += 1)
		{
			scrittura << componenti[i][j] + 1 << " ";
		}
		scrittura << endl;
	}
}

int main ()
{
	leggi ();
	elabora ();
	scrivi ();
}

