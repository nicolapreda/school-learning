#!/bin/bash

rm -f esito
touch esito


if(( $# < 2 ))
then
    echo "Numero di parametri errato"
else
    echo -n "Cliente: " >> esito
    grep $1 clienti | cut -d "|" -f 2 >> esito
    echo -n "Contatto: "
    grep $1 contatti | grep $2 contatti | cut -d "|" -f 3 >> esito
    grep -E '\|'$2'\|' telefonate | awk -F '|' '{print $3, $4}' >> esito 

    gEsito=$(stat --format=%s "./esito")   
    if(($gEsito == 0))
    then
        echo "Nessun contatto trovato"
    fi
fi

cat esito