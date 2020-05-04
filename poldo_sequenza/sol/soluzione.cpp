/*
Soluzione al problema Poldo con l'algoritmo visto a lezione.
Versione che stampa anche la sequenza.
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>

using namespace std;

class ElementoPila {
  public:
    ElementoPila(uint32_t _valore, ElementoPila* _predecessore): valore(_valore), predecessore(_predecessore) {}
    uint32_t valore;
    ElementoPila* predecessore;
};
typedef deque<ElementoPila> pila;

/*
Ricerca binaria (anche se un po' bruttina) nel vettore contenente le pile.
E' possibile farla perche' per costruzione e' garantito che il vettore sia ordinato.
*/
uint32_t findPos(uint32_t start, uint32_t end, uint32_t& newNumber, vector<pila>& vec) {
  if(start == end) return start;
  if(vec[end - 1].front().valore > newNumber) return end;
  if(end - start == 1) return start;

  uint32_t mid = (start + end) / 2;
  if(vec[mid].front().valore > newNumber) {
    return findPos(mid + 1, end, newNumber, vec);
  } else if (vec[mid].front().valore < newNumber) {
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
void solve(uint32_t& newNumber, vector<pila>& vec) {
  uint32_t pos = findPos(0,vec.size(),newNumber, vec);
  ElementoPila* predPTR = NULL;
  if(pos != 0) {
    predPTR = &(vec[pos - 1].front());
  }
  if(pos == vec.size()) {
    vec.push_back(deque<ElementoPila>(1,ElementoPila(newNumber,predPTR)));
  } else {
    vec[pos].push_front(ElementoPila(newNumber,predPTR));
  }
}

int main(int argc, char** argv)
{
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

  uint32_t n;
  cin >> n;

  //La lunghezza di questo vettore sara' il numero massimo di panini che Poldo potra' mangiare.
  auto sVect = vector<pila>();
  sVect.reserve(n); //NECESSARIO PERCHE' HO AVUTO LA MALSANA IDEA DI SALVARE GLI INDIRIZZI, E QUINDI NON POSSO PERMETTERMI UN REALLOC DINAMICO.

  uint32_t temp;
  for(uint32_t i = 0; i < n; i++) {
    cin >> temp;
    solve(temp,sVect);
  }
  cout << sVect.size() << endl;

  /*
  Ricostruiamo la sequenza partendo dall'ultima pila.
  */
  auto elem = sVect[sVect.size() - 1].front();
  vector<uint32_t> solution;
  solution.reserve(sVect.size());
  uint32_t count = 0;
  while(true) {
    solution[count] = elem.valore;
    count ++;
    if(elem.predecessore != NULL) {
      elem = *(elem.predecessore);
    } else {
      break;
    }
  }

  for(uint32_t i = sVect.size() - 1; i != ~0u; --i) {
    cout << solution[i] << " ";
  }
  return 0;
}
