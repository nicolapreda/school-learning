#create a file for every student in files in "CLASSI" folder

cd ./CLASSI

for entry in `ls`; do
    while read p; do
    touch ../${entry}/${p// /_}
    done < ${entry}
done