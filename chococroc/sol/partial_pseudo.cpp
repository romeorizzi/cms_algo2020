#include <bits/stdc++.h>

using namespace std;

int win_from(int n, int m) {
	if (n < m) 
		swap(n, m);
   	return (n + 1) % (m + 1) != 0 || __builtin_popcount((n + 1) / (m + 1)) != 1;
}

int S;

int cut_direction(int n, int m) {
    for(int s = 1; s <= n/2; s++) {
        if(!win_from(n - s, m)) {
            S = s;
            return 0;
        }
    }
    for(int s = 1; s <= m/2; s++) {
        if(!win_from(n, m - s)) {
            S = s;
            return 1;
        }
    }
    return -1;
}

int eat_size(int n, int m) {
    return S;
}
