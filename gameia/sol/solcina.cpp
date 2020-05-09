/*
SOURCE: https://blog.csdn.net/yjf3151731373/article/details/77072661
Rivisitato per funzionare su input singolo invece dell'intero batch.
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include <bits/stdc++.h>
using namespace std;
const int N =200000+10;
vector<int>p[N];
int a[N];
void dfs(int u,int fa)
{
    int cnt=0;
    if(p[u].size()==0)
    {
        a[u]=1;
        return ;
    }
    for(int i=0;i<p[u].size();i++)
    {
        int v=p[u][i];
        dfs(v,u);
        if(a[v]==1) cnt++;
        if(a[v]==2)  {a[u]=2; return ;}
    }
    if(cnt>1) a[u]=2;
    else if(cnt==1) a[u]=0;
    else if(cnt==0) a[u]=1;
    return ;
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


    int n, k;
    cin >> n >> k;
    for(int i=0;i<=n;i++) p[i].clear();
    for(int i=2;i<=n;i++)
    {
        int x;
        cin >> x;
        p[x].push_back(i);
    }
    a[1]=2;
    dfs(1,-1);
    if(a[1]==0&&(n-2)/2<=k) cout << "1" << endl;
    else cout << "0" << endl;

    return 0;
}