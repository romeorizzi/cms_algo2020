/*
Generatore di input per il problema Collage.

arg1 --> lunghezza della sequenza numerica da generare
arg2 --> numero di colori disponibili (1 - 256), non il valore massimo (0 - 255)
arg3 --> modalita'
arg4 --> seed

VALORI ACCETTABILI PER MODALITA':
- 0 parentesi
- 1 chi2
- 2 completamente random
- 3 con tanti numeri ripetuti
*/
#include<iostream>
#include<cassert>
#include<cstdlib>
#include<random>
#include<set>
#include<vector>

using namespace std;

#define MAX_LEN 1000
#define MAX_COLOR_PALETTE 256
#define N_MOD 4
#define LOG2(X) ((unsigned) (8*sizeof (unsigned long long) - __builtin_clzll((X)) - 1))


/*un po' una schifezza, ma per il suo scopo limitato va bene*/
class NODO {
    public:
#ifdef DEBUGME
    NODO(int _colore, int id = 0) : colore(_colore), uniqueID(id) {};
#else
    NODO(int _colore, int id = 0) : colore(_colore) {};
#endif
    int colore;
    vector<NODO> figli;
    bool isDouble = false;
#ifdef DEBUGME
    int uniqueID;
#endif
};

#ifdef DEBUGME
int uniqueIDCounter = 123;
#endif
/*
Divide il nodo in bucket in base alla sua lunghezza. Ogni bucket sara' un figlio e rappresentera' una "parentesi".
Ogni bucket viene ridiviso ricorsivamente.
I colori gia' usati hanno una maggior possibilita' di essere usati di nuovo per aumentare il grado di difficolta'.
*/
void recursiveCall(NODO& node, int len, set<int>& usedColors, int& numColors) {
#ifdef DEBUGME
    cout << "LEN:" << len << " ID:" << node.uniqueID << endl;
#endif
    assert(len > 0);
    //se mi e' rimasto da distribuire una lunghezza < 3 si trattera' o di un unico elemento, o di un paio di parentesi senza alcun elemento al loro interno.
    if(len == 1) {
        return;
    } else if(len == 2) {
        node.isDouble = true;
        return;
    } else {
        //sottraggo 2, ovvero le "parentesi esterne"
        len -= 2;
        int logC = LOG2(len + 1) + 1;
        
        //Bucket troppo grandi semplificano troppo la vita.
        //Per esempio con lunghezza mille la dimensione massima viene fissata a 500, cosi' da avere ALMENO due bucket.
        int maxBucketSize = max(1, len / ((rand() % logC) + 1));
        int newColor, bucketSize;
        
        //Continuo a suddividere finche' ho ancora spazio a disposizione.
        while(len > 0) {
            newColor = rand() % (numColors * 3);
            bucketSize = min(len, 1 + (rand() % maxBucketSize));
            if(newColor >= numColors) {
                newColor = newColor % usedColors.size();
                auto it = usedColors.begin();
                advance(it, newColor);
                newColor = *it;
            }
            if(newColor == node.colore) {
                newColor = (newColor + 1) % numColors;
            }
            usedColors.insert(newColor);
            
            #ifdef DEBUGME            
            node.figli.push_back(NODO(newColor, uniqueIDCounter++));
            #else
            //Aggiungo un nuovo figlio
            node.figli.push_back(NODO(newColor));
            #endif
            
            //Suddivido anche il figlio
            recursiveCall(*node.figli.rbegin(), bucketSize, usedColors, numColors);
            len -= bucketSize;


            #ifdef DEBUGME 
            if(node.uniqueID == 0) cout << "LEN:" << len << " ID:" << node.uniqueID << " B:" << bucketSize << " M:" << maxBucketSize << endl;
            #endif
        }
    }
}

/*
Solo il primo nodo verra' ignorato.
Vedi --> treeMode
*/
void visitPrint(NODO& node, bool ignoreMe = false) {
    if(!ignoreMe) {
        cout << node.colore << " ";
    }
    if(!node.figli.empty()) {
        for(size_t i = 0; i < node.figli.size(); i++) {
            visitPrint(node.figli[i]);
        }
    }
    if(!ignoreMe && (node.isDouble || !node.figli.empty())) {
        cout << node.colore << " ";
    }
}

