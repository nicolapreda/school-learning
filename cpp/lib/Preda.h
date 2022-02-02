#include <iostream>
using namespace std;

//Dichiarazione funzioni
int maxArray(int array, int n);
int minArray(int array, int n);
int sommaArray(int array, int n);
double mediaArray(int array, int n);
int maxOccorrenza(int array, int n);


maxArray(int array, int n){
    int maxelement = 0;
    for(int i = 0; i < n; i++){
        if(array[i] > maxelement)
            maxelement = array[i];
    }
    return maxelement;
}

minArray(int array, int n){
    int minelement = array[0];
    for(int i = 1; i < n; i++){
        if(array[i] < minelement)
            minelement = array[i];
    }
    return minelement;
}

sommaArray(int array, int n){
    int somma = 0;
    for(int i = 0; i < n; i++){
        somma += array[i];
    }

    return somma;
}

mediaArray(int array, int n){
    int somma = 0
    double media = 0; 
    for(int i = 0; i < n; i++){
        somma += array[i];
    }
    media = somma / n;

    return media;
}

maxOccorrenza(){
    int nCorrente, occorrenzaCorrente = 0;

    for(int i = 0; i < n; i++){
        if(array[i] == nCorrente)
            occorrenzaCorrente++;
    }

}

