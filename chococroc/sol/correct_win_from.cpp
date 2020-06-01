#include <bits/stdc++.h>

using namespace std;

int win_from(int n, int m) {
	if (n < m) 
		swap(n, m);
   	return (n + 1) % (m + 1) != 0 || __builtin_popcount((n + 1) / (m + 1)) != 1;
}

int cut_direction(int n, int m) {
    // TODO
    return 42;
}

int eat_size(int n, int m) {
    // TODO
    return 42;
}
