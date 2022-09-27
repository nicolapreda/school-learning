#check if there is an argument passed
if [ $# -eq 0 ]
then
echo "No arguments supplied"
exit 1
fi

#kill processes with a given name
ps -ef| grep $1 | grep -v grep | awk '{print $2}' | xargs kill -9

#xargs => esegue un altro comando specificandogli come parametri i dati letti dallo standard input
#grep -v "grep" takes input line by line, and outputs only the lines in which grep does not appear. Without -v, 
#it would output only the lines in which grep does appear