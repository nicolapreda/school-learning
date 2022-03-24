
#!/bin/bash
for ((i=1; i<=5; i++))
do
    read num
    if  [[ $num =~ [0-9] ]]; then
            sum=$((somma + num))
    fi
done
echo $sum > somma
