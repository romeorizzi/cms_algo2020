/*
Generatore di input per il problema Collage.

arg1 --> numero di nodi dell'albero da generare
arg2 --> modalita'
arg3 --> seed

VALORI ACCETTABILI PER MODALITA':
- 0 nessun aiuto
- 1 numero minimo di aiuti
- 2 tanti aiuti
- 3 random aiuti
- 4 un albero in cui Bob vince pelo pelo
- 5 un albero in cui Bob perde, ma avrebbe potuto vincere avendo avuto a disposizione piu' gettoni

USI SPECIALI:
arg1 < 0: i casi di esempio
arg1 -100: un albero in cui bob vince
*/
#include<iostream>
#include<cassert>
#include<cstdlib>
#include<random>
#include<set>
#include<vector>

using namespace std;

#define MAX_LEN 100000
#define N_MOD 6
#define LOG2(X) ((unsigned) (8*sizeof (unsigned long long) - __builtin_clzll((X)) - 1))


/*un po' una schifezza, ma per il suo scopo limitato va bene*/
class NODO {
    public:

    NODO(int id) : uniqueId(id) {};
    NODO(int id, int _father) : uniqueId(id), fatherId(_father) {};
    vector<NODO> figli;
    int uniqueId;
    int fatherId;
};

int uniqueIDCounter = 2;


void recursiveCall(NODO& node, int len, bool bobWins = false) {
    assert(len >= 0);
    if(len == 0) return;
    if(len == 1) {
        node.figli.push_back(NODO(uniqueIDCounter++,node.uniqueId));
        return;
    } else if(len == 2) {
        if(rand() % 2 && !bobWins) {
            node.figli.push_back(NODO(uniqueIDCounter++,node.uniqueId));
            node.figli.push_back(NODO(uniqueIDCounter++,node.uniqueId));
        } else {
            node.figli.push_back(NODO(uniqueIDCounter++,node.uniqueId));
            recursiveCall(*node.figli.rbegin(), 1, bobWins);
        }
        return;
    } else {
        int logC = LOG2(len + 1) + 1;
        
        //Bucket troppo grandi semplificano troppo la vita.
        //Per esempio con lunghezza mille la dimensione massima viene fissata a 500, cosi' da avere ALMENO due bucket.
        int maxBucketSize = max(1, len / ((rand() % logC) + 1));
        int bucketSize;
        if(bobWins && (len % 2)) {
            bucketSize = min(len, 1 + (rand() % maxBucketSize));
            bucketSize = max(bucketSize, 2);
            if(!(bucketSize % 2)) {
                --bucketSize;
            }
            node.figli.push_back(NODO(uniqueIDCounter++,node.uniqueId));
            recursiveCall(*node.figli.rbegin(), bucketSize - 1, bobWins);
            len -= bucketSize;
        }
        //Continuo a suddividere finche' ho ancora spazio a disposizione.
        while(len > 0) {
            bucketSize = min(len, 1 + (rand() % maxBucketSize));
            if(bobWins && (bucketSize % 2)) {
                assert(!(len % 2));
                ++bucketSize;
            }
            //Aggiungo un nuovo figlio
            node.figli.push_back(NODO(uniqueIDCounter++,node.uniqueId));
            
            //Suddivido anche il figlio
            recursiveCall(*node.figli.rbegin(), bucketSize - 1, bobWins);
            len -= bucketSize;
        }
    }
}

/*
void visitBKP(NODO& node, bool ignoreMe = false) {
    if(!ignoreMe) {
        cout << node.fatherId << " ";
    }
    if(!node.figli.empty()) {
        for(size_t i = 0; i < node.figli.size(); i++) {
            visitPrint(node.figli[i]);
        }
    }
}
*/
void visit(vector<int>& vec, NODO& node) {
    vec[node.uniqueId] = node.fatherId;
    if(!node.figli.empty()) {
        for(size_t i = 0; i < node.figli.size(); i++) {
            visit(vec, node.figli[i]);
        }
    }
}

/*
Solo il primo nodo verra' ignorato.
*/
void visitPrint(NODO& root) {
    auto toBeFilled = vector<int>(uniqueIDCounter, 0);
    if(!root.figli.empty()) {
        for(size_t i = 0; i < root.figli.size(); i++) {
            visit(toBeFilled, root.figli[i]);
        }
        for(size_t i = 2; i < toBeFilled.size(); i++) {
            cout << toBeFilled[i] << " ";
        }
    }
}

void treeMode(int& len){
    
    NODO radice(1);
    if(len > 1)
        recursiveCall(radice, len - 1);

    //visitPrint(radice, true);
    visitPrint(radice);
}

void bobWin(int&len) {
    assert(len > 1);
    if(len%2){
        --len;
    }
    NODO radice(1);

    recursiveCall(radice, len - 1, true);
    //visitPrint(radice, true);
    visitPrint(radice);
}

int main(int argc, char** argv) {
    assert(argc > 1);

    //CASI DI ESEMPIO
    if(argc == 2) {
        int exNumber = atoi(argv[1]);
        assert(exNumber < 0);
        switch(exNumber)
        {
            case -1:
                cout << "2 1" << endl << "1" << endl;
                break;
            case -2:
                cout << "3 1" << endl << "1 2" << endl;
                break;
            case -3:
                cout << "4 1" << endl << "1 2 3" << endl;
                break;
            case -4:
                cout << "4 0" << endl << "1 2 3" << endl;
                break;
            default:
                return - 1;
                break;
        }
        return 0;
    }
    assert(argc == 4);

    int len = atoi(argv[1]);
    assert(len <= MAX_LEN && len > 0);

    int mod = atoi(argv[2]);
    assert(mod < N_MOD && mod >= 0);

    int seed = atoi(argv[3]);
    srand(seed);

    if(mod >= 4 && (len % 2))
        --len;

    cout << len << " ";
    switch(mod) {
        case 0:
            cout << 0 << endl;
            break;
        case 1:
        case 4:
            cout << max(0, len/2 - 1) << endl;
            break;
        case 2:
            cout << len << endl;
            break;
        case 3:
            cout << rand() % len << endl;
            break;
        case 5:
            cout << max(0, len/2 - 2) << endl;
            break;
        default:
            return -1;
    }
    if(mod >= 4) {
        bobWin(len);
    } else {
        treeMode(len);
    }
    cout << endl;
    return 0;
}