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

int main(int argc, char** argv) {
    ifstream in(argv[1]);

    if(in.fail()) {
        return 1;
    }
    cin.rdbuf(in.rdbuf());

    int bobActions, treeSize;

    cin >> treeSize;
    if(cin.fail() || treeSize > 100000 || treeSize < 0) return 2;
    cin >> bobActions;
    if(cin.fail() || bobActions > treeSize || bobActions < 0) return 3;
    //L'albero e' fatto da $treeSize nodi.
    auto tree = vector<shared_ptr<NODE>>();
    for(int i = 0; i <= treeSize; i++) {
        tree.push_back(make_shared<NODE>());
    }
    int tmp;
    for(int i = 2; i <= treeSize; i++) {
        cin >> tmp;
        if(cin.fail() || tmp > treeSize || tmp < 1) return 4;
        //il nodo iesimo ha come padre il nodo tmp;
        tree[i]->father = tree[tmp];
        //ovviamente quindi anche il nodo tmp avra' come figlio il nodo iesimo.
        tree[tmp]->figli.push_back(tree[i]);
    }
    for(int i = 2; i <= treeSize; i++) {
        if(tree[i]->father == NULL) {
            return 5;
        }
        if(tree[i] == tree[i] -> father) {
            return 6;
        }
    }
    return 0;
}