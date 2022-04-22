#!/bin/bash

rm -f log

if ! [[ $# -eq 2 ]]; then
    echo "inserisci 2 parametri"
	rm -f log
else

if [[ (( $1 == "admin" )) && (( $2 == "amministratore" )) ]]; then
	touch log
	echo 1 > log

elif [[ (( $1 == "user" )) && (( $2 == "utente" )) ]]; then
        touch log
        echo 2 > log

elif [[ (( $1 == "guest" )) && (( $2 == "ospite" )) ]]; then
        touch log
        echo 3 > log

else
	touch log
	echo 0 > log
fi

cat log

fi
