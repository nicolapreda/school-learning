#check if 2 parameters are passed
if [ $# -ne 2 ]
then
    echo "Usage: $0 <alunno> <classe>"
    exit 1
fi

#if folder $2 doesnt exist, exit
cd ./$2

for f in "./${2}"; do
    echo "$f"
done