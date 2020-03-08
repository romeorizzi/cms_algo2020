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

long long int risposta, upper_bound;
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

  *fin >> risposta >> upper_bound >> subtask;

  long long int max_chiamate;
  /* In base al subtask, decido il max numero di chiamate */
  if (subtask == 2) {
    max_chiamate = upper_bound / 2;
  } else if (subtask > 2) {
    // max_chiamate = ceil(log_2(upper_bound))
    max_chiamate = 0;
    while ((1LL << max_chiamate) < upper_bound) {
      max_chiamate++;
    }
  } else {
    max_chiamate = -1; // infinito
  }

  /* Qui devo leggere il "log" presente nel file output.txt dell'utente
     e decidere se l'output e' valido */
  long long int conta_chiamate = 0;
  while (1) {
    int tipo = safe_read(0, 2);
    long long int confronto_con = safe_read(1LL, upper_bound);
    if (tipo == 0) {  // evento "l'utente prova a indovinare"
      conta_chiamate++;
    } else if (tipo == 1) {  // evento "l'utente da' la risposta"
      if (confronto_con == risposta) {
        check_fine_file();
        ex("Output corretto.", 1.0);
      }
      else ex("Risposta non corretta.", 0.0);
    } else {  // evento "l'avversario cambia la risposta"
      risposta = confronto_con;
    }
    if (max_chiamate != -1 && conta_chiamate > max_chiamate) {
      ex("Troppe chiamate alla funzione confronto_con.", 0.0);
    }
  }

  ex("Panic.", 0.0);
  return 0;
}
