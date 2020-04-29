#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N = 10000;
vector<int> X;

int main() {
#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d", &N);
    X.resize(1);

    for (int i = 0, x; i < N; i++) {
        cin >> x;
        bool to_insert = true;
        for (int j = 0; j < X.size() && to_insert; j++)
            if (x > X[j]) {
                X[j] = x;
                to_insert = false;
            }

        if (to_insert)
            X.resize(X.size() + 1, x);
    }
#ifndef EVAL
    copy(X.begin(), X.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
#endif
    cout << X.size() << endl;
    return 0;
}
