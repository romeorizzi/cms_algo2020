#include <bits/stdc++.h>

using namespace std;

int move(int row, int col) {
    if (col < row) swap(col, row);
    while (row < (col+1)/2)
        row = row * 2 + 1;
    return col - row;
}

int win_from(int n, int m) {
    return move(n, m) > 0;
}

int cut_direction(int n, int m) {
    return (n < m) ? 1 : 0;
}

int eat_size(int n, int m) {
    return move(n, m);
}
