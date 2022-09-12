#restituisce la classe dello studente passato come argomento (esempio ./cercaAlunno.sh Piffari Matteo) se presente
#altrimenti restituisce "Assente"


#check if 2 parameters are passed
if [ $# -ne 2 ]
then
    echo "Usage: $0 <cognome alunno> <nome alunno>"
    exit 1
fi

#unisci nome e cognome
alunno="$1_$2"
#converti in maiuscolo
alunno=$(echo $alunno | tr '[:lower:]' '[:upper:]')

#check if alunno is in class folders
for classe in $(ls -d */)
do
    if [ -f "./${classe}/${alunno}" ]
    then
        echo "Presente in ${classe}"
        exit 1
    fi
done