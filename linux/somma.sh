#!/bin/bash
#${!i} => Parametro all'interno della variabile con l'indice
sum=0
for((i=1;i<=5;i++)); do
    if  [[ $i =~ [0-9] ]]; then
        (( sum += $i ))
    else
        echo "Error in a parameter: Not a number">&2; exit 1
    fi
done   


echo $sum > somma
