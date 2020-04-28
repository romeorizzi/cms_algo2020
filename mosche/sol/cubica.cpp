/* soluzione cubica O(RSK) al problema:
    mosche (rielaborazione di PROZOR, da COCI 2015-16, round 6, task 2) 
   Romeo Rizzi, 9 marzo 2016
*/
#include<cassert>
#include<iostream>
#include<cstring>

using namespace std;

const int MAX_R = 2000; int r;
const int MAX_S = 2000; int s;
const int MAX_K = 2000; int k;
int fly[MAX_R][MAX_S];      // 1 se c'e' la mosca, 0 se non c'e'
char c_fly[MAX_R][MAX_S];   // comes in handy for the printing of the solution in output
int prefix_sum_on_row[MAX_R][MAX_S]; // somme prefisse per ciascuna riga della matrice fly

int eval(int x, int y) {
// ritorna il numero di mosche interne a quadrato kxk
// con angolo sinistro-alto in (x,y) e destro-basso in (x+k-1,y+k-1)
// zona attiva: x+1<=i<=x+k-2, y+1<=j<=y+k-2
   int risp = 0;
   for(int i = x+1; i < x+k-1; i++)
      risp += prefix_sum_on_row[i][y+k-2]-prefix_sum_on_row[i][y];
   return risp;
}

int main() {
   cin >> r >> s >> k;
   for(int i = 0; i < r; i++) {
      string spoon;
      cin >> spoon;
      for(int j = 0; j < s; j++) {
         c_fly[i][j] = spoon[j];
         fly[i][j] = (spoon[j] == '*') ? 1 : 0 ;
         prefix_sum_on_row[i][j] = fly[i][j] + ( (j>0) ? prefix_sum_on_row[i][j-1] : 0 );
      }
   }

   int max_so_far = -1;
   int best_x;
   int best_y;
   for(int i = 0; i+k-1 < r; i++)
      for(int j = 0; j+k-1 < s; j++)
        if(eval(i,j) > max_so_far) {
            max_so_far = eval(i,j);
            best_x = i; best_y = j;
        }

   c_fly[best_x][best_y] = c_fly[best_x + k-1][best_y + k-1] = '+';
   c_fly[best_x + k-1][best_y] = c_fly[best_x][best_y + k-1] = '+';
   for(int i = 1; i < k-1; i++) {
      c_fly[best_x][best_y +i] = c_fly[best_x +k-1][best_y +i] = '-';
      c_fly[best_x +i][best_y] = c_fly[best_x +i][best_y +k-1] = '|';
   }

   cout << eval(best_x, best_y) << endl;
   for(int i = 0; i < r; i++) {
      for(int j = 0; j < s; j++)
         cout << c_fly[i][j];
      cout << endl;
   }

   return 0;
}

