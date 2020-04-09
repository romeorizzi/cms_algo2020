/*
  Cracco e Rizzi 2016   (adattato da Autore Alessio Guerrieri)
 */

// Assume file di input e file di output non malformati.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;

#define NONE -1

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
  if (fout->fail() || fout->eof())
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
    ex("Percorso troppo lungo", 0.0f);
}

int N,M;

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
  map<pair<int,int>,int> graph;
  for(int i=0; i<M; i++){
    int a,b;
    *fin >> a >> b;
    graph[make_pair(a,b)] = 1;
  }

  
  /* Da controllare:
     Il percorso é lungo M
     Vengono usati solo archi esistenti
     Ogni arco viene usato al massimo una volta     
   */
  int cur=NONE;  
  for(int i=0;i<M;i++){
    int a=safe_read(0,N-1);
    int b=safe_read(0,N-1);
    if( ( a!=cur ) && ( cur != NONE ) )
      ex("Il percorso non corretto",0.0f);      
    pair<int,int> edge=make_pair(a,b);
    if(graph[edge]==0)
      ex("Arco inesistente",0.0f);
    else if(graph[edge]==1)
      graph[edge]=-1;
    cur=b;
  }
  check_fine_file();
  ex("Soluzione corretta",1.0f);
  return 0;
}
