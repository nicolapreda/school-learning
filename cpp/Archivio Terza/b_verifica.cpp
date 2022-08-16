/*
    Autore: Nicola Preda
    Data: 4/11/21
    Classe: 3ID
    Funzionamento: data una sequenza di 10 numeri interi inseriti
	dall’utente, calcola due somme, quella dei numeri dispari e quella dei numeri divisibili per 5.
	Se il numero inserito è negativo oppure maggiore di 100 viene ignorato
*/

#include <iostream>

using namespace std;

int main()
{

    int n, somma_dispari = 0, somma_div_5 = 0;
    //Ho dichiarato tutte le variabili con int perchè n sarà compresa tra 0 e 100, e le altre variabili rappresenteranno delle somme dei valori inseriti, che non supereranno mai il massimo numero rappresentabile a 32/64 bit.
    
    for (int numeri = 1; numeri <= 10; numeri++)
    {
        cout << "Inserisci un numero" << endl;
        cin>>n;
        
             if (n<0||n>100)
             {
                 n = 0;
             }
                
        
            if (n % 2 != 0)
            {
                somma_dispari += n;
            }
            if (n % 5 == 0)
            {
                somma_div_5 += n;
            }
        
    }
    cout<<"Somma numeri dispari: "<<somma_dispari<<endl;
    cout<<"Somma numeri divisibili per cinque: "<<somma_div_5<<endl;

}