/*
Soluzione al problema Poldo con l'algoritmo visto a lezione.

La soluzione dovrebbe avere complessita' O(nlog(k)), dove n e' la lunghezza del menu e k il risultato.
Se il menu e' generato casualmente ci dovremmo aspettare un k pari a circa sqrt(2n).
Nel caso peggiore (un menu gia' ordinato) k sarà ovviamente pari a n.
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

/*
Ricerca binaria (anche se un po' bruttina) nel vettore contenente le pile (o meglio solo le loro teste per risparmiare memoria).
E' possibile farla perche' per costruzione e' garantito che il vettore sia ordinato.
*/
uint32_t findPos(uint32_t start, uint32_t end, uint32_t& newNumber, vector<uint32_t>& vec) {
  if(start == end) return start;
  if(vec[end - 1] > newNumber) return end;
  if(end - start == 1) return start;

  uint32_t mid = (start + end) / 2;
  if(vec[mid] > newNumber) {
    return findPos(mid + 1, end, newNumber, vec);
  } else if (vec[mid] < newNumber) {
    return findPos(start, mid, newNumber, vec);
  } else {
    return mid;
  }
}

/*
Viene chiamata per ogni panino nel menu.
Piazza il nuovo panino sopra la pila piu' adatta.
La scelta avviene cosi': si cerca la pila piu' "a sinistra" possibile contenente un panino di peso minore.
Se serve si crea una nuova pila.
*/
void solve(uint32_t& newNumber, vector<uint32_t>& vec) {
  uint32_t pos = findPos(0,vec.size(),newNumber, vec);
  if(pos == vec.size())
    vec.push_back(newNumber);
  else
    vec[pos] = newNumber;
}

int main(int argc, char** argv)
{
  #ifdef EVAL
  //====================================================
  //PARTE OBBLIGATORIA REINDIRIZZAMENTO STDIN/OUT
  //====================================================
  ifstream fileIn;
  fileIn.open("input.txt");
  ofstream fileOut;
  fileOut.open("output.txt");

  if(!fileIn.is_open() || !fileOut.is_open()) return -1;

  cin.rdbuf(fileIn.rdbuf());
  cout.rdbuf(fileOut.rdbuf());
  #endif

  uint32_t n;
  cin >> n;

  //La lunghezza di questo vettore sara' la soluzione.
  auto sVect = vector<uint32_t>();

  uint32_t temp;
  for(uint32_t i = 0; i < n; i++) {
    cin >> temp;
    solve(temp,sVect);
  }
  cout << sVect.size();
  /*
    Se oltre alla lunghezza fosse stata richiesta anche la sequenza stessa,
    avremmo dovuto cambiare la struttura del vettore perche' non ci sarebbe piu' bastata la testa di ogni pila per ricostruire la sequenza.
  */
  return 0;
}
