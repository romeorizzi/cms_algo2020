#include <iostream>
 
using namespace std;
 
string solve(int n, int m = 0, string r = "") {
 
    if (n == 0 && m == 0)
        return r + "\n";
 
    return (n > 0 ? solve(n - 1, m + 1, r + "I") : "") + (m > 0 ? solve(n, m - 1, r + "M") : "");
 
}
 
long cache[35][35] = {1};
 
long solveN(int n, int m = 0) {
    return cache[n][m] != 0 ? cache[n][m] :
            cache[n][m] = (n > 0 ? solveN(n - 1, m + 1) : 0) + (m > 0 ? solveN(n, m - 1) : 0);
}
 
int main() {
    int x;
    cin >> x;
    cout << solveN(x) << endl;
    cout << solve(x);
    return 0;
}
