/*
DISCLAIMER: e' la prima soluzione che mi e' venuta in mente.
Come spesso accade non e' ne' la piu' elegante ne' la migliore.

Ho cercato di commentarla il piu' possibile, ma forse le altre soluzioni potrebbero risultarvi piu' semplici da capire.
*/

#include<memory>
#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<string>
using namespace std;
class NODE {
    public:
    shared_ptr<NODE> father;
    list<shared_ptr<NODE>> figli;
};
#define WHITNEY 0;
#define BOB 1;


vector<shared_ptr<NODE>> recidi(shared_ptr<NODE> nodo) {
    vector<shared_ptr<NODE>> nuoviAlberi;
    if(nodo->figli.size() < 2) return nuoviAlberi;

    for(auto it = nodo->figli.begin(); it != nodo->figli.end();) {
        if((*it)->figli.size() != 0) {
            (*it)->father = NULL;
            nuoviAlberi.push_back(*it);
            it = nodo->figli.erase(it);
        } else {
            it++;
        }
    }
    return nuoviAlberi;
}

/*
Inverte le relazioni padre/figlio fino ad una foglia (non compresa)
      +
   °     -
 - - -     -

        °
   -  -   -  +
               -
                 -

*/
shared_ptr<NODE> cambio(shared_ptr<NODE> nodo) {
    auto primoFiglio = nodo->figli.front();
    auto oldFather = nodo;
    while(primoFiglio->figli.size() != 0) {
        oldFather->figli.pop_front();
        oldFather->father = primoFiglio;
        primoFiglio->father = NULL;
        primoFiglio->figli.push_back(oldFather);

        oldFather = primoFiglio;
        primoFiglio = primoFiglio->figli.front();
    }
    return primoFiglio->father;
}

int rec(shared_ptr<NODE> nodo, int& bobActions) {
    if(bobActions < 0) {
        //cout << "Ho finito le azioni!" << endl;
        return WHITNEY;
    }

    auto res = recidi(nodo);
    //Se rimangono tanti figli dopo aver reciso, Whitney Vince per forza.
    if(nodo->figli.size() > 1) {
        return WHITNEY;
    }

    //Se ho reciso fin troppo, non va bene. Cambio radice.
    if(nodo->figli.size() == 0) {
        for(auto n : res) {
            n->father = nodo;
            nodo->figli.push_back(n);
        }
        return rec(cambio(nodo), bobActions);
    }
    //Se ho effettivamente reciso qualcosa...
    if(res.size() > 0) {
        for(auto n : res) {
            if(rec(n,--bobActions) == 0) {
                return WHITNEY;
            }
        }
    } else {
        //Altrimenti se l'unico figlio ha almeno un altro figlio, inverto parentela.
        auto unico = *(nodo->figli.begin());
        if(unico->figli.size() > 0) {
            nodo->figli.pop_back();
            nodo->father = unico;
            unico->figli.push_back(nodo);
            unico->father = NULL;
            return rec(unico, bobActions);
        }
    }
    //Se Bob e' sopravvissuto a tutti questi controlli si merita la vittoria.
    return BOB;
}


/*
Partendo dalla radice spezzetto l'albero con queste regole:
- Se ha piu' di un figlio, recido tutti i legami coi figli che hanno nipoti, creando ALMENO 1 albero (uno composto da padre e figli senza figli, gli altri da figli coi nipoti)
    - Se il primo albero cosi' ottenuto ha un numero di figli > 1, Bob perde.
    - Altrimenti se ha 0 figli, devo cambiare radice.
    - Altrimenti,
        - Se ci sono altri alberi sottraggo 1 a bobActions. Ripeto il procedimento con tutti gli altri alberi ottenuti.
        - Altrimenti, se l'unico figlio ha almeno un altro figlio, inverto parentela e richiamo ricorsivamente.
*/
int solve(vector<shared_ptr<NODE>>& tree, int& bobActions) {
    if(tree[1]->figli.size() == 0) return WHITNEY;

    return rec(tree[1], bobActions);
}



int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    if(in.fail() || out.fail()) {
        return -1;
    }
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());

    int bobActions, treeSize;

    cin >> treeSize >> bobActions;
    //L'albero e' fatto da $treeSize nodi.
    auto tree = vector<shared_ptr<NODE>>();
    for(int i = 0; i <= treeSize; i++) {
        tree.push_back(make_shared<NODE>());
    }
    int tmp;
    for(int i = 2; i <= treeSize; i++) {
        cin >> tmp;
        //il nodo iesimo ha come padre il nodo tmp;
        tree[i]->father = tree[tmp];
        //ovviamente quindi anche il nodo tmp avra' come figlio il nodo iesimo.
        tree[tmp]->figli.push_back(tree[i]);
    }
    cout << solve(tree, bobActions) << endl;

    return 0;
}