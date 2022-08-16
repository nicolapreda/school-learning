#check if 2 parameters are passed
if [ $# -ne 2 ]
then
    echo "Usage: $0 <alunno> <classe>"
    exit 1
fi

#check if $1 is in $2
if [ -f "./${2}/${1}" ]
then
    echo "Presente"
    exit 1
else
    echo "Assente"
    exit 1
fi

