/* FONTE: https://www.cnblogs.com/Recoder/p/5534421.html 
RIADATTATA PER PRENDERE IN INPUT FILE E SOLO UN TESTCASE*/
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int MAXN = 1e5 + 5;
struct SegTree {
    int l , r , lazy;
    int lsum1 , rsum1 , sum1;
    int lsum0 , rsum0 , sum0;
}T[MAXN << 2];
int a[MAXN];

void Pushdown(int p) {
    if(T[p].lazy) {
        int ls = p << 1 , rs = (p << 1)|1;
        T[ls].lazy ^= T[p].lazy;
        T[rs].lazy ^= T[p].lazy;
        int temp = T[ls].lsum1;
        T[ls].lsum1 = T[ls].lsum0;
        T[ls].lsum0 = temp;
        temp = T[ls].rsum1;
        T[ls].rsum1 = T[ls].rsum0;
        T[ls].rsum0 = temp;
        temp = T[ls].sum1;
        T[ls].sum1 = T[ls].sum0;
        T[ls].sum0 = temp;

        temp = T[rs].lsum1;
        T[rs].lsum1 = T[rs].lsum0;
        T[rs].lsum0 = temp;
        temp = T[rs].rsum1;
        T[rs].rsum1 = T[rs].rsum0;
        T[rs].rsum0 = temp;
        temp = T[rs].sum1;
        T[rs].sum1 = T[rs].sum0;
        T[rs].sum0 = temp;

        T[p].lazy = 0;
    }
}

void Pushup(int p) {
    T[p].lsum1 = T[p << 1].lsum1 , T[p].lsum0 = T[p << 1].lsum0;
    T[p].rsum1 = T[(p << 1)|1].rsum1 , T[p].rsum0 = T[(p << 1)|1].rsum0;
    if(T[p].lsum1 == T[p << 1].r - T[p << 1].l + 1)
        T[p].lsum1 += T[(p << 1)|1].lsum1;
    if(T[p].rsum1 == T[(p << 1)|1].r - T[(p << 1)|1].l + 1)
        T[p].rsum1 += T[p << 1].rsum1;
    if(T[p].lsum0 == T[p << 1].r - T[p << 1].l + 1)
        T[p].lsum0 += T[(p << 1)|1].lsum0;
    if(T[p].rsum0 == T[(p << 1)|1].r - T[(p << 1)|1].l + 1)
        T[p].rsum0 += T[p << 1].rsum0;
    T[p].sum1 = max(T[p << 1].sum1 , max(T[(p << 1)|1].sum1 , T[p << 1].rsum1 + T[(p << 1)|1].lsum1));
    T[p].sum0 = max(T[p << 1].sum0 , max(T[(p << 1)|1].sum0 , T[p << 1].rsum0 + T[(p << 1)|1].lsum0));
}

void build(int p , int l , int r) {
    int mid = (l + r) >> 1;
    T[p].lazy = 0;
    T[p].l = l , T[p].r = r;
    if(l == r) {
        cin >> a[l];
        T[p].sum1 = T[p].lsum1 = T[p].rsum1 = a[l] ? 1 : 0;
        T[p].sum0 = T[p].lsum0 = T[p].rsum0 = a[l] ? 0 : 1;
        return ;
    }
    build(p << 1 , l , mid);
    build((p << 1)|1 , mid + 1 , r);
    Pushup(p);
}

void updata(int p , int l , int r , int flag) {
    int mid = (T[p].l + T[p].r) >> 1;
    if(T[p].l == l && T[p].r == r) {
        T[p].lazy ^= flag;
        int temp = T[p].lsum1;
        T[p].lsum1 = T[p].lsum0;
        T[p].lsum0 = temp;
        temp = T[p].rsum1;
        T[p].rsum1 = T[p].rsum0;
        T[p].rsum0 = temp;
        temp = T[p].sum1;
        T[p].sum1 = T[p].sum0;
        T[p].sum0 = temp;
        return ;
    }
    Pushdown(p);
    if(r <= mid) {
        updata(p << 1 , l , r , flag);
    }
    else if(l > mid) {
        updata((p << 1)|1 , l , r , flag);
    }
    else {
        updata(p << 1 , l , mid , flag);
        updata((p << 1)|1 , mid + 1 , r , flag);
    }
    Pushup(p);
}

int query(int p , int l , int r) {
    int mid = (T[p].l + T[p].r) >> 1;
    if(T[p].l == l && T[p].r == r) {
        return T[p].sum1;
    }
    Pushdown(p);
    if(r <= mid) {
        return query(p << 1 , l , r);
    }
    else if(l > mid) {
        return query((p << 1)|1 , l , r);
    }
    else {
        return max( min(T[p << 1].rsum1 , mid - l + 1)+min(T[(p << 1)|1].lsum1 , r - mid) , //mid在l和r之间
         max( query(p << 1 , l , mid) , query((p << 1)|1 , mid + 1 , r)) );
    }
}

int main()
{
	ifstream fileIn;
    fileIn.open("input.txt");
    ofstream fileOut;
    fileOut.open("output.txt");

    if(!fileIn.is_open() || !fileOut.is_open()) return -1;

    cin.rdbuf(fileIn.rdbuf());
    cout.rdbuf(fileOut.rdbuf());

    int n, m, action, i, j;

    cin >> n;


    build(1 , 1 , n);

    cin >> m;
    for(int index = 0; index  < m; ++index) {
        cin >> action >> i >> j;
        if(action == 0) {
            cout << query(1 , i , j) << endl;
        } else {
            updata(1 , i , j , 1);
        }
    }

    return 0;
}