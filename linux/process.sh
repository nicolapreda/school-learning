#!/bin/bash

#filter result with grep to take the first column
ps -e | grep $1 | cut -b -7 > result

#or use pidof function to automatically grab the pid
pidof $1 > result

# or filter result with awk to take the first column
awk '{print $1}'ps -e > result


