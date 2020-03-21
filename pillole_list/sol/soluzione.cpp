/*
 *  Soluzione ufficiale di pillole_list
 *  tecnica: ricorsione
 *  ultima revisione: Alessandro Righi, 2020.03.21
 */

#include <cstdio>
#include <vector>
#include <string>

static std::vector<std::string> sol;

void
compute(int I, int M, std::string s)
{
    if (I == 0 && M == 0)
        sol.push_back(s);
    if (I > 0)
        compute(I - 1, M + 1, s + "I");
    if (M > 0)
        compute(I, M - 1, s + "M");
}

int
main()
{
    int N;
    scanf("%d", &N);

    compute(N, 0, "");

    printf("%zu\n", sol.size());
    for (std::string s : sol) {
        printf("%s\n", s.c_str());
    }
}
