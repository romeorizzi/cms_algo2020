#!/bin/sh

#
# Genera gli output
#

if [ -z "$1" ]; then
    echo "Uso: $0 nome-solutore"
    echo "Specificare il nome della soluzione da provare"
    exit 1
fi

prog=$1

PATH=$PATH:./

mkdir output-$prog/
for((i=0;i<20;i++)); do
    echo "Generazione output $i per $prog"
    time $prog < input/input$i.txt > output-$prog/output$i.txt
done
