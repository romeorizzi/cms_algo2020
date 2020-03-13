#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> X;
int N;

long solve()
{
    // TODO: write solution
    return 0;
}

int main()
{
    scanf("%d", &N);
    X.resize(N);
    for (int i = 0; i < N; i++) {
        scanf("%ld", &X[i]);
    }

    printf("%ld\n", solve());
}
