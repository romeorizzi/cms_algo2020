/*
  Matteo Boscariol
 */

// Assume file di input e file di output non malformati.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>

using namespace std;

ifstream *fin;
ifstream *fcor;
ifstream *fout;

void ex(const char *msg, float res)
{
  if(msg) {
    fprintf(stderr, "%s ", msg);
  }
  printf("%f\n", res);
  exit(0);
}

template <class T>
T safe_read(const T &lowerBound, const T &upperBound)
{
  // Legge in maniera sicura un tipo ordinato e controlla che stia in
  // [lowerBound, upperBound]
  T x;
  if (lowerBound > upperBound)
    {
      cerr << "safe_read chiamato con parametri errati: " << lowerBound << " " << upperBound << "\n";
      return 1;
    }
  *fout >> x;

  if (fout->fail())
    ex("Output malformato", 0.0f);
  if (x < lowerBound || x > upperBound)
    ex("Output invalido", 0.0f);
  return x;
}

void
check_fine_file()
{
  string x;

  if (fout->eof())
    return;

  *fout >> x;
  if (x != "" || !fout->eof())
    ex("Output malformato", 0.0f);
}

int N,M, sol_len;
bool is_cycle;


vector< set<int> > adjlist;

int user_len;
bool user_cycle;
vector<int> user_sequence;
vector<bool> used_node;

int main(int argc, char *argv[])
{
  if(argc < 4)
    {
      cerr << "Usage: " << argv[0] << " <input> <correct output> <test output>" << endl;
      return 1;
    }

  fin = new ifstream(argv[1]);
  fcor = new ifstream(argv[2]);
  fout = new ifstream(argv[3]);

  if(fin->fail())
    {
      cerr << "Impossibile aprire il file di input " << argv[1] << "." << endl;
      return 1;
    }
  if(fcor->fail())
    {
      cerr << "Impossibile aprire il file di output corretto " << argv[2] << "." << endl;
      return 1;
    }
  if(fout->fail())
    ex("Impossibile aprire il file di output generato dal codice sottoposto al problema.", 0.0);

  *fin >> N >> M;
  adjlist.resize(N+1);
  used_node.resize(N+1, false);
  for(int i=0;i<M;i++) {
    int u,v;
    *fin >> u >> v;
    adjlist[u].insert(v);
  }

  *fcor >> sol_len;
  if(sol_len == -1) {
    is_cycle = true;
  }

  user_len = safe_read(-1, N);
  if(user_len == 0) {
    ex("Errato", 0.0f);
    return 0;
  }

  if(user_len == -1) {
    user_cycle = true;
    user_len = safe_read(2, N);
  }

  for(int i=0;i<user_len;i++) {
    int u = safe_read(1, N);
    if(used_node[u]) {
      ex("Errato", 0.0f);
      return 0;
    }
    user_sequence.push_back(u);
  }
  
  check_fine_file();
  
  for(int i=1;i<user_sequence.size(); i++) {
    int u = user_sequence[i-1], v = user_sequence[i];
    if(adjlist[u].find(v) == adjlist[u].end()) {
      ex("Errato", 0.0f);
      return 0;
    }
  }
  
  if(user_cycle) {
    int u = user_sequence.back(), v = user_sequence.front();
    if(adjlist[u].find(v) == adjlist[u].end()) {
      ex("Errato", 0.0f);
      return 0;
    }
  }
  
  // Se arriva qui, la sequenza è corretta, che sia un ciclo o un path.
  // Verifico se è ottima.
  
  if(user_cycle) {
    if(is_cycle) {
      ex("Corretto", 1.0f);
    }
    else {
      ex("It burns", 1.0f);
    }
  }
  else {
    if(is_cycle) {
      ex("Errato", 0.0f);
    }
    else if(user_len < sol_len){
      ex("Errato", 0.0f);
    }
    else if(user_len == sol_len) {
      ex("Corretto", 1.0f);
    }
    else {
      ex("It burns", 1.0f);
    }
  }

  return 0;
}
