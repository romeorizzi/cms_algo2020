#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

ifstream fin;  // input
ifstream fcor; // output corretto
ifstream fout; // da controllare


void ex(const char *msg, float res) {
  cerr << msg << endl;
  cout << res << endl;
  
  exit(0);
}

void check_fine_file(float res) {
  if (fout.eof())
    return;

  string x; fout >> x;
  if (x != "" || !fout.eof())
    ex("Output malformato (check fine file)", res);
}


int main(int argc, char *argv[]) {
  if(argc < 4) {
      cerr << "Usage: " << argv[0] << " <input> <correct output> <test output>" << endl;
      return 1;
  }
		
  fin.open(argv[1]);  // file input
  fcor.open(argv[2]); // file output corretto
  fout.open(argv[3]); // file output da controllare

  int r, s, k; fin >> r >> s >> k;
  int risp_cor; fcor >> risp_cor; 
  int risp_out; fout >> risp_out;
  if( risp_out > risp_cor )  ex("Soluzione superottima: dichiari un numero di mosche eccessivo", 0.0);
  if( risp_out < risp_cor )  ex("Soluzione subottima: catturi poche mosche", 0.0);

  int first_row = -654321; // quando positiva: riga inizio racchetta 
  int first_col = -1; // colonna inizio racchetta
  int risp = 0; 
  for(int i = 0; i < r; i++) {
      string spoon_in; fin >> spoon_in;
      string spoon_out; fout >> spoon_out;
      // cout << spoon_in << endl;
      // cout << spoon_out << endl;
      if(first_row < 0) {
         for(int j = 0; j < s; j++)
	   if(spoon_in[j] != spoon_out[j]) {
	       first_row = i; first_col = j;
               if(spoon_out[first_col] != '+') ex("Numero giusto ma output malformato", 0.5);
               if(first_col+k-1 >= s) ex("Numero giusto ma output malformato", 0.5);
               if(spoon_out[first_col+k-1] != '+') ex("Numero giusto ma output malformato", 0.5);
               for(j = first_col+1; j < first_col+k-1; j++)
		 if(spoon_out[j] != '-') ex("Numero giusto ma output malformato", 0.5);
               j = first_col+k;
	   }
      }
      else {
	for(int j = 0; j < s; j++) {
	   char tmp = spoon_in[j];
           if(i < first_row + k-1) {
	     if( (j == first_col) || (j == first_col + k-1) ) tmp = '|';
	     if( (j > first_col) && (j < first_col + k-1) )
               if( tmp == '*' )  risp++;
           }
           if(i == first_row + k-1) {
	     if( (j == first_col) || (j == first_col + k-1) ) tmp = '+';
	     if( (j > first_col) && (j < first_col + k-1) ) tmp = '-';
           }
	   if(spoon_out[j] != tmp) {
	     // cout << "i = " << i << ", j = " << j << ", tmp = " << tmp << endl;  
              ex("Numero giusto ma output malformato", 0.5);
           }
        }
      }
  }

  if( risp != risp_out )
     ex("Non catturi il numero di mosche dichiarato", 1.0);

  check_fine_file( 0.8 );	
  ex("Soluzione corretta", 1.0);
	
  return 0;
}
