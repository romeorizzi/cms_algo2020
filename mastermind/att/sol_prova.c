#include "ourLibToPlay.h"

void solve(){
	int sol[4] = {1, 4, 5, 0};
	int res[2];
	checkCode(sol, res);
	if(res[0]==4){
		pensoCheCodiceSia(sol);	
	} else {
		sol[0] = 1; sol[1] = 2; sol[2] = 3; sol[3] = 4;	
		pensoCheCodiceSia(sol);	
	}
}
