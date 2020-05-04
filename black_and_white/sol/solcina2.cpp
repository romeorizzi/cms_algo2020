/* FONTE: https://blog.csdn.net/surfacedust/article/details/6669230
RIADATTATA PER PRENDERE IN INPUT FILE E SOLO UN TESTCASE*/

#include<string.h>
#include<stdlib.h>
#include<fstream>
#include<iostream>
#define N 100010
#define MID(x,y) ((x+y)>>1)
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a>b?b:a)
#define swap(a,b) (a^=b,b^=a,a^=b)
using namespace std;
struct node{
	
	int l,r;
	int sum;			//黑子连续和
	int w_sum;			//白子连续和
	int l_sum,r_sum;	//左黑连续长度， 右黑连续长度
	int wl_sum,wr_sum;	//左白连续长度， 右白连续长度
	int flag;			//标记
	
}seg_tree[N<<2];
int s[N],ans;
 
void Swap(int t){
	
	swap(seg_tree[t].l_sum,seg_tree[t].wl_sum);
	swap(seg_tree[t].r_sum,seg_tree[t].wr_sum);
	swap(seg_tree[t].sum,seg_tree[t].w_sum);
	
}
void updata(int t){
	
	//黑子
	seg_tree[t].sum = Max(seg_tree[L(t)].r_sum + seg_tree[R(t)].l_sum ,Max(seg_tree[L(t)].sum,seg_tree[R(t)].sum));
	seg_tree[t].l_sum = seg_tree[L(t)].l_sum;
	if(seg_tree[L(t)].l_sum == seg_tree[L(t)].r-seg_tree[L(t)].l)
		seg_tree[t].l_sum += seg_tree[R(t)].l_sum;
	seg_tree[t].r_sum = seg_tree[R(t)].r_sum;	
	if(seg_tree[R(t)].r_sum == seg_tree[R(t)].r-seg_tree[R(t)].l)
		seg_tree[t].r_sum += seg_tree[L(t)].r_sum;
	
	//白子
	seg_tree[t].w_sum = Max(seg_tree[L(t)].wr_sum + seg_tree[R(t)].wl_sum ,Max(seg_tree[L(t)].w_sum,seg_tree[R(t)].w_sum));
	seg_tree[t].wl_sum = seg_tree[L(t)].wl_sum;
	if(seg_tree[L(t)].wl_sum == seg_tree[L(t)].r-seg_tree[L(t)].l)
		seg_tree[t].wl_sum += seg_tree[R(t)].wl_sum;
	seg_tree[t].wr_sum = seg_tree[R(t)].wr_sum;
	if(seg_tree[R(t)].wr_sum == seg_tree[R(t)].r-seg_tree[R(t)].l)
		seg_tree[t].wr_sum += seg_tree[L(t)].wr_sum;
	
}
void build(int t,int l,int r)
{
	int mid = MID(l,r);
	seg_tree[t].l = l;
	seg_tree[t].r = r;
	if(r-l == 1){
		if(s[l] == 0){
			seg_tree[t].sum=0;
			seg_tree[t].l_sum=0;
			seg_tree[t].r_sum=0;
			
			seg_tree[t].w_sum=1;
			seg_tree[t].wl_sum=1;
			seg_tree[t].wr_sum=1;
			
		}
		else {
			seg_tree[t].sum=1;
			seg_tree[t].l_sum=1;
			seg_tree[t].r_sum=1;
			
			seg_tree[t].w_sum=0;
			seg_tree[t].wl_sum=0;
			seg_tree[t].wr_sum=0;
		}
		return ;
	}
	build(L(t),l,mid);
	build(R(t),mid,r);
	updata(t);
}
void insert(int t, int l, int r){
	
	//printf("<t-%d,%d,%d>\n",t,seg_tree[t].l,seg_tree[t].r);
	//printf("<l-%d   r-%d>\n",l,r);
	
	int mid = MID(seg_tree[t].l,seg_tree[t].r);
	
	if(l == seg_tree[t].l && seg_tree[t].r == r){
		Swap(t);
		seg_tree[t].flag ^=1;
		return ;
	}
	if(seg_tree[t].flag == 1){
		seg_tree[t].flag = 0;
		Swap(L(t));
		seg_tree[L(t)].flag ^=1;
		Swap(R(t));
		seg_tree[R(t)].flag ^=1;
	}
	if(mid >= r)
		insert(L(t),l,r);
	
	else if( mid <= l ) insert(R(t),l,r);
	else {
		
		insert(L(t),l,mid);
		
		insert(R(t),mid,r);
		
	}
	updata(t);
}
int search(int t,int l,int r)
{
	int mid = MID(seg_tree[t].l,seg_tree[t].r);
	int ll,rr,res_l,res_r;
	if(seg_tree[t].l == l && seg_tree[t].r == r){
		return seg_tree[t].sum;
	}
	if(seg_tree[t].flag == 1){
		
		seg_tree[t].flag = 0;
		
		Swap(L(t));
		
		seg_tree[L(t)].flag ^=1;
		
		Swap(R(t));
		
		seg_tree[R(t)].flag ^=1;
		//updata(t);
	}
	if(r <= mid)return search(L(t),l,r);
	
	else if( l >= mid)return search(R(t),l,r);
	
	else {
		
		res_l = search(L(t),l,mid);
		res_r = search(R(t),mid,r);
		ll = seg_tree[L(t)].r_sum;
		rr = seg_tree[R(t)].l_sum;
		ll = Min(ll,mid-l);
		//printf("<%d>\n",ll);
		rr = Min(rr,r-mid);
		//printf("<%d>\n",rr);
		return Max(ll+rr,Max(res_l,res_r));
		
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

	int n,i,m,x,j;
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> s[i];
	build(1,1,n+1);
	cin >> m;
	while(m--){
		
		cin >> x >> i >> j;
		
		if(x==0){
			ans = search(1,i,j+1);
			cout << ans << endl;
		}
		else insert(1,i,j+1);
	}
	return 0;
}
/*
5
0 1 1 1 0
5
1 3 3
0 1 5
1 1 5
0 1 5
*/
