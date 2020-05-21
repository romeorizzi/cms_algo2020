#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> //hopcroft
#define MAX_N 500 //questo è il numero di (nodi-1) *2 +Costante


#define EVAL



using namespace std;

//////////////////////////////INIZIO PARTE DI HOPCROFT///////////////////////
const int MAXN1 = 50000;
const int MAXN2 = 50000;
const int MAXM = 150000;
int n1, n2, edges, last[MAXN1], prev[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];


void init(int _n1, int _n2) {
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}

void addEdge(int u, int v) {
    head[edges] = v;
    prev[edges] = last[u];
    last[u] = edges++;
}

void bfs() {
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) {
        if (!used[u]) {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = prev[e]) {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1) {
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = prev[e]) {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching() {
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}


//////////////////////////////FINE PARTE DI HOPCROFT///////////////////////
typedef pair<int, int> edge_t;


//questa riga non funziona
//vector< vector<int> > rimappabile(MAX_N, vector<int>(MAX_N,-1)); //P[Et][Ep] testo e pattern
int rimappabile[MAX_N][MAX_N];

//aggiunte per accesso in o(1)
vector< vector<int> > l_posizione_in_ordine(MAX_N, vector<int>(MAX_N,-1)); 

vector< vector<int> > posizione_in_ordine(MAX_N, vector<int>(MAX_N,-1)); 




/*
LEGENDA (ordine e l_ordine)

ordine.first() ---> nodo di partenza
ordine.second() --> nodo di arrivo

*/

vector< vector<int> > nodi; //per ogni nodo tengo i suoi vicini
vector< vector<bool> > labeled; //per ogni arco (xk si sdoppiano) tengo quelli a cui ho assegnato una label
vector< edge_t > ordine = vector < edge_t > (); // per ora li pusho su una coda(poi si vedrà)
int N_p;

//albero piccolo (little)
vector< vector<int> > l_nodi; //per ogni nodo tengo i suoi vicini
vector< vector<bool> > l_labeled; //per ogni arco (xk si sdoppiano) tengo quelli a cui ho assegnato una label
vector< edge_t > l_ordine = vector < edge_t > (); // per ora li pusho su una coda(poi si vedrà)
int N_lp;


void label_dfs(int father, int son){
  int pos_son_in_father;//posizione del nodo figlio nella lista dei vicini del padre
//attenzione che se mi hai già labellato puoi pure ritornare!!
  for(int i = 0; i<nodi.at(father).size(); ++i)
    if(nodi[father][i] == son){
      if(labeled[father][i])
        return;
      pos_son_in_father = i;
      break;
    }
  //labello tutti i figli di son(eccetto father) sono stati labelati 
  for(int i = 0; i< nodi.at(son).size(); ++i)
    if(nodi[son][i]!= father)
      label_dfs(son, nodi[son][i]);


  //ora posso pushare son e labellarlo
  labeled[father][pos_son_in_father] = true;

  ordine.push_back(pair<int,int>(father,son));


//AGGIUNTA Affinche dato un arco so dire in che ordine è stato messo nell'array ordine
  posizione_in_ordine[father][son]=ordine.size()-1;

}

//stessa funzione di sopra ma per il figlio
void l_label_dfs(int father, int son){
  int pos_son_in_father;//posizione del nodo figlio nella lista dei vicini del padre
//attenzione che se mi hai già labellato puoi pure ritornare!!
  for(int i = 0; i<l_nodi.at(father).size(); ++i)
    if(l_nodi[father][i] == son){
      if(l_labeled[father][i])
        return;
      pos_son_in_father = i;
      break;
    }
  //labello tutti i figli di son(eccetto father) sono stati labelati 
  for(int i = 0; i< l_nodi.at(son).size(); ++i)
    if(l_nodi[son][i]!= father)
      l_label_dfs(son, l_nodi[son][i]);


  //ora posso pushare son e labellarlo
  l_labeled[father][pos_son_in_father] = true;
  l_ordine.push_back(pair<int,int>(father,son));

//AGGIUNTA Affinche dato un arco so dire in che ordine è stato messo nell'array ordine
  l_posizione_in_ordine[father][son]=l_ordine.size()-1;
}

//questo è da sistemare
void is_remappable_check(){

  for(int i=0; i<ordine.size(); ++i)
    for(int j=0; j<l_ordine.size(); ++j)
      if(l_nodi[l_ordine[j].second].size() == 1)
        rimappabile[i][j] = 1; //rimappabile è basato sull'ordine (quello della dfs)
      else if(nodi[ordine[i].second].size() == 1)
        continue;
      else{ //devo usare hopcroft per vedere se sono rimappabili
        init(nodi[ordine[i].second].size(), l_nodi[l_ordine[j].second].size());//il -1 è dovuto al ramo che torna indietro
        //i nodi si contano da 1
//QUI HO INTRODOTTO UN ERRORE
        cout<<"size 1 = "<<nodi[ordine[i].second].size()<< " size 2 = " <<  l_nodi[l_ordine[j].second].size()<<endl;

        cout<<"arco fat ("<<ordine[i].first<<", "<<ordine[i].second<<")\n";
        cout<<"arco pat ("<<l_ordine[j].first<<", "<<l_ordine[j].second<<")\n";


        for(int x=0; x<nodi[ordine[i].second].size(); ++x){
          for(int y=0; y<l_nodi[l_ordine[j].second].size(); ++y){
            if(nodi[ordine[i].second][x] == ordine[i].first || l_nodi[l_ordine[j].second][y] == l_ordine[j].first )//devo escludere i due nodi che tornano indietro
              continue;

            int Et=posizione_in_ordine[ordine[i].second][nodi[ordine[i].second][x]];
            int Ep=l_posizione_in_ordine[l_ordine[j].second][l_nodi[l_ordine[j].second][y]];
            cout<<"arco Et "<<Et<<"\n";
            cout<<"arco Ep "<<Ep<<"\n";
            if(rimappabile[Et][Ep]){
              addEdge(x,y);//metto arco         //per il caso in cui torna indietro non metto l'arco
            }

          }
        }

        cout<<  maxMatching() <<"********\n";
        cout<<l_nodi[l_ordine[j].second].size()-1<<"\n";
        if( maxMatching() == l_nodi[l_ordine[j].second].size()-1) //questa riga lo fa impallare
            rimappabile[i][j]=1;  

      }
    
}

bool is_remappable(){

  for(int i=0; i<ordine.size(); ++i)
    for(int j=0; j<l_ordine.size(); ++j)
      if(rimappabile[i][j]==1 && rimappabile[posizione_in_ordine[ordine[i].second][ordine[i].first]][l_posizione_in_ordine[l_ordine[j].second][l_ordine[j].first]] == 1){
        cout<<"i="<<i;
        cout<<" j="<<j<<endl;
        cout<<"i^-1="<<posizione_in_ordine[ordine[i].second][ordine[i].first];
        cout<<" j^-1="<<l_posizione_in_ordine[l_ordine[j].second][l_ordine[j].first] <<endl;


        return 1;
      }

  return 0;

}


int main() {

#ifdef EVAL
	ifstream in("input.txt");
	ofstream out("output.txt");
#else
	istream &in(cin);
	ostream &out(cout);
#endif

//leggo il primo albero
  in>>N_p;

  nodi = vector< vector<int> > (N_p);
  labeled = vector< vector<bool> > (N_p);

  int id_nodo, id_figlio;

  for (int i = 0; i < N_p-1; ++i){
    in>>id_nodo;
    in>>id_figlio;
    nodi.at(id_nodo).push_back(id_figlio);
    nodi.at(id_figlio).push_back(id_nodo);
    labeled.at(id_nodo).push_back(false);
    labeled.at(id_figlio).push_back(false);
  }

  #ifdef DEBUG
  cout<<"Vicini: \n";
  for (int i = 0; i < N_p; ++i){
    cout<<i<<": ";
    for(int j = 0; j< nodi.at(i).size(); ++j)    
      cout<<nodi[i][j]<<" ";
    cout<<"\n";

  }
  #endif


//leggo il secondo albero (sotto-albero isomorfo)
  in>>N_lp;

  l_nodi = vector< vector<int> > (N_lp);
  l_labeled = vector< vector<bool> > (N_lp);

  for (int i = 0; i < N_lp-1; ++i){
    in>>id_nodo;
    in>>id_figlio;
    l_nodi.at(id_nodo).push_back(id_figlio);
    l_nodi.at(id_figlio).push_back(id_nodo);
    l_labeled.at(id_nodo).push_back(false);
    l_labeled.at(id_figlio).push_back(false);
  }

  #ifdef DEBUG
  cout<<"Vicini secondo: \n";
  for (int i = 0; i < N_lp; ++i){
    cout<<i<<": ";
    for(int j = 0; j< l_nodi.at(i).size(); ++j)    
      cout<<l_nodi[i][j]<<" ";
    cout<<"\n";

  }
  #endif



//per tutti gli archi non labellati voglio lanciare la dfs
  for (int i = 0; i < N_p; ++i){
    for(int j = 0; j< labeled.at(i).size(); ++j)    
      label_dfs(i,nodi[i][j]);
  }

//anche per il figlio
  for (int i = 0; i < N_lp; ++i){
    for(int j = 0; j< l_labeled.at(i).size(); ++j)    
      l_label_dfs(i,l_nodi[i][j]);
  }

  



  #ifdef DEBUG 
  cout<<"Boolean vicini: \n";
  for (int i = 0; i < N_p; ++i){
    cout<<i<<": ";
    for(int j = 0; j< labeled.at(i).size(); ++j)    
      cout<<labeled[i][j]<<" ";
    cout<<"\n";

  }

  cout<<"Boolean vicini secondo: \n";
  for (int i = 0; i < N_lp; ++i){
    cout<<i<<": ";
    for(int j = 0; j< l_labeled.at(i).size(); ++j)    
      cout<<l_labeled[i][j]<<" ";
    cout<<"\n";

  }



  #endif



  #ifdef DEBUG 
  cout<<"Ordine labellamenti (partenza, arrivo): \n";
  for(int i = 0; i< ordine.size(); ++i)    
      cout<<"("<<ordine[i].first<<", " <<ordine[i].second<<") ";
  cout<<"\n";

  cout<<"Ordine labellamenti secondo:\n";
  for(int i = 0; i< l_ordine.size(); ++i)    
      cout<<"("<<l_ordine[i].first<<", " <<l_ordine[i].second<<") ";
  cout<<"\n";

  cout<<"Posizione in ordine matrix:\n";
  for(int i = 0; i < nodi.size(); ++i){
    for(int j = 0; j < nodi.size(); ++j)    
      printf("%4i ", posizione_in_ordine[i][j]);
    cout<<"\n";
  }
  

  #endif


  is_remappable_check();

  out<<is_remappable();  

  cout<<is_remappable()<<"*********************\n";

  #ifdef DEBUG 
  for(int i=0; i<ordine.size(); ++i){
    for(int j=0; j<l_ordine.size(); ++j)
      cout<<rimappabile[i][j]<<" ";
    cout<<"\n";
    }

  #endif


  return 0;
}

