/*
 * GENERATORE task mappa
 */ 

#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;


int N, M;
char D[105][105];
bool visited[105][105];
bool inside(int x, int y){
    return (x >= 1) && (x <= N) && (y >= 1) && (y <= N);
}
bool dfs(int a, int b){
   // cout << a << " " << b << endl;
    visited[a][b] = 1;
    if(a == N && b == N) return true;
    bool can = false;
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            if(inside(a+i-1,b+j-1))
                if(!visited[a+i-1][b+j-1])
                    if(D[a+i-1][b+j-1] == '*')
                        can |= dfs(a+i-1,b+j-1);
    return can;
}

int main(int argc, char** argv) {
	N = atoi(argv[1]);
	int seed = atoi(argv[2]);
	srand(seed);
    bool check;
    do{
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j)
                visited[i][j] = 0;
        for(int i = 1; i <= N; ++i)
            for(int j = 1; j <= N; ++j){
                int q = rand() % 100;
                if(q <= 60 )
                    D[i][j] = '+';
                else D[i][j] = '*';
            }
        D[1][1] = D[N][N] = '*';
        check = dfs(1,1);
    }while(!check);


	cout << N  << endl;
	for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j)
            cout  << D[i][j];
        cout << endl;
	}
	return 0;
}