/* CODICE DI RIFERIMENTO ==> 0
Generazione simil formula con parentesi.
Dopo una serie di chiamate ricorsive in cui si genera un albero, alla fine con una visita si ottiene una cosa molto simile ad una formula formata da parentesi.
La prima parentesi e' "invisibile", cosi' da ottenere una formula che non e' necessariamente fatta cosi':
((.........)(.......).....(......))
ma molto piu' probabilmente sara':
(.........)(.......).....(......)
*/
void treeMode(int& len, int& numColors, int& seed){
    
    auto usedColors = set<int>();
    srand(seed);
    NODO radice (rand() % numColors);
    usedColors.insert(radice.colore);


    recursiveCall(radice, len + 2, usedColors, numColors);

    visitPrint(radice, true);
}




/* CODICE DI RIFERIMENTO ==> 1
Generazione con distribuzione Chi2
*/
void chiMode(int& len, int& numColors, int& seed){
    auto generator = default_random_engine(seed);
    int logC = LOG2(numColors) + 1;
    assert(logC > 0 && logC <= numColors);
    chi_squared_distribution<double> distribution((logC + 1) / 2);

    int count = 0;
    int tmp;
    while(count < len - 1) {
        tmp = distribution(generator);
        if(tmp >= 0 && tmp < numColors) {
            count++;
            cout << tmp << " ";
        }
    }
    cout << (int)distribution(generator) % numColors << endl;
}





/* CODICE DI RIFERIMENTO ==> 2
Generazione molto semplice: col classico rand() % colori disponibili.
*/
void randomMode(int& len, int& numColors, int& seed){
    srand(seed);

    for(int i = 0; i < len - 1; i++) {
        cout << rand() % numColors << " ";
    }
    cout << rand() % numColors << endl;
}

/* CODICE DI RIFERIMENTO ==> 3
Generazione in cui i primi ca. (log(numColors) + 1) colori hanno una grossa probabilita' di uscire. Piu' un ulteriore probabilita' che esca il colore 0.
*/
void repetitionMode(int& len, int& numColors, int& seed){
    srand(seed);

    int logC = LOG2(numColors) + 1;
    assert(logC > 0 && logC <= numColors);

    int modN = 10 * numColors;
    
    int temp;
    for(int i = 0; i < len - 1; i++) {
        temp = rand() % modN;
        if(temp > numColors) {
            cout << (logC & 1 ? 0 : temp % logC) << " ";
        } else {
            cout << temp % numColors << " ";
        }
    }
    cout << rand() % logC << endl;    
}



int main(int argc, char** argv) {
    assert(argc > 0);

    //CASI DI ESEMPIO
    if(argc == 2) {
        int exNumber = atoi(argv[1]);
        assert(exNumber < 0);
        switch(exNumber)
        {
            case -1:
                cout << "3" << endl << "1 2 1" << endl;
                break;
            case -2:
                cout << "7" << endl << "1 1 2 3 1 2 1" << endl;
                break;
            default:
                return - 1;
                break;
        }
        return 0;
    }
    assert(argc == 5);

    int len = atoi(argv[1]);
    assert(len <= MAX_LEN && len > 0);

    int numColors = atoi(argv[2]);
    assert(numColors <= MAX_COLOR_PALETTE && numColors > 0);

    int mod = atoi(argv[3]);
    assert(mod < N_MOD && mod >= 0);

    int seed = atoi(argv[4]);

    cout << len << endl;
    switch(mod) {
        case 0:
            treeMode(len, numColors, seed);
            break;
        case 1:
            chiMode(len, numColors, seed);
            break;
        case 2:
            randomMode(len, numColors, seed);
            break;
        case 3:
            repetitionMode(len, numColors, seed);
            break;
        default:
            return -1;
    }

    return 0;
}