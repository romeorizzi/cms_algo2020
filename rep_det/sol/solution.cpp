#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

vector<long> X;
int N;

unordered_set<long> found;

long solve()
{
    long result = 0x7FFFFFFFFFFFFFFF;
    for (long x : X) {
        if (found.count(x)) {
            result = min(result, x);
        }
        found.insert(x);
    }

    return result < 0x7FFFFFFFFFFFFFFF ? result : 0;
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