/**
 *  Soluzione di for2_std
 *  Romeo Rizzi, last: 2020-03-24
 */
#include <iostream>
using namespace std;
int main() {
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
       for(int j = 1; j <= N; j++)
	 cout << i*j << " ";
       cout << std::endl; // cout << "\n";
    }
    return 0;
}

