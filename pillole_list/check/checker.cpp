#include <stdio.h>
#include <assert.h>
#include <stdarg.h>

#include <set>
#include <string>

void
ex(double res, const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    assert(0.0 <= res && res <= 1.0);

    vfprintf(stderr, fmt, args);
    printf("%lf\n", res);
    exit(0);
}

int
main(int argc, char *argv[])
{
    FILE *in, *cor, *out;
    int N, i, j, correct_S, solution_S, I, M;
    char line[1024];
    std::set<std::string> values;

    assert(argc == 4);
    assert(in = fopen(argv[1], "r"));
    assert(cor = fopen(argv[2], "r"));
    assert(out = fopen(argv[3], "r"));

    assert(fscanf(in, "%d", &N) == 1);
    assert(fscanf(cor, "%d", &correct_S) == 1);

    if (fgets(line, sizeof(line), out) == NULL)
        ex(0.0, "Errore di lettura della riga %d: probabile fine prematura del file", i);

    if (sscanf(line, "%d", &solution_S) != 1)
        ex(0.0, "Errore parsing del file soluzione alla riga 1: atteso un intero");

    if (correct_S != solution_S)
        ex(0.0, "Numero di soluzioni errato: atteso %d, ottenuto %d", correct_S, solution_S);

    for (i = 1; i <= correct_S; i++) {
        if (fgets(line, sizeof(line), out) == NULL)
            ex(0.0, "Errore di lettura della riga %d: probabile fine prematura del file", i);

        I = N;
        M = 0;
        for (j = 0; j < N * 2; j++) {
            switch (line[j]) {
            case 'I':
                if (I <= 0)
                    ex(0.0, "Riga %d carattere %d: tentativo di rimuovere pillola intera quando queste sono zero", i, j);
                I--;
                M++;
                break;
            case 'M':
                if (M <= 0)
                    ex(0.0, "Riga %d carattere %d: tentativo di rimuovere una pillola mezza quando queste sono zero", i, j);
                M--;
                break;
            default:
                ex(0.0, "Carattere '%c' non valido alla riga %d carattere %d: possibile fine prematura della riga", line[j], i, j);
            }
        }

        if (M != 0 || I != 0)
            ex(0.0, "Non hai consumato tutte le pillole alla riga %d", i);

        if (!values.insert(std::string(line)).second)
            ex(0.0, "Riga %d ripetuta", i);
    }

    ex(1.0, "Corretto");
}
