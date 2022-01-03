#include <iostream>
/*
    Autore: Nicola Preda
    Data: 6/11/21
    Classe: 3ID
    Funzionamento: Calcolo del MCD di due numeri tramite l'algoritmo di Euclide
    Maggiori informazioni sul funzionamento dell'algoritmo : https://it.wikipedia.org/wiki/Algoritmo_di_Euclide
*/


using namespace std;

int main()
{
    int a, b, resto, mcd;
    cout << "Inserisci il primo numero:" << endl;
    cin >> a;
    do
    {
        cout << "Inserisci il secondo numero (deve essere maggiore del primo da te inserito): " << endl;
        cin >> b;
    } while (b <= a);

    while (resto != 0)
    {
        resto = a % b;
        if (resto == 0)
        {
            mcd = b;
            break;
        }
        else
        {
            a = b;
            b = resto;
        }
    }
    cout<<"L'MCD dei due numeri è: "<<mcd<<endl;
    return 0;
}