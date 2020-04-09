all:  testo  output  cor/correttore 

Makefile:
	../../../../util/new/make_Makefile.py . > Makefile

clean:
	rm -rf input output result input0.txt output0.txt
	find -iname '*.pyc' -print0 | xargs -0 rm -f
	rm -rf testo/testo.html testo/testo.pdf testo/testo.tex testo/testo.aux testo/testo.log sol/sol_stefano_sbagliata sol/sol_stefano_sbagliata_ma_furba sol/sol_alessio sol/soluzione sol/sol_stefano_lenta cor/correttore cor/cor

sol/sol_stefano_sbagliata: sol/sol_stefano_sbagliata.cpp
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o sol/sol_stefano_sbagliata sol/sol_stefano_sbagliata.cpp

sol/sol_stefano_sbagliata_ma_furba: sol/sol_stefano_sbagliata_ma_furba.cpp
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o sol/sol_stefano_sbagliata_ma_furba sol/sol_stefano_sbagliata_ma_furba.cpp

sol/sol_alessio: sol/sol_alessio.cpp
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o sol/sol_alessio sol/sol_alessio.cpp

sol/soluzione: sol/soluzione.cpp
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o sol/soluzione sol/soluzione.cpp

sol/sol_stefano_lenta: sol/sol_stefano_lenta.cpp
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o sol/sol_stefano_lenta sol/sol_stefano_lenta.cpp

cor/correttore: cor/correttore.cpp
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o cor/correttore cor/correttore.cpp

cor/cor: cor/cor.cpp
	g++ -march=i686 -m32 -O2 -Wall -pedantic -static -o cor/cor cor/cor.cpp

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

test_sol_stefano_sbagliata: ../../../../util/new/driver/driver input output sol/sol_stefano_sbagliata  cor/correttore
	../../../../util/new/test.py ../../../../util/new/driver/driver sol/sol_stefano_sbagliata 5   cor/correttore

test_sol_stefano_sbagliata_ma_furba: ../../../../util/new/driver/driver input output sol/sol_stefano_sbagliata_ma_furba  cor/correttore
	../../../../util/new/test.py ../../../../util/new/driver/driver sol/sol_stefano_sbagliata_ma_furba 5   cor/correttore

test_sol_alessio: ../../../../util/new/driver/driver input output sol/sol_alessio  cor/correttore
	../../../../util/new/test.py ../../../../util/new/driver/driver sol/sol_alessio 5   cor/correttore

test_soluzione: ../../../../util/new/driver/driver input output sol/soluzione  cor/correttore
	../../../../util/new/test.py ../../../../util/new/driver/driver sol/soluzione 5   cor/correttore

test_sol_stefano_lenta: ../../../../util/new/driver/driver input output sol/sol_stefano_lenta  cor/correttore
	../../../../util/new/test.py ../../../../util/new/driver/driver sol/sol_stefano_lenta 5   cor/correttore

test: ../../../../util/new/driver/driver input output sol/sol_stefano_sbagliata sol/sol_stefano_sbagliata_ma_furba sol/sol_alessio sol/soluzione sol/sol_stefano_lenta  cor/correttore
	../../../../util/new/test_all.py ../../../../util/new/driver/driver "sol/sol_stefano_sbagliata sol/sol_stefano_sbagliata_ma_furba sol/sol_alessio sol/soluzione sol/sol_stefano_lenta" 5   cor/correttore

.PHONY: all clean test_sol_stefano_sbagliata test_sol_stefano_sbagliata_ma_furba test_sol_alessio test_soluzione test_sol_stefano_lenta test
