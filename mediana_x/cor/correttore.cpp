// problem: ordina_x, Romeo Rizzi Mar 2015

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <map>
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
    ex("Output malformato", 0.0f);
}

#define MAX_N_BALLS 100000
long int order[MAX_N_BALLS];

long int nBalls;
int subtask;

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


    /* Qui devo leggere il "log" presente nel file output.txt dell'utente
     e decidere se l'output e' valido */

  int wellOrdered = -1;
  long int nPesate = -1, maxPesate = -1;
  *fout >> wellOrdered >> nPesate >> maxPesate;
  if (wellOrdered < 0 || nPesate < 0 || maxPesate < 0)
    ex("Output malformato (hai chiamato consegnaBiglieInOrdine?).", 0.0);  
  else if(nPesate > maxPesate)
    ex("Troppe chiamate alla funzione pesa.", 0.0);
  else
    if ( wellOrdered )
      ex("Output corretto.", 1.0);
    else
      ex("Risposta non corretta.", 0.0);

  ex("Panic.", 0.0);
  return 0;
}
