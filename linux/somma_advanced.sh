#!/bin/bash

sum=0
for arg in "$@"; do
    if  [[ $arg =~ [0-9] ]]; then
        (( sum += arg ))
    else
        echo "Error in a parameter: Not a number">&2; exit 1
    fi
done   


echo $sum > somma
