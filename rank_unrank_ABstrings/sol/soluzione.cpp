/**
 *  Soluzione di perm_recognition, scritta da Romeo Rizzi 2018.11.28
 */
#include <iostream>
#include <string>
using namespace std;

const int MAXL = 60;
typedef unsigned long long ll;


ll ABstring2rank(string s) {
  ll sol = 0;
  ll val = 1;
  for (int i = s.size()-1; i >= 0; i--) {
    if (s[i] == 'B')
      sol += val;
    val *= 2;
  }
  return sol;
}

char buf[512];

string ABstring_of_len_and_rank(ll length, ll r) {
  for (int i = 0; i < length; i++) buf[i] = 'A';
  int i = 0;
  while (r) {
    if (r & 0x1) buf[i] = 'B';
    i++;
    r /= 2;
  }
  for (int i = 0; i < length/2; i++) swap(buf[i], buf[length-i-1]);
  return string(buf);
}

int main() {
  string s;
  getline (cin,s);
  ll a, b;
  bool unrank = sscanf(s.c_str(), "%llu%llu", &a, &b) == 2;
  if (unrank) {
    cout << ABstring_of_len_and_rank(a, b) << endl;
  }
  else {
    cout << ABstring2rank(s) << endl;
  }
  return 0;
}
