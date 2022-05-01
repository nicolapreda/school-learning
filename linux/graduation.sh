#!/bin/bash

# 1. get graduation of students in the file called as the first parameter
    cut -d ";" -f 4 $1 

echo ""

# 2. get graduation of students in the file called as the first parameter and in the subject called in second parameter
    grep $2 $1 | cut -d ";" -f 4 

echo ""

# 3. get the minimum graduation of the class in a subject
    grep $2 $1 | cut -d ";" -f 4 | sort -n | head -1

echo ""

# 4. get the average of the class in a subject
    count=0;
    total=0; 

    for i in $( grep $2 $1 | cut -d ";" -f 4 )
    do 
        total=$(echo $total+$i | bc )
        ((count++))
    done
    echo "scale=2; $total / $count" | bc

echo ""


# 5. get the minimum, maximum and average of the student in a subject
    # parameter 1: file name parameter 2: subject name   parameter 3: student name, get minimum of the student in the subject
    grep $2 $1 | grep $3 | cut -d ";" -f 4 | sort -n | head -1
    # parameter 1: file name parameter 2: subject name   parameter 3: student name, get maximum of the student in that subject
    grep $2 $1 | grep $3 | cut -d ";" -f 4 | sort -n | tail -1
    # parameter 1: file name parameter 2: subject name   parameter 3: student name, get average graduation of the student in that subject
    count=0;
    total=0; 

    for i in $( grep $2 $1 | grep $3 | cut -d ";" -f 4 )
    do 
        total=$(echo $total+$i | bc )
        ((count++))
    done
    echo "scale=2; $total / $count" | bc

echo ""

# 6. get names of best students in that subject in that test
    # parameter 1: file name parameter 2: subject name   parameter 3: date, get names of students that had more than 7 in that subject in that test
    for i in $( grep $2 $1 | grep $3 )
    do 
        if [ $(echo $i | cut -d ";" -f 4) -gt 7 ]
        then
            echo $(echo $i | cut -d ";" -f 3)
        fi
    done
    