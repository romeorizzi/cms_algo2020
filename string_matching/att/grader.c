#include <stdio.h>
#include <stdlib.h>
 
using namespace std;

int maxCompare;
int yourCompare;
char* text;

FILE *file;

extern void solve(char *pattern, int patt_len, int text_len);

int charCompare(char p, int pos_in_txt){	
	yourCompare++;
	return p == text[pos_in_txt];
}

void pensoCheMatchingSia(int risposta[], int risp_len){
	fprintf(file, "%d %d\n", maxCompare, yourCompare);
	for (int j = 0; j < risp_len; j++) {
			fprintf(file, "%d ", risposta[j]);
	}
	fprintf(file, "\n");
	fclose(file);

	exit(0);	
}
 
int main(){

	#ifdef EVAL
    file = fopen("input.txt", "r");
	#else
  	file = stdin;
	#endif

    int subtask, seed;

	fscanf(file, "%d", &subtask);
	fscanf(file, "%d", &seed);
    
	fclose(file);

	#ifdef EVAL
    file = fopen("output.txt", "w");
	#else 
    file = stdout;
	#endif

    srand(seed);

	int text_len = rand()%99991+10;
	text = (char*)malloc(sizeof(char)*text_len);
	
	for(int i = 0; i < text_len; i++){
		text[i] = rand()%26 + 'a';
	}
	
	int patt_len;
	do{
		patt_len = rand()%100+1;
	} while(patt_len > text_len);

	char *pattern = (char*)malloc(sizeof(char)*patt_len);
	
	for(int i = 0; i < patt_len; i++){
		pattern[i] = rand()%26 + 'a';
		//fprintf(stderr, "%c", pattern[i]);
	}
	//fprintf(stderr, "\n\n");
	
	int ins = rand()%(text_len/patt_len);
	
	int posCas = 0;
	for(int j = 0; j < ins; j++){
		posCas = rand()%(text_len-patt_len-1);
		for (int i = 0; i < patt_len; i++){
			text[i+posCas]=pattern[i];
		}
	}
	
	/*for(int i = 0; i < text_len; i++){
		fprintf(stderr, "%c", text[i]);
	}
	fprintf(stderr, "\n\n");*/

 	if(subtask == 0) maxCompare = (text_len - patt_len + 1)* patt_len;
	if(subtask == 1) maxCompare = 3*text_len;
	if(subtask == 2) maxCompare = 4.0/3.0*text_len; //soluzione ottima secondo algoritmo di Galil-Giancarlo

    yourCompare = 0;
    
	solve(pattern, patt_len, text_len);
	
    return 0;
}
