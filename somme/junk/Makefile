all: somme mangia greedy

	./genera-input.sh
	./genera-output.sh somme
	./genera-output.sh mangia
	./genera-output.sh greedy

somme: solutore.cpp
	g++ -o somme -O2 -pedantic -Wall solutore.cpp

mangia: solutore-mangia.cpp
	g++ -o mangia -O2 -pedantic -Wall solutore-mangia.cpp

greedy: solutore-greedy.cpp
	g++ -o greedy -O2 -pedantic -Wall solutore-greedy.cpp


# testo del problema
testo: 
	\mv somme.html somme-html.save
	xsltproc ../../../util/problem_layout.xslt somme.xml > somme.html

clean:
	rm -rf somme-html.save greedy mangia somme input/ output-{somme,mangia,greedy}/

