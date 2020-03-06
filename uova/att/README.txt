Supponiamo che lavori ad una soluzione scritta in c++ (file con estensione .cpp).

Come vedi alla pagina del problema,
quando la sottometterai al server, per poterla valutare sulle istanze di test egli la compilerà prima con:

/usr/bin/g++ -DEVAL -std=gnu++11 -O2 -pipe -static -s -o ric_bin grader.cpp ric_bin.cpp

E' in generale buona idea cercare di attenersi aparametri di compilazione compatibili, ma potrai ovviamente variarli come più utile ai tuoi esperimenti.
Ad esempio, compilandola con:

g++ -std=gnu++11 -O2 -pipe -static -s -o ric_bin grader.cpp ric_bin.cpp

poi potrai testarla su diversi file di input di prova che ti puoi essere preparato in locale. Ad esempio, puoi ora testarla agevolmente con entrambi gli input di prova resi disponibili in attachment alla pagina del problema.

Ad esempio, da terminale puoi facilmente sfruttare la redirezione dell'input lanciando:

romeo@romeo-HP-ProBook-450-G4:~/2020/ric_bin/att$ ./ric_bin < input1.txt 

ottenendo in risposta:
0

oppure:

romeo@romeo-HP-ProBook-450-G4:~/2020/ric_bin/att$ ./ric_bin < input2.txt 

ottenendo in risposta:
1




