/* correttore per slalom
   Luca Barbieri
   9-3-2006
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <vector>
#include <algorithm>
using namespace std;

#define IN -1
#define REF 0
#define OUT 1

bool pedantic = true;
FILE* in;

struct sol
{
	FILE* f;
	int n;
	vector<int> nodes;
	int cost;
};

sol sols[2];

void ex_(char *msg, float res) {
   if ( msg )
     fprintf(stderr, "[\x1b[1m\x1b[31m%s\x1b[m] ", msg);

   printf("%f\n", res);
   exit(0);
}

void exf(int sol, float res, char *msg, ...)
{
	if(sol != OUT && res != 0.0f)
		return;

	char* str = 0;
	va_list ap;
	va_start(ap, msg);
	vasprintf(&str, msg, ap);
	
	if(sol == OUT)
		ex_(str, res);
	else if(sol == IN)
	{
		printf("ERRORE CATASTROFICO NELL'INPUT!!!\n%s\n", str);
		exit(1);
	}
	else
	{
		printf("ERRORE CATASTROFICO NELLA SOLUZIONE DI RIFERIMENTO!!!\n%s\n", str);
		exit(1);
	}
		
	free(str);
}

int readInt(int sol)
{
  FILE* fp;
  
  if(sol == IN)
  	fp = in;
  else
  	fp = sols[sol].f;

  char buf[64];
  int bufi = 0;
  
  bool minus = false;
  bool seensign = false;
  bool seendigits = false;
  
  for(;;)
  {
  	char c = fgetc(fp);
  	if(c == EOF || isspace(c))
  	{
  		if(seensign && !seendigits)
  		{
  			if(pedantic)
	  			exf(sol, 0.0, "La soluzione contiene un carattere + o - isolato");
  		}
  		  			
  		if(seendigits)
  		{
  			if(bufi == 0)
  				return 0;
  				
  			buf[bufi] = 0;
  			long long tmp;
  			sscanf(buf, "%Ld", &tmp);
  			
  			if(tmp > (long long)(int)0x7fffffff || tmp < (long long)(int)0x80000000)
  				exf(sol, 0.0, "La soluzione contiene un numero piu' grande di un intero a 32 bit");
  			
  			return tmp;  			
  		}
  		
		bufi = 0;
  		minus = false;
  		seensign = false;
  		seendigits = false;
  		
  		if(c == EOF)
  			break;
  		continue;
  	}
  	
  	if(c == '+' || c == '-')
  	{
  	 	if(seensign || seendigits)
  	 	{
  	 		if(pedantic)
	  			exf(sol, 0.0, "La soluzione contiene un carattere + o - non all'inizio del numero");
	  		continue;
  	 	}

  		seensign = true;
  		if(c == '-')
	  		minus = true;
	  		
	  	continue;
  	}
  	
  	seendigits = true;
  	
  	if(c == '0' && !bufi)
  		continue;
  		
  	if(!isdigit(c))
  	{
  		if(pedantic)
			exf(sol, 0.0, "La soluzione contiene caratteri non numerici e diversi da + o -");
		continue;
  	}
	
	if(bufi >= 10)
		exf(sol, 0.0, "La soluzione contiene un numero piu' grande di un intero a 32 bit");
	
  	buf[bufi++] = c;
  }

  exf(sol, 0.0, "Il file prodotto dalla soluzione e' incompleto");
  return 0;
}

struct node
{
	int weight;
	bool marked[2];
	bool check;
	
	node()
	: weight(-1), check(false)
	{
		marked[0] = marked[1] = false;
	}
};

int n;
vector<node> nodes;
vector<vector<int> > adj;

vector<pair<int, int> > edges;

void read_sol(int soli)
{
	sol& sol = sols[soli];
		
	sol.n = readInt(soli);
	
	if(sol.n > n)
		exf(soli, 0.0f, "La soluzione ha un numero di snodi maggiore di quelli nella pista");

	if(sol.n < 0)
		exf(soli, 0.0f, "La soluzione ha un numero di snodi negativo");
	
	sol.cost = 0;
	
	for(int i = 0; i < sol.n; ++i)
	{
		int v = readInt(soli);
		//printf("from %d: %d\n", soli,v);
		if(v < 1 || v > n)
			exf(soli, 0.0f, "La soluzione si riferisce al nodo numero %d, che non è tra %d e %d", v, 1, n);

		--v;
			
		sol.nodes.push_back(v);
		
		if(nodes[v].marked[soli])
			exf(soli, 0.0f, "La soluzione include almeno due volte il nodo %d", v + 1);
		
		nodes[v].marked[soli] = true;
		
		sol.cost += nodes[v].weight;
	}
	
	for(int i = 0; i < (n - 1); ++i)
	{
		if(!nodes[edges[i].first].marked[soli] && !nodes[edges[i].second].marked[soli])
			exf(soli, 0.0, "La soluzione non copre la pista %d %d", edges[i].first, edges[i].second);
	}
}

int main(int argc, char** argv)
{
	in = fopen(argv[1], "r");
	sols[OUT].f = fopen(argv[2], "r");
	sols[REF].f = fopen(argv[3], "r");
		
	n = readInt(IN);
	nodes.resize(n);
	
	for(int i = 0; i < n; ++i)
	{
		nodes[i].weight = readInt(IN);
	}
	
	adj.resize(n);
	
	if(n < 1)
		exf(IN, 0.0, "L'input dichiara un numero di nodi nonpositivo");
		
	if(n > (1024 * 1024 * 16))
		exf(IN, 0.0, "L'input dichiara un numero di nodi > 16M");
	
	vector<pair<int, int> > check_edges;
	
	for(int i = 0; i < (n - 1); ++i)
	{
		int a, b;
		a = readInt(IN);
		b = readInt(IN);
		--a;
		--b;
		
		if((a < 0) || (b < 0) || (a >= n) || (b >= n))
			exf(IN, 0.0, "L'input contiene numeri di nodi assurdi");
		
		adj[a].push_back(b);
		adj[b].push_back(a);
		
		if(a == b)
			exf(IN, 0.0, "L'input contiene un cappio");
			
		edges.push_back(make_pair(a, b));
		check_edges.push_back(make_pair(min(a, b), max(a, b)));
	}
	
	sort(check_edges.begin(), check_edges.end());
	
	if(unique(check_edges.begin(), check_edges.end()) != check_edges.end())
		exf(IN, 0.0, "L'input contiene piste duplicate");
	
	/*
#ifdef CHECK_INPUT
	stack<pair<int, int> > dfs_stack;
	
	dfs_stack.push_back(make_pair(0, 0));
	
	for(;;)
	{
		pair<int, int> dfs_top;
		
		do
		{
			if(dfs_stack.empty())
				return;
			
			dfs_top = dfs_stack.top();
			dfs_stack.pop();
		}
		while(dfs_top.second == adj[dfs_top.first].size());
		
		dfs_stack.push(make_pair(dfs_top.first, dfs_top.second + 1));
		
		dfs_top.first
	}
#endif
*/
	
	read_sol(REF);
	read_sol(OUT);	
		
//	printf("cost is %d %d\n", sols[OUT].cost, sols[REF].cost);
	
	if(sols[OUT].cost < sols[REF].cost)
		exf(REF, 0.0, "La soluzione di riferimento non è ottimale!");
	
	if(sols[OUT].cost > sols[REF].cost)
		exf(OUT, 0.0, "La soluzione ha un costo subottimale");
	
	exf(OUT, 1.0, "La soluzione è corretta");
	
	return 0;
}
