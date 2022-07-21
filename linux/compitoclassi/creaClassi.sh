#create a directory for every class in "CLASSI" folder
cd "$(dirname "${BASH_SOURCE[0]}")/.."
for i in CLASSI/*; do
    if [ -d "$i" ]; then
        if [ ! -d "$i/class" ]; then
            mkdir "$i/class"
        fi
    fi
done
