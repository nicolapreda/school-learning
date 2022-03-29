#!/bin/bash

#check if the parameters are 5
if [ $# -ne 5 ]; then
    echo "Error: 5 parameters are required" >&2; exit 1
fi

#check if a file exists
if [ -f risultato ]; then
    rm -rf risultato
fi

for arg in "$@"; do
    if  [[ $arg =~ [0-9] ]]; then
        echo $arg >> risultato_temp
    else
        echo "Error in a parameter: Not a number">&2; exit 1
    fi
done   

#sort the input parameters
sort -g risultato_temp > risultato
rm -rf risultato_temp
