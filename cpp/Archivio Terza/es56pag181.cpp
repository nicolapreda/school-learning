#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void decROT13(char stringa[],int l){
    for(int i = 0; i < l; i++){
        stringa[i]+=13;
        if (stringa[i] > 122)
        {
            stringa[i] = stringa[i] - 122;
            stringa[i] += 96;
        }
        
    }
    cout<<stringa;
}

int main(){
    char parola[100];
    cout<<"Inserisci la stringa (caratteri minuscoli)\n";
    cin>> parola;

    int lung=strlen(parola);
    decROT13(parola, lung);
}