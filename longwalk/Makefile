all:  testo  output  cor/correttore 

Makefile:
	../../../../util/new/make_Makefile.py . > Makefile.tmp && mv Makefile.tmp Makefile

clean:
	rm -rf input output result input0.txt output0.txt
	find -iname '*.pyc' -print0 | xargs -0 rm -f
	find -iname '*.o' -print0 | xargs -0 rm -f
	rm -rf testo/testo.html testo/testo.pdf testo/testo.aux testo/testo.log
	rm -rf gen/gen_romeo sol/romeo sol/romeo_EVAL sol/romeo_stl sol/romeo_stl_EVAL sol/soluzione sol/soluzione_EVAL cor/correttore cor/cor


gen/gen_romeo: gen/gen_romeo.cpp
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o gen/gen_romeo gen/gen_romeo.cpp

sol/romeo: sol/romeo.cpp 
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o sol/romeo sol/romeo.cpp

sol/romeo_EVAL: sol/romeo.cpp 
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o sol/romeo_EVAL sol/romeo.cpp -DEVAL

sol/romeo_stl: sol/romeo_stl.cpp 
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o sol/romeo_stl sol/romeo_stl.cpp

sol/romeo_stl_EVAL: sol/romeo_stl.cpp 
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o sol/romeo_stl_EVAL sol/romeo_stl.cpp -DEVAL

sol/soluzione: sol/soluzione.cpp 
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o sol/soluzione sol/soluzione.cpp

sol/soluzione_EVAL: sol/soluzione.cpp 
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o sol/soluzione_EVAL sol/soluzione.cpp -DEVAL

cor/correttore: cor/correttore.cpp
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o cor/correttore cor/correttore.cpp

cor/cor: cor/cor.cpp
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o cor/cor cor/cor.cpp

testo: testo/testo.html testo/testo.pdf

testo/testo.html: testo/testo.xml
	xsltproc ../../../../util/new/xslt/problem_layout.xslt testo/testo.xml > testo/testo.html

testo/testo.pdf: testo/testo.tex
	TEXINPUTS=${TEXINPUTS}:.:testo:testo/file: pdflatex -output-directory testo -interaction batchmode testo.tex


#testo/testo.pdf: testo/testo.xml
#	xsltproc ../../../../util/new/xslt/problem_layout_tex.xslt testo/testo.xml > testo/testo.tex
#	TEXINPUTS=${TEXINPUTS}:.:testo:testo/file: pdflatex -output-directory testo -interaction batchmode testo.tex

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

test_romeo: ../../../../util/new/driver/mo-box sol/romeo_EVAL sol/romeo input output  cor/correttore
	../../../../util/new/test.py ../../../../util/new/driver/mo-box sol/romeo_EVAL 3 512 Batch Comp cor/correttore

test_romeo_stl: ../../../../util/new/driver/mo-box sol/romeo_stl_EVAL sol/romeo_stl input output  cor/correttore
	../../../../util/new/test.py ../../../../util/new/driver/mo-box sol/romeo_stl_EVAL 3 512 Batch Comp cor/correttore

test_soluzione: ../../../../util/new/driver/mo-box sol/soluzione_EVAL sol/soluzione input output  cor/correttore
	../../../../util/new/test.py ../../../../util/new/driver/mo-box sol/soluzione_EVAL 3 512 Batch Comp cor/correttore

test: ../../../../util/new/driver/mo-box sol/romeo_EVAL sol/romeo_stl_EVAL sol/soluzione_EVAL input output  cor/correttore
	../../../../util/new/test_all.py ../../../../util/new/driver/mo-box "sol/romeo_EVAL sol/romeo_stl_EVAL sol/soluzione_EVAL" 3 512 Batch Comp cor/correttore

.PHONY: all clean test_romeo test_romeo_stl test_soluzione test
