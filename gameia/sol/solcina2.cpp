/* SOURCE: https://www.shuzhiduo.com/A/obzbRR7MzE/
Rivisitato per funzionare su input singolo invece dell'intero batch.
Nella versione originale la numerazione dei vertici era in ordine DFS. Potrebbe non funzionare
*/
#include <bits/stdc++.h>
#include<fstream>
using namespace std;
const int maxn = 102000;
int head[maxn], edgecnt;
struct node{
    int to,next;
}E[maxn*2];
void add(int u, int v){
    E[edgecnt].to=v,E[edgecnt].next=head[u],head[u]=edgecnt++;
}
void init(){
    memset(head,-1,sizeof(head));
    edgecnt=0;
}
int sz[maxn];
bool flag;
void dfs(int u, int pre){
    if(flag) return;
    sz[u] = 1;
    int ans = 0;
    for(int i=head[u]; ~i; i=E[i].next){
        int v = E[i].to;
        if(v == pre) continue;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v]%2==1) ans++;
    }
    if(ans>=2) flag=1;
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

    int n,k;

    cin >> n >> k;
    if(n == 2) {
        cout << "1" << endl;
        return 0;
    }
    flag=0;
    init();
    for(int i=2; i<=n; i++){
        int x;
        cin >> x;
        add(i, x);
        add(x, i);
    }
    dfs(1,-1);
    if(flag||n%2) cout << "0" << endl;
    else if(n/2-1>k) cout << "0" << endl;
    else cout << "1" << endl;
    return 0;
}
