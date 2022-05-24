#!/bin/bash
rm -f esito
touch esito

# if $1 is null
if [ -z "$1" ]
then
    echo "Specificare il codice del cliente"
else
    if grep -q $1 clienti
    then
        
        grep $1 clienti | cut -d "|" -f 2 >> esito
        
        # E => Extended Regular Expression
        grep -E '\|'$1'\|'  contatti >> esito

    else
        echo "Cliente non trovato"
    fi
fi

cat esito