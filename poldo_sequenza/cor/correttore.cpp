#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readAndFail(ifstream& file, uint32_t& target, const string message = "File malformattato\n") {
    file >> target;
    if(file.fail()) {
        cerr << message;
        cout << 0.0f << endl;
        exit(0);
    }
}

int main(int argc, char *argv[])
{
    if(argc < 4)
    {
        cerr << "Usage: " << argv[0] << " <input> <correct output> <test output>" << endl;
        return 1;
    }
    ifstream fileIn,fileOut,fileCor;
    fileIn.open(argv[1]);
    if(fileIn.fail()) {
        cerr << "Impossibile aprire il file di input " << argv[1] << "." << endl;
        return 1;
    }
    fileCor.open(argv[2]);
    if(fileCor.fail()) {
        cerr << "Impossibile aprire il file di output corretto " << argv[2] << "." << endl;
        return 1;
    }
    fileOut.open(argv[3]);
    if(fileOut.fail()) {
        cerr << "Impossibile aprire il file di output sottomesso " << argv[3] << "." << endl;
        cout << 0.0f << endl;
        return 0;
    }

    uint32_t tmp, old, tmpIn, sequenceLen;
    readAndFail(fileCor, sequenceLen);
    readAndFail(fileOut, tmp);
    if(sequenceLen != tmp) {
        cerr << "Numero panini non corrisponde\n";
        cout << 0.0f << endl;
        return 0;
    }
    //scarto primo dato dell'input (numero di panini dal menu)
    fileIn >> tmpIn;
    //setto old ad un numero ben piu' grande del peso massimo.
    old = ~0u;
    for(uint32_t i = 0; i < sequenceLen; ++i) {
        readAndFail(fileOut, tmp);
        if(tmp < old) {
            old = tmp;
        } else {
            cerr << "Sequenza errata: " << old << " <= " << tmp << endl;
            cout << 0.0f << endl;
            return 0;
        }
        do {
            readAndFail(fileIn, tmpIn, "Sequenza errata\n");
        } while(tmpIn != tmp);
    }

    //fin qui va tutto bene, controlliamo che non ci fossero ulteriori numeri nel suo file.
    fileOut >> tmp;

    if(fileOut.fail()) {
        //era davvero l'ultimo.
        cerr << "Corretto\n";
        cout << 1.0f << endl;
    }  else {
        cerr << "File malformattato\n";
        cout << 0.0f << endl;
    }
    return 0;
}