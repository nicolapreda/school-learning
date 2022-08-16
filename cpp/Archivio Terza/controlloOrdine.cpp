
#include <iostream>

using namespace std;

int main(){
    
    int n_valori, valore, precedente;
    bool crescente;

    crescente = true;
    n_valori = 0;


    cout<<"Scrivi il numero di valori che vuoi inserire"<<endl;
    cin>>n_valori;
    
    cout<<"Inserisci il valore"<<endl;
    cin>>precedente;
    
    n_valori = n_valori - 1;

    while (n_valori > 0)
    {
        //Prendo in ingresso il valore
        cout<<"Inserisci il valore"<<endl;
        cin>>valore;
        if (valore < precedente)
        {
            crescente = false;
        }

        precedente = valore;
        n_valori = n_valori - 1;

    }

    if (crescente == true)
    {
        cout<<"La tua sequenza è crescente!"<<endl;
        return main();
    }
    else{
        cout<<"La tua sequenza non è crescente!"<<endl;
        return main();
    }
    
    
}