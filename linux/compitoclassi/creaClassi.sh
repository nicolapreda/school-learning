#create a directory for every file in "CLASS" folder

cd ./CLASSI
for entry in `ls`; do
    mkdir -p "../${entry}"
done
