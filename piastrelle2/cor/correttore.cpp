/*
  Romeo Rizzi
 */

// Assume file di input e file di output non malformati.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

const int MAXN = 20;

ifstream *fin;
ifstream *fcor;
ifstream *fout;

int p[2][MAXN];

string encoding(int n) {
  string risp = "";
  for(int i = 1; i<n; i++)
     risp += (p[0][i] == p[0][i-1])? "x" : "y";
  for(int i = 1; i<n; i++)
     risp += (p[1][i] == p[1][i-1])? "x" : "y";
  for(int i = 0; i<n; i++)
     risp += (p[0][i] == p[1][i])? "x" : "y";

  return risp;
}

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
    ex("Output malformato (safe_read)", 0.0f);
  if (x < lowerBound || x > upperBound)
    ex("Output invalido (safe_read)", 0.0f);
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
    ex("Output malformato (check fine file)", 0.0f);
}


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

  int N, Kcor, Kout;
  *fin >> N;
  *fcor >> Kcor;
  Kout = safe_read( (long long int) 0, std::numeric_limits<long long int>::max());

  if(Kout != Kcor) {
    ex("Errato, dichiarato un diverso numero di soluzioni in prima riga.", 0.0f);
    return 0;
  }

  unordered_map<string, int> mapOut;
  for(int k = 0; k < Kout; k++) {
    //cout << "k = " << k << endl;

    for(int j = 0; j < 2; j++) {
      for(int i = 0; i < N; i++) {
           p[j][i] = safe_read(1, 5);
           //cout << p[j][i] << " ";
        }
      //cout << endl;
    }
     string key = encoding(N);
     if( mapOut[key] != 0 ) {
         for(int j = 0; j < 2; j++) {
            for(int i = 0; i < N; i++)
	       cerr << p[j][i] << " ";
            cerr << endl;
         }
         ex("Errato: piastrellatura ripetuta nel file di output da valutare.", 0.0f);
         return 0;
     }
     mapOut[key] = 1;
  }

  for(int k = 0; k < Kout; k++) {
     for(int j = 0; j < 2; j++)
        for(int i = 0; i < N; i++)
	   *fcor >> p[j][i];
     string key = encoding(N);
     if( mapOut[key] == 0 ) {
         for(int j = 0; j < 2; j++) {
            for(int i = 0; i < N; i++)
	       cerr << p[j][i] << " ";
            cerr << endl;
         }
         ex("Errato: piastrellatura mancante nel file di output da valutare.", 0.0f);
         return 0;
     }
  }

  // Se arriva qui, e le nostre piastrellature sono tutte diverse,
  // la soluzione del ragazzo e' equivalente alla nostra..
  
  ex("Corretto", 1.0f);

  return 0;
}
