/* FILE: long_walk_with_STL.cpp   last change: 24-Oct-2012   Romeo Rizzi
 * a solver for problem long_walk in 28-09-2012 exam in Algorithms
 */
/* BASIC FACTS: a digraph is a directed graph. A node with no exiting arcs is called a sink. In a digraph, no directed circuit can pass through a sink. Conversely, if a directed graph has no sink then it must necessarily contain a directed circuit since once can be found as follows: place a pebble into a node and then move it from nodo to node following the arcs (from the tail node to the head node) until it gets back to an already visited node.
 ALGORITHM: until the digraph has some sinks, we keep removing them (no directed circuit can pass through a sink) meanwhile labelling each of them with the length of a longest walk starting from it (whence entirely made of removed nodes). Indeed, the subdigraph induced by the removed nodes is a DAG (=directed acyclic graph), whence these longest paths can be computed by dynamic programming.
 IMPLEMENTATION: to get a linear time algorithm, when a node becomes a sink it is put in the stack "LIFOsink" where it stays until it gets removed from the digraph. (A node becomes a sink when its out_degree drops to 0). 
The original digraph is stored in star representation implemented by means of 2 arrays of vectors, where each vector contains a star of a node. The boolean array "removed" is used to spot out removed nodes                                                                   .
*/


#include <cassert>
#include <iostream>  // uso di cin e cout non consentito in versione finale
#include <fstream>
#include <vector>


using namespace std;

const int MAX_N =  100000; int n; // numero nodi.
const int MAX_M = 1000000; int m; // numero archi.

int out_deg[MAX_N +1]; // i nodi (e gli archi) sono numerati da 1 ad n
// di ogni nodo voglio conoscere il grado uscente nel grafo residuo, per realizzare efficacemente quando esso diviene un pozzo
vector<int> out_nei[MAX_N +1], in_nei[MAX_N +1]; // per ogni nodo ho il vector con la stella uscente (out_nei) e quello con la stella entrante (in_nei)  
int LIFOsink[MAX_N], LIFOpos = 0; // just an handy bag where to store nodes which have become sinks
bool removed[MAX_N +1];
int max_from[MAX_N +1], nxt[MAX_N +1], max_so_far, max_start; // implement the dynamic programming to find the max lenght path; their value is defined on top of the already removed nodes. When v is a removed node then:
// max_from[v] is the maximum length of a path starting at v;
// nxt[v] stores the second node of a maximum length path starting at v.
// Meanwhile, max_so_far is the running maximum of the max_from[v] values over the nodes v removed so far and max_start stores the removed node achieving this maximum.  

int main() {
  #ifdef EVAL
  ifstream fin("input.txt");  assert( fin );
  ofstream fout("output.txt");  assert( fout );
  #else
  istream &fin = cin;
  ostream &fout = cout;
  #endif
  fin >> n >> m;
  for(int i=0; i<=n; i++)
     nxt[i] = max_from[i] = out_deg[i] = 0;	
  for(int tail, head, j = 1; j <= m; j++) {
    fin >> tail >> head;
    out_nei[tail].push_back(head); in_nei[head].push_back(tail);
    out_deg[tail]++;
  }

  for(int i=1; i<=n; i++) {
    removed[i] = false; assert( out_deg[i] == out_nei[i].size() );
    if( out_deg[i] == 0 )  LIFOsink[ LIFOpos++ ] = i;	
  }
  int n_removed = 0;

  while( LIFOpos ) {  // hearth of the algorithm
    int v = LIFOsink[ --LIFOpos ];
    removed[v] = true; n_removed++;
    
    for(vector<int>::iterator it = out_nei[v].begin(); it < out_nei[v].end(); it++) // begin: dyn prog
      if( max_from[ *it ] >= max_from[v] ) {
	max_from[v] = max_from[ *it ] +1;
        nxt[v] = *it;
        if( max_from[v] > max_so_far )  {
          max_so_far = max_from[v]; max_start = v;
        }
      } // end: dynamic programming

    for(vector<int>::iterator it = in_nei[v].begin(); it < in_nei[v].end(); it++) {// begin: update graph
      out_deg[ *it ] --;
      if( out_deg[ *it ] == 0 )
      LIFOsink[ LIFOpos++ ] = *it;  
    } // end: updating the graph (node v has been removed)
  }

  if( n_removed == n ) { // it was a DAG: we are ready to output a longest path
    fout << max_so_far+1 << endl;  // max length of a path in the removed nodes
    int v = max_start;  // max_start = the first node of a maximum length path
    while( v ) {  // we print the nodes one by one
      fout << v << " ";
      v = nxt[v];   // nxt[] was properly set up during the dyn programming 
    }
    fout << endl;
  }
  else {  // we are left with some nodes but no sink -> there must be a cycle
    fout << -1 << " "; // there must be a cycle, we now search for it ...
    bool visited[MAX_N +1]; // with the algo described in "BASIC FACTS"
    for(int i = 1; i <= n; i++)  visited[i] = false; // no node visited yet
    int v = 1; while( removed[v] )  v++;  // place the pebble in any unremoved v
    while( !visited[v]) {
      visited[v] = true;  // cout << endl << endl << v << " ";
      for(vector<int>::iterator it = out_nei[v].begin(); it < out_nei[v].end(); it++)
        if( !removed[ *it ] )  nxt[v] = *it;
      v = nxt[v];
    }
    int u = v; //we got back to an already visited node v, now go round again... 
    int len=0;
    do { 
      len++;
      u = nxt[u];
    } while( u != v );
    fout << len << endl;
    // and again...
    do { // and print the nodes one by one
      fout << u << " "; // cout << u << " ";
      u = nxt[u];
    } while( u != v );
    fout << endl;
  } 
  return 0;
}
