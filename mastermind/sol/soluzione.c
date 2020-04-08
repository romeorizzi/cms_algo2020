#include "ourLibToPlay.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

#define min(a, b) (((a) > (b)) ? (b) : (a))
#define max(a, b) (((a) < (b)) ? (b) : (a))

void check_code(int attempt[], int result[], int history[]) {
    int black = 0, white = 0;

    int fr_att[6] = {0};
    int fr_hist[6] = {0};

    for(int i = 0; i < 4; i++) {
        if(attempt[i] == history[i]) {
            black++;
        }
        else {
          assert(attempt[i] >= 0 && attempt[i] <= 5);
          assert(history[i] >= 0 && history[i] <= 5);
          fr_att[attempt[i]]++;
          fr_hist[history[i]]++;
        }
    }

    for(int i = 0; i < 6; i++) {
      white += min(fr_att[i], fr_hist[i]);
    }
    result[0] = black;
    result[1] = white;
}

int rank(int black, int white){
    return black * 4 + white;
}

void increase(int num[4]){
    for (int i = 3; i >= 0; i--) {
      num[i]++;
      if (num[i] == 6)
        num[i] = 0;
      else
        break;
    }
}

char is_invalid[6][6][6][6];
int is_valid(int code[]) {
    return !is_invalid[code[0]][code[1]][code[2]][code[3]];
}

void set_invalid(int code[]) {
    is_invalid[code[0]][code[1]][code[2]][code[3]] = 1;
}

int get_score(int code[]) {

    int p_code[4] = {0, 0, 0, 0};

    int results[17] = {0};

    do {
        if (is_valid(p_code)) {
            int result[2];
            check_code(p_code, result, code);
            results[rank(result[0], result[1])]++;
        }
        increase(p_code);
    }
    while (p_code[0] + p_code[1] + p_code[2] + p_code[3] != 0);

    int worst = 0;

    for (int i = 0; i < 17; i++) {
        if (results[i]) worst = max(results[i], worst);
    }
    return worst;
}

void print_guess(int g[4]) {
    printf("[%d %d %d %d]\n", g[0], g[1], g[2], g[3]);
}

void solve(){

    int g_code[4] = {0, 0, 1, 1}; //Codice soluzione da sottomettere

    int guesses = 0;
    int result[] = {0, 0};

    int previous_answers[10][4];
    int previous_rankings[10];

    for (;;) {
        guesses++;

        // print_guess(g_code);
        checkCode(g_code, result);
        int ranking = rank(result[0], result[1]);

        memcpy(previous_answers[guesses - 1], g_code, 4 * sizeof(g_code[0]));
        previous_rankings[guesses - 1] = ranking;

        if(result[0] == 4) break;

        int a_code[4] = {0, 0, 0, 0}; //Codice soluzione temporaneo

        do {
            if (is_valid(a_code)) {
                for(int i = 0; i < guesses; i++)
                {
                    check_code(a_code, result, previous_answers[i]);
                    int test_ranking = rank(result[0], result[1]);
                    if(test_ranking != previous_rankings[i]) {
                        set_invalid(a_code);
                        break;
                    }
                }
            }
 			increase(a_code);
        }
        while (a_code[0] + a_code[1] + a_code[2] + a_code[3] != 0);

        // int valid_cnt = 0;
        int best_score = 0x7fffffff;
        int b_code[4] = {0, 0, 0, 0};
        do {
            if (is_valid(a_code)) {
                // valid_cnt++;
                int score = get_score(a_code);
                if (best_score > score) {
                    best_score = score;
                    memcpy(b_code, a_code, 4 * sizeof(b_code[0]));
                }
            }
            increase(a_code);
        }
        while (a_code[0] + a_code[1] + a_code[2] + a_code[3] != 0);

        // printf("Codes left: %d\n", valid_cnt);
        // if(best_score == 0x7fffffff) {
        //     printf("Left:\n");
        //     do {
        //         if (is_valid(a_code)) {
        //             print_guess(a_code);
        //         }
        //         increase(a_code);
        //     }
        //     while (a_code[0] + a_code[1] + a_code[2] + a_code[3] != 0);
        //     assert(0);
        // }
        memcpy(g_code, b_code, 4 * sizeof(g_code[0]));
    }

    pensoCheCodiceSia(g_code);

}
