all:  testo  output 

Makefile:
	../../../../util/new/make_Makefile.py . > Makefile.tmp && mv Makefile.tmp Makefile

clean:
	rm -rf input output result input0.txt output0.txt
	find -iname '*.pyc' -print0 | xargs -0 rm -f
	find -iname '*.o' -print0 | xargs -0 rm -f
	rm -rf testo/testo.html testo/testo.pdf testo/testo.tex testo/testo.aux testo/testo.log
	rm -rf sol/sol sol/sol_EVAL sol/soluzione sol/soluzione_EVAL


sol/sol: sol/sol.cpp 
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o sol/sol sol/sol.cpp

sol/sol_EVAL: sol/sol.cpp 
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o sol/sol_EVAL sol/sol.cpp -DEVAL

sol/soluzione: sol/soluzione.cpp 
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o sol/soluzione sol/soluzione.cpp

sol/soluzione_EVAL: sol/soluzione.cpp 
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o sol/soluzione_EVAL sol/soluzione.cpp -DEVAL

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

test_sol.cpp: ../../../../util/new/driver/mo-box sol/sol.cpp_EVAL sol/sol.cpp input output
	../../../../util/new/test.py ../../../../util/new/driver/mo-box sol/sol.cpp_EVAL 3 512 Batch Diff

test_soluzione.cpp: ../../../../util/new/driver/mo-box sol/soluzione.cpp_EVAL sol/soluzione.cpp input output
	../../../../util/new/test.py ../../../../util/new/driver/mo-box sol/soluzione.cpp_EVAL 3 512 Batch Diff

test_sol: ../../../../util/new/driver/mo-box sol/sol_EVAL sol/sol input output
	../../../../util/new/test.py ../../../../util/new/driver/mo-box sol/sol_EVAL 3 512 Batch Diff

test_soluzione: ../../../../util/new/driver/mo-box sol/soluzione_EVAL sol/soluzione input output
	../../../../util/new/test.py ../../../../util/new/driver/mo-box sol/soluzione_EVAL 3 512 Batch Diff

test: ../../../../util/new/driver/mo-box sol/sol.cpp_EVAL sol/soluzione.cpp_EVAL sol/sol_EVAL sol/soluzione_EVAL input output
	../../../../util/new/test_all.py ../../../../util/new/driver/mo-box "sol/sol.cpp_EVAL sol/soluzione.cpp_EVAL sol/sol_EVAL sol/soluzione_EVAL" 3 512 Batch Diff

.PHONY: all clean test_sol.cpp test_soluzione.cpp test_sol test_soluzione test
