#!/bin/sh

#
# Genera tutti gli input di somme
#

rm -rf input/
mkdir input

# input di test
cat > input/input0.txt <<EOF
6
11 -4 52 -7 -2 -20
EOF

# input dove il greedy dovrebbe andare
for((i=1;i<=5;i++)); do
    ./somme-gen-raddoppia.py $(( (i+1)*26 )) -25 25 1 > input/input$i.txt
done

# input difficili per il greedy (probabilmente)
for((i=6;i<20;i++)); do
    ./somme-gen02.py $(( (i+1)*25 )) 1 > input/input$i.txt
done
