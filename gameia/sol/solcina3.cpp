

/*
SOURCE: https://www.bbsmax.com/A/QW5Y821KJm/
Rivisitato per funzionare su input singolo invece dell'intero batch.
Nella versione originale la numerazione dei vertici era in ordine DFS. Potrebbe non funzionare
*/
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int n, k;
vector<int> G[110000];
bool ans;
int dfs(int x)
{
    int s = 1;
    for (auto& y : G[x])
        s += dfs(y);
    if (s == 2) k--;
    if (s > 2) ans = 0;
    return s % 2;
}
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    if(in.fail() || out.fail()) {
        return -1;
    }
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());

    cin >> n >> k;
    if(n == 2) {
        cout << "1" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) G[i].clear();
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        G[x].push_back(i);
    }
    if (n&1) cout << "0" << endl;
    else
    {
        ans = 1;
        dfs(1);
        if (!ans || k < -1) cout << "0" << endl;
        else cout << "1" << endl;
    }
}


