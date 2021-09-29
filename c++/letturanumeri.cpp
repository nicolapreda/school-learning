#include <iostream>

using namespace std;

int main(){
    int n, somma, contatore;
    n = 1;
    while (n != 0)
    {
        cout<<"Inserisci un numero"<<endl;
        cin>>n;
        contatore = contatore + 1;
        somma = somma + n;
        
    }
    cout<<"La somma è "<<somma<<", i valori letti in tutto sono "<<contatore-1<<endl;   
    return 0;
}