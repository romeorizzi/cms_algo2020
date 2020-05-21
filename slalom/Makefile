all:  testo  output  cor/correttore 

Makefile:
	../../../../util/new/make_Makefile.py . > Makefile.tmp && mv Makefile.tmp Makefile

clean:
	rm -rf input output result input0.txt output0.txt
	find -iname '*.pyc' -print0 | xargs -0 rm -f
	find -iname '*.o' -print0 | xargs -0 rm -f
	rm -rf testo/testo.html testo/testo.pdf testo/testo.tex testo/testo.aux testo/testo.log
	rm -rf gen/generatore sol/solutore sol/solutore_EVAL sol/soluzione sol/soluzione_EVAL sol/solutore2 sol/solutore2_EVAL cor/correttore2 cor/correttore


gen/generatore: gen/generatore.c
	gcc -march=i686 -m32 -O2 -lm -Wall -pedantic -static -o gen/generatore gen/generatore.c

sol/solutore: sol/solutore.c 
	gcc -march=i686 -m32 -O2 -lm -Wall -pedantic -static -o sol/solutore sol/solutore.c

sol/solutore_EVAL: sol/solutore.c 
	gcc -march=i686 -m32 -O2 -lm -Wall -pedantic -static -o sol/solutore_EVAL sol/solutore.c -DEVAL

sol/soluzione: sol/soluzione.c 
	gcc -march=i686 -m32 -O2 -lm -Wall -pedantic -static -o sol/soluzione sol/soluzione.c

sol/soluzione_EVAL: sol/soluzione.c 
	gcc -march=i686 -m32 -O2 -lm -Wall -pedantic -static -o sol/soluzione_EVAL sol/soluzione.c -DEVAL

sol/solutore2: sol/solutore2.c 
	gcc -march=i686 -m32 -O2 -lm -Wall -pedantic -static -o sol/solutore2 sol/solutore2.c

sol/solutore2_EVAL: sol/solutore2.c 
	gcc -march=i686 -m32 -O2 -lm -Wall -pedantic -static -o sol/solutore2_EVAL sol/solutore2.c -DEVAL

cor/correttore2: cor/correttore2.cpp
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o cor/correttore2 cor/correttore2.cpp

cor/correttore: cor/correttore.c
	gcc -march=i686 -m32 -O2 -lm -Wall -pedantic -static -o cor/correttore cor/correttore.c

testo: testo/testo.html testo/testo.pdf

testo/testo.html: testo/testo.xml
	xsltproc ../../../../util/new/xslt/problem_layout.xslt testo/testo.xml > testo/testo.html

testo/testo.pdf: testo/testo.xml
	xsltproc ../../../../util/new/xslt/problem_layout_tex.xslt testo/testo.xml > testo/testo.tex
	TEXINPUTS=${TEXINPUTS}:.:testo:testo/file: pdflatex -output-directory testo -interaction batchmode testo.tex

input: input0.txt gen/generatore.py gen/GEN
	rm -rf input
	mkdir -p input
	../../../../util/new/genera_input.py gen/generatore.py gen/GEN
	../../../../util/new/valida_input.py gen/valida.py gen/GEN
	touch input

output: output0.txt input sol/soluzione gen/GEN
	rm -rf output
	mkdir -p output
	../../../../util/new/genera_output.py sol/soluzione gen/GEN
	touch output

output0.txt: testo/testo.xml
	xsltproc ../../../../util/new/xslt/estrai_output.xslt testo/testo.xml | grep -vE '^\s*$$' > output0.txt

input0.txt: testo/testo.xml
	xsltproc ../../../../util/new/xslt/estrai_input.xslt testo/testo.xml | grep -vE '^\s*$$' > input0.txt

test_solutore: ../../../../util/new/driver/mo-box sol/solutore_EVAL sol/solutore input output  cor/correttore
	../../../../util/new/test.py ../../../../util/new/driver/mo-box sol/solutore_EVAL 1 512 Batch Comp cor/correttore

test_soluzione: ../../../../util/new/driver/mo-box sol/soluzione_EVAL sol/soluzione input output  cor/correttore
	../../../../util/new/test.py ../../../../util/new/driver/mo-box sol/soluzione_EVAL 1 512 Batch Comp cor/correttore

test_solutore2: ../../../../util/new/driver/mo-box sol/solutore2_EVAL sol/solutore2 input output  cor/correttore
	../../../../util/new/test.py ../../../../util/new/driver/mo-box sol/solutore2_EVAL 1 512 Batch Comp cor/correttore

test: ../../../../util/new/driver/mo-box sol/solutore_EVAL sol/soluzione_EVAL sol/solutore2_EVAL input output  cor/correttore
	../../../../util/new/test_all.py ../../../../util/new/driver/mo-box "sol/solutore_EVAL sol/soluzione_EVAL sol/solutore2_EVAL" 1 512 Batch Comp cor/correttore

.PHONY: all clean test_solutore test_soluzione test_solutore2 test
