#include <cstdio>
#include <vector>

using namespace std;

int N;
vector<long> A, B;

long solve() {
    int i = N - 1;
    int j = N - 1;
    while (true) {
        if (A[i] == B[j])
            return A[i];
        if (A[i] < B[j])
            j--;
        else
            i--;
    }
}

int main() {
    scanf("%d", &N);

    A.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%ld", &A[i]);
    }

    B.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%ld", &B[i]);
    }

    printf("%ld\n", solve());
}
