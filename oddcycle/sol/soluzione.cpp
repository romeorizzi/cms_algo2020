/* solutore oddcycle
   Romeo 2017-03-15
*/

#define DEBUG 0

const unsigned MAXN = 30;
int seen[MAXN];
int sex[MAXN];
int cycle[MAXN], posW = 0;

int N, M, L;
std::vector<int> adj[MAXN];

bool odd_cycle(int node, int mysex) {
  if( seen[node] ) {
    if( sex[node] != mysex ) {
      cycle[posW++] = node;
      L = posW;
      return true;
    }
    else
      return false;
  }
  seen[node] = 1; sex[node] = mysex;
  cycle[posW++] = node;
  for (int next: adj[node])
    if( odd_cycle(next, 1-mysex) )
      return true;
  posW--;
  return false;
}

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::cin >> N >> M;

    for (int i=0; i<M; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        adj[a].push_back( b );
        adj[b].push_back( a );
    }

    assert( odd_cycle(0, 0) );

    std::cout << L << std::endl;
    for (int i=0; i<L; i++) {
      std::cout << cycle[i]+1 << " ";
    }
    bool print = false;
    for (int i=L-2; i >= 0; i--) {
      if( print )
         std::cout << cycle[i]+1 << " ";
      if( cycle[i] == cycle[L-1] )
	print = true;
    }
    std::cout << std::endl;

    return 0;
}
