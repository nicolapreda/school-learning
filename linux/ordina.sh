#!/bin/bash

sum=0
#check if the parameters are 5
if [ $# -ne 5 ]; then
    echo "Error: 5 parameters are required" >&2; exit 1
fi

#check if the parameters are numbers

for((i=1;i<=5;i++)); do
    if  [[ $i =~ [0-9] ]]; then
        (( sum += ${!i} ))
    else
        echo "Error in a parameter: Not a number">&2; exit 1
    fi
done   


echo $sum > risultato
