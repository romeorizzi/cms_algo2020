#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;


auto associativeTable = vector<vector<const char*>>(11);
typedef struct {
    vector<uint64_t> conta;
    vector<const char*>* ref;
} nodoG;
nodoG generateNode(uint32_t code) {
    nodoG toRet;
    toRet.conta = vector<uint64_t>(associativeTable[code].size());
    toRet.ref = &associativeTable[code];
    return toRet;
}

inline uint64_t minimo(uint64_t& a, uint64_t b) {
    return a < b ? a : b;
}

uint64_t recipeChange(nodoG& o, nodoG& n) {
    auto oRef = *o.ref;
    auto nRef = *n.ref;
    uint64_t superMinimum = ~0UL, min;
    uint32_t index = 0;
    for(auto newTag : nRef) {
        min = ~0UL;
        for(uint32_t i = 0; i < o.conta.size(); i++) {
            if(oRef[i][0] == newTag[0] && oRef[i][1] == newTag[1] && oRef[i][2] == newTag[2]) {
                min = minimo(min, o.conta[i] + 1);
            } else if (oRef[i][1] == newTag[0] && oRef[i][2] == newTag[1]){
                min = minimo(min, o.conta[i] + 2);
            } else if (oRef[i][2] == newTag[0]) {
                min = minimo(min, o.conta[i] + 3);
            } else {
                min = minimo(min, o.conta[i] + 4);
            }
        }
        n.conta[index++] = min;
        superMinimum = minimo(superMinimum, min);
    }
    return superMinimum;
}

int main(int argc, char** argv)
{
    //====================================================
    //PARTE OBBLIGATORIA REINDIRIZZAMENTO STDIN/OUT
    //====================================================
    ifstream fileIn;
    fileIn.open("input.txt");
    ofstream fileOut;
    fileOut.open("output.txt");

    if(!fileIn.is_open() || !fileOut.is_open()) return -1;

    cin.rdbuf(fileIn.rdbuf());
    cout.rdbuf(fileOut.rdbuf());

    associativeTable[0] = vector<const char*>({"CCC"});
    associativeTable[1] = vector<const char*>({"CCP","PCC","CPC"});
    associativeTable[2] = vector<const char*>({"CCM","MCC","CMC"});

    associativeTable[3] = vector<const char*>({"PPP"});
    associativeTable[4] = vector<const char*>({"PPC","CPP","PCP"});
    associativeTable[5] = vector<const char*>({"PPM","MPP","PMP"});

    associativeTable[6] = vector<const char*>({"MMM"});
    associativeTable[7] = vector<const char*>({"MMC","CMM","MCM"});
    associativeTable[8] = vector<const char*>({"MMP","PMM","MPM"});

    associativeTable[9] = vector<const char*>({"CPM","CMP","PCM","PMC","MCP","MPC"});
    associativeTable[10] = vector<const char*>({"AAA"});

    uint32_t readCode, N;
    cin >> N;
    auto currentCombo = generateNode(10);
    nodoG oldCombo;
    uint64_t count = 0;

    for(uint i = 0; i < N ; ++i) {
        cin >> readCode;
        oldCombo = currentCombo;
        currentCombo = generateNode(readCode);
        count = recipeChange(oldCombo, currentCombo);
    }
    cout << count << endl;
    return 0;
}
