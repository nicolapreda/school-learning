//Scrivere un programma che scrive su un file binario le prime 10 potenze del 2. 
//L'utente può chiedere in input la potenza che viene letta in modo diretto dal file.


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
int main(){
    ofstream out("potenze.dat", ios::out|ios::binary);
    int potenza = 1;
    for(int i = 0; i < 10; i++){
        out.write((char*)&potenza, sizeof(int));
        potenza *= 2;
    }
    out.close();
    cout << "Inserisci la potenza da leggere: ";
    cin >> potenza;
    ifstream in("potenze.dat", ios::out|ios::binary);
    in.seekg((potenza - 1) * sizeof(int));
    in.read((char*)&potenza, sizeof(int));
    cout << "2^" << potenza << " = " << potenza << endl;
    in.close();
    return 0;
}