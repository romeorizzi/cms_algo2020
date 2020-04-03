#include <stdio.h>
#include <time.h>
#include <assert.h>
#define MN 1000010

int   *pre,  *post ;
int  rPre[MN], rPost[MN] ;
int     L[MN],     R[MN] ;
int out[MN], idx ;
char         visited[MN] ;
int NN ;

void simmetrica( int n )
{
	if( L[n] != 0 ) simmetrica( L[n] );
	out[idx++] = n ;
	if( R[n] != 0 ) simmetrica( R[n] );	
}

void costruisci( int pos )
{
	int l = pre[pos] ;
	int idxl = pos+1 ;
	int idxr = rPost[l]-1 ;	
	visited[l] = 1 ;
	if(          idxl >= NN || idxr < 0            ) return ;
	if( visited[pre[idxl]] || visited[post[idxr]] ) return ;
	L[l] =  pre[idxl] ;
	R[l] = post[idxr] ;	
	costruisci( idxl );
	costruisci( rPre[post[idxr]] );	
}

void visita(int N, int *PRE, int *POST, int *SIMM )
{
	NN = N ; pre = PRE ; post = POST ;
	for( int i = 0 ; i < N ; i++ ) rPost[POST[i]] = rPre[ PRE[i]] = i ;	
	costruisci(     0  );
	simmetrica( pre[0] );
	for( int i = 0 ; i < N ; i++ ) SIMM[i] = out[i] ;
}


