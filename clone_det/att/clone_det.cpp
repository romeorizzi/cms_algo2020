#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long> A, B;

long solve() {
    return 0;
}

int main() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    B.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    cout << solve() << endl;
}
