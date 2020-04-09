all:  testo  output 

Makefile:
	../../../../util/new/make_Makefile.py . > Makefile

clean:
	rm -rf input output result input0.txt output0.txt
	rm -rf testo/testo.html testo/testo.pdf testo/testo.tex testo/testo.aux testo/testo.log sol/solutore-greedy sol/soluzione sol/solutore sol/solutore-mangia

sol/solutore-greedy: sol/solutore-greedy.cpp
	g++ -O2 -Wall -pedantic -static -o sol/solutore-greedy sol/solutore-greedy.cpp

sol/soluzione: sol/soluzione.cpp
	g++ -O2 -Wall -pedantic -static -o sol/soluzione sol/soluzione.cpp

sol/solutore: sol/solutore.cpp
	g++ -O2 -Wall -pedantic -static -o sol/solutore sol/solutore.cpp

sol/solutore-mangia: sol/solutore-mangia.cpp
	g++ -O2 -Wall -pedantic -static -o sol/solutore-mangia sol/solutore-mangia.cpp

testo: testo/testo.html testo/testo.pdf

testo/testo.html: testo/testo.xml
	xsltproc ../../../../util/new/xslt/problem_layout.xslt testo/testo.xml > testo/testo.html

testo/testo.pdf: testo/testo.xml
	xsltproc ../../../../util/new/xslt/problem_layout_tex.xslt testo/testo.xml > testo/testo.tex
	TEXINPUTS=${TEXINPUTS}:.:testo:testo/file: pdflatex -output-directory testo -interaction batchmode testo.tex

input: input0.txt gen/generatore.sh gen/GEN
	rm -rf input
	mkdir -p input
	../../../../util/new/genera_input.py gen/generatore.sh gen/GEN
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

test_solutore-greedy: ../../../../util/new/driver/driver input output sol/solutore-greedy
	../../../../util/new/test.py ../../../../util/new/driver/driver sol/solutore-greedy 1 

test_soluzione: ../../../../util/new/driver/driver input output sol/soluzione
	../../../../util/new/test.py ../../../../util/new/driver/driver sol/soluzione 1 

test_solutore: ../../../../util/new/driver/driver input output sol/solutore
	../../../../util/new/test.py ../../../../util/new/driver/driver sol/solutore 1 

test_solutore-mangia: ../../../../util/new/driver/driver input output sol/solutore-mangia
	../../../../util/new/test.py ../../../../util/new/driver/driver sol/solutore-mangia 1 

test: ../../../../util/new/driver/driver input output sol/solutore-greedy sol/soluzione sol/solutore sol/solutore-mangia
	../../../../util/new/test_all.py ../../../../util/new/driver/driver "sol/solutore-greedy sol/soluzione sol/solutore sol/solutore-mangia" 1 

.PHONY: all clean test_solutore-greedy test_soluzione test_solutore test_solutore-mangia test
