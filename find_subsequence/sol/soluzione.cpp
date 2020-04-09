/**
 *  Soluzione di find_subsequence
 */
#include <iostream>
#include <string>
using namespace std;

int find_subsequence(string p, string t) {
/* Riceve in input due stringhe p e t e cerca la prima occorrenza di p entro t.
 * Ritorna -1 se non ne trova nessuna.
 * Altrimenti ritorna la prima posizione della prima occorrenza (quella più a sinistra).
 */
  int pos_t = 0;
  for(int pos_p = 0; pos_p < p.size(); pos_p++) {
    char urgent = p[pos_p];
    while(pos_t < t.size() && t[pos_t] != urgent)
      pos_t = pos_t + 1;
    if(pos_t == t.size())  return -1;
  }
  return pos_t + 1;
}

////////////////////////////////////////////////////

int main() {
  string p, t;
  getline(cin,p);
  getline(cin,t);
  cout << find_subsequence(p, t) << endl;
  return 0;
}
