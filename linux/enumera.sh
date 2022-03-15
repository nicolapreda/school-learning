rm -f numeri
if (( $2 <= 0 )) && (($1 < 0)); then
  echo "Valore 1 e 2 non validi"
elif (( $2 <= 0 )) ; then
  echo "Valore 2 non valido"
elif (($1 < 0)); then
  echo "Valore 1 non valido" 
else
for((i = 0; i <= $1; i += $2)); do
    echo $i >> numeri
done
fi
