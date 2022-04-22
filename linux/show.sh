

#!/bin/bash


contenuto=$(cat log)
if [[ contenuto == 0 ]]; then
        echo "devi effettuare prima il login!"
elif ! [[ -e log ]]; then
        echo "devi effettuare prima il login!"
else
        rm -f testo
        touch testo
        
        for (( i=$contenuto ; i<=0 ; i-- ))
        do
                echo $i > testo
                cat testo
        done

fi
