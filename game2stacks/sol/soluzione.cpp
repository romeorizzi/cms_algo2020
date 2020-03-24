/**
 *  Soluzione di game2stacks, written by Romeo Rizzi 2018.11.28
 */
#include <iostream>
using namespace std;


void play(int n1, int n2, int &togli1, int &togli2) {
  togli1 = togli2 = 0;
  if(n1 > n2)
    togli1 = n1-n2;
  else
    togli2 = n2-n1;
}

int main() {
  int n1, n2;
  cin >> n1 >> n2;
  int togli1, togli2;
  play(n1, n2, togli1, togli2);
  cout << togli1 << endl << togli2 << endl;
  return 0;
}

