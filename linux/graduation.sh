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
#n=5;
#m=$n;
#while [ $m -gt 0 ]; do
#    num=${`grep $2 $1 | cut -d ";" -f 4``}
#    sum=`expr $sum + $num`
#
#    n=`expr $n - 1`
#done

#avg=`echo "$sum / $m" | bc -l`
#echo $avg

# 5. 
grep -w $2|$3 $1 | cut -d ";" -f 4 | sort -n | head -1
