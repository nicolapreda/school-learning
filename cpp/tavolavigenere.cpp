#include <iostream>
#include <string.h>

using namespace std;

void inizializza(char matrice[26][26]){
    // initialize The Vigenère Cipher Encryption Matrix
    for (int i = 0, counter = 0; i < 26; i++, counter = 0 + i)
    {
        for (int j = 0; j < 26; j++, counter++)
        {
            if (65 + counter > 90)
            {
                counter = 0;
            }
            matrice[i][j] = 65 + counter;
        }
    }

}

void codifica(char chiaro[], char matrice[26][26], char chiave[]){
    char codificata[100];
    // codifica il messaggio in chiaro
    for (int i = 0, j = 0; i < strlen(chiaro); i++, j++)
    {
        codificata[i] = chiaro[i] - 'A';
        //chiave[i%strlen(chiave)] - 'A'
        cout<<codificata[i];
    }

}

void stampa(char matrice[26][26]){

    //print matrix
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    char chiaro[10] = "provaciao";
    char verme[4] = "abc";
    char tavolaVigenere[26][26];
    inizializza(tavolaVigenere);
    stampa(tavolaVigenere);
    codifica(chiaro,tavolaVigenere, verme);
    cout<<endl;
}
