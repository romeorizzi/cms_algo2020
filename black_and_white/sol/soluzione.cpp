#include<iostream>
#include<fstream>
#include<string>
#include<vector>

//MASSIMO 10^5 BIT ~ 2^17, quindi 2^18 SPAZIO NELL'ALBERO
#define POWDUE 262144u
#define STARTINDEX 131072u

#define BITMASK ~0ul

using namespace std;

typedef struct {
    uint32_t somma = 0;
    bool full = false;
    uint32_t sommaL = 0;
    uint32_t sommaR = 0;
} NODO_ELEM;

typedef struct {
    NODO_ELEM now;
    NODO_ELEM flipped;
    bool flipMe = false;
} NODO;

NODO_ELEM generaNodoElem(uint32_t n) {
    NODO_ELEM toRet;
    if(n) {
        toRet.somma = n;
        toRet.sommaL = n;
        toRet.sommaR = n;
        toRet.full = n;
    }
    return toRet;
}

NODO_ELEM EMPTY_ELEM = generaNodoElem(0);
NODO_ELEM FULL_ELEM = generaNodoElem(1);


NODO generaNodo(uint32_t n) {
    NODO toRet;
    if(n) {
        toRet.now = FULL_ELEM;
    } else {
        toRet.flipped = FULL_ELEM;
    }
    return toRet;
}

NODO EMPTY = generaNodo(0);
NODO FULL = generaNodo(1);


NODO_ELEM& calc_elem(NODO_ELEM& left, NODO_ELEM& right, NODO_ELEM& target) {
    target.full = left.full && right.full;
    target.sommaL = left.sommaL;
    target.sommaR = right.sommaR;
    target.somma = max(left.somma, right.somma);
    if(left.sommaR && right.sommaL) {
        target.somma = max(left.sommaR + right.sommaL, target.somma);
        if(left.full) {
            target.sommaL = left.sommaR + right.sommaL;
        }
        if(right.full) {
            target.sommaR = right.sommaR + left.sommaR;
        }
    }
    return target;
}

NODO& calc(NODO& left, NODO& right, NODO& target) {
    calc_elem(left.now, right.now, target.now);
    calc_elem(left.flipped, right.flipped, target.flipped);
    return target;
}

auto tree = vector<NODO>(POWDUE);


void flip(uint32_t index, bool force = false) {
    /* DIAGNOSTICA
    cout << " FLIP: " << index;
    */
    if(index >= POWDUE) return;
    NODO_ELEM tmp = tree[index].now;
    tree[index].now = tree[index].flipped;
    tree[index].flipped = tmp;
    tree[index].flipMe = false;
    if(index < STARTINDEX) {
        index *= 2;
        tree[index].flipMe = !tree[index].flipMe;
        tree[index + 1].flipMe = !tree[index + 1].flipMe;
    }
}

void update(uint32_t index, uint32_t l, uint32_t r, const uint32_t& i, const uint32_t& j) {
    if(tree[index].flipMe) {
        flip(index);
    } 
    
    if (r < i || l > j) // Completamente fuori
        return;
    
    
    
    if (l >= i && r <= j) { // Completamente dentro
        flip(index);
        return;
    }
    
    //else
    uint32_t mid = (l + r) / 2;
    update(2 * index, l, mid, i, j);
    update(2 * index + 1, mid + 1, r, i, j);
    /* DIAGNOSTICA
    if(tree[2 * index].flipMe || tree[2 * index + 1].flipMe) {
        cout << "SCAM SCAM SCAM SCAM SCAM SCAM SCAM SCAM" << endl;
        exit(-1);
    }
    */
    calc(tree[2 * index], tree[2 * index + 1], tree[index]);
    return;
}

void range_update(uint32_t i, uint32_t j) {
    update(1u, STARTINDEX, POWDUE - 1, i, j);
    return;    
}

NODO get_max(uint32_t index, uint32_t l, uint32_t r, const uint32_t& i, const uint32_t& j) {
    if(tree[index].flipMe) {
        flip(index);
    }
    if (r < i || l > j) // Completamente fuori
        return EMPTY;

    if (l >= i && r <= j) { // Completamente dentro
        return tree[index];
    }

    //else
    uint32_t mid = (l + r) / 2;
    NODO tmpL = get_max(2 * index, l, mid, i, j);
    NODO tmpR = get_max(2 * index + 1, mid + 1, r, i, j);
    NODO ret;
    /* DIAGNOSTICA
    if(tmpL.flipMe || tmpR.flipMe) {
        cout << "SCAM SCAM SCAM SCAM SCAM SCAM SCAM SCAM" << endl;
        exit(-1);
    }
    */
    return calc(tmpL, tmpR, ret);
}

uint32_t query(const uint32_t i, const uint32_t j) {
    NODO ret = get_max(1u, STARTINDEX, POWDUE - 1, i, j);
    return ret.now.somma;
}


int main(int argc, char** argv) {
    uint32_t n, m, action, i, j, tmp;

	ifstream fileIn;
    fileIn.open("input.txt");
    ofstream fileOut;
    fileOut.open("output.txt");

    if(!fileIn.is_open() || !fileOut.is_open()) return -1;

    cin.rdbuf(fileIn.rdbuf());
    cout.rdbuf(fileOut.rdbuf());
    
    cin >> n;

    for(uint32_t index = 0; index  < n; ++index) {
        cin >> tmp;
        tree[STARTINDEX + index] = tmp==0?EMPTY:FULL;
    }
    //finisco l'albero
    for(uint32_t index = STARTINDEX / 2; index > 0; index /= 2 ) {
        tmp = index * 2;
        for(uint32_t inner = index; inner < tmp; inner++) {
            calc(tree[inner * 2],tree[inner * 2 + 1],tree[inner]);
        }
    }

    cin >> m;
    for(uint32_t index = 0; index  < m; ++index) {
        cin >> action >> i >> j;
        if(action == 0) {
            cout << query(i + STARTINDEX - 1, j + STARTINDEX - 1) << endl;

            /* DIAGNOSTICA
            cout << endl;
            for(uint32_t index = 8192; index < POWDUE; index *= 2 ) {
                uint32_t banzai = 16;
                for(uint32_t inner = index; banzai > 0 && inner < index * 2; banzai--,inner++) {
                    cout << "{S:" << tree[inner].now.somma << "F:" << tree[inner].flipMe << "L:" << tree[inner].now.sommaL << "R:" << tree[inner].now.sommaR << "} ";
                }
                cout << endl;
            }
            cout << endl;
            */
        } else {
            range_update(i + STARTINDEX - 1, j + STARTINDEX - 1);
        }
    }



    return 0;
}