#!/bin/bash
somma=0

if [ -f somma ]; 
then
    rm -rf somma
fi


for i in {1..5}
do
    somma=$((somma + $i))

    
done

echo $somma >> somma