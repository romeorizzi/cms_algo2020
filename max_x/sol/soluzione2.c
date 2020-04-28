#include "ourLibToPlay.h"

void individua(long int n, long int maxLies) {

    int heaviest = 0;

    for (int i = 1; i < n; i++) {

        int res[2] = {0, 0};
        for (;;) {
            int new_vote = pesa(i, heaviest);
            if (new_vote < 0) new_vote = 0;
            if (++res[new_vote] >= (maxLies + 1)) break;
        }

        if (res[0] > res[1]) {
            maxLies -= res[1];
        }
        else {
            maxLies -= res[0];
            heaviest = i;
        }
    }

    pensoCheMaxSia(heaviest);
}
