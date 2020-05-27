/*
    Federico Glaudo
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#define MAXN 100100
using namespace std;
 
int N;
vector <int> aa[MAXN];
vector <vector <int> > cc; // componenti connesse
 
int qq=0;
int id[MAXN];
 
int tt=0;
int label[MAXN];
int openingTime[MAXN];
bool open[MAXN];
bool visited[MAXN];
 
stack <int> coda;
 
void dfs(int v){
    visited[v]=1;
    openingTime[v]=label[v]=tt;
    tt++;
    coda.push(v);
    open[v]=1;
     
    for(int i=0;i<int(aa[v].size());i++){
        int a=aa[v][i];
        if(!visited[a]){
            dfs(a);
            label[v]=min(label[v], label[a]);
        }
        else if(open[a])label[v]=min(label[v],openingTime[a]);
    }
     
    if(openingTime[v]==label[v]){
        id[v]=qq;
        open[v]=0;
        while(coda.top()!=v){
            id[coda.top()]=qq;
            open[coda.top()]=0;
            coda.pop();
        }
        coda.pop();
        qq++;
    }
}

int scc(int n, int e, int da[], int a[]) {
	int M;
	N=n, M=e;
	
	for(int i=0;i<M;i++) aa[da[i]].push_back(a[i]);
	
    for(int i=0;i<N;i++) if(!visited[i])dfs(i);
    
    cc.resize(qq);
    for(int i=0;i<N;i++)cc[id[i]].push_back(i);
    sort(cc.begin(), cc.end());
    
    return cc.size();
}
 
