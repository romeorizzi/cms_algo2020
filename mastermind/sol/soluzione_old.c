#include "ourLibToPlay.h"

int g_code[4] = {0}; //Codice soluzione da sottomettere
int a_code[4] = {0}; //Codice soluzione temporaneo

void checkHistory(int attempt[], int result[], int history[]){

    result[0] = 0;
    result[1] = 0;
    int blacks[4] = {0};
    int whites[4] = {0};


    for(int i=0; i<4; i++)
    {
        if(attempt[i] == history[i])
            blacks[i]=1;
        else
            blacks[i]=0;
    }

    for(int i=0; i<4; i++)
    {
        if(blacks[i]!=1)
        {
            for(int f=0; f<4; f++)
            {
                if(f==i) continue;
                if((attempt[i] == history[f] && blacks[f] != 1))
                    if(whites[f] == 0)
                    {
                        whites[f]=1;
                        break;
                    }
            }
        }
    }

    for(int i=0; i<4; i++)
    {
        result[0] += blacks[i];
        result[1] += whites[i];
    }

}


int scoreCalculator(int black, int white){
    if(black == 0 && white == 0) return 0;
    if(black == 0 && white == 1) return 1;
    if(black == 1 && white == 0) return 2;
    if(black == 0 && white == 2) return 3;
    if(black == 1 && white == 1) return 4;
    if(black == 2 && white == 0) return 5;
    if(black == 0 && white == 3) return 6;
    if(black == 1 && white == 2) return 7;
    if(black == 2 && white == 1) return 8;
    if(black == 3 && white == 0) return 9;
    if(black == 0 && white == 4) return 10;
    if(black == 1 && white == 3) return 11;
    if(black == 2 && white == 2) return 12;
    if(black == 4 && white == 0) return 13;
}

void increase(int num[4]){
    num[3]++;
    if(num[3] == 6)
    {
        num[2]++;
        if(num[2] == 6)
        {
            num[1]++;
            if(num[1] == 6)
            {
                num[0]++;
                if(num[0]==6) num[0] = 0;
                num[1] = 0;
            }
            num[2] = 0;
        }
        num[3] = 0;
    }
}

void solve(){

    int guesses = 0;
    int result[] = {0, 0};

    g_code[0] = 0; g_code[1] = 0; g_code[2] = 1; g_code[3] = 1;
    a_code[0] = 0; a_code[1] = 0; a_code[2] = 1; a_code[3] = 1;
    int previous_answers[10][4];
    int previous_scores[10];
    while(result[0] != 4){
        guesses++;

        checkCode(g_code, result);
        int score = scoreCalculator(result[0],result[1]);

        previous_answers[guesses-1][0] = g_code[0];
        previous_answers[guesses-1][1] = g_code[1];
        previous_answers[guesses-1][2] = g_code[2];
        previous_answers[guesses-1][3] = g_code[3];

        previous_scores[guesses-1] = score;

        if(result[0] == 4)	break;

        int anySolutions = 1;

        while(anySolutions)
        {
            int consistent = 1;
            for(int i=0; i<guesses; i++)
            {
                checkHistory(a_code, result, previous_answers[i]);
                int test_score = scoreCalculator(result[0],result[1]);
                if(test_score != previous_scores[i]){
                    consistent = 0;
                    break;
                }
            }
            if(consistent)	break;
 			increase(a_code);
        }

        g_code[0] = a_code[0];
        g_code[1] = a_code[1];
        g_code[2] = a_code[2];
        g_code[3] = a_code[3];

    }

    pensoCheCodiceSia(g_code);

}
