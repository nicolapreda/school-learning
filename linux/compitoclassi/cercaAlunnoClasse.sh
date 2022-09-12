#check if 3 parameters are passed
if [ $# -ne 3 ]
then
    echo "Usage: $0 <cognome alunno> <nome alunno> <classe>"
    exit 1
fi

#unisci nome e cognome
alunno="$1_$2"
#converti in maiuscolo
alunno=$(echo $alunno | tr '[:lower:]' '[:upper:]')

#check if $1 is in $2
if [ -f "./${3}/${alunno}" ]
then
    echo "Presente"
    exit 1
else
    echo "Assente"
    exit 1
fi