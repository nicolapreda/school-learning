/*
    Autore: Nicola Preda
    Data: 4/11/21
    Classe: 3ID
    Funzionamento: Dati due numeri interi
	positivi viene calcolato se sono due numeri primi gemelli.

*/

#include <iostream>

using namespace std;

int main()
{
    int n1, n2;
    bool sonoGemelli = true;
    cout << "Inserisci il primo numero: " << endl;
    cin >> n1;
    cout << "Inserisci il secondo numero: " << endl;
    cin >> n2;
    for (int divisore1 = 2; divisore1 < n1; divisore1++)
    {
        if (n1 % divisore1 == 0)
        {
            sonoGemelli = false;
        }
    }
    for (int divisore2 = 2; divisore2 < n2; divisore2++)
    {
        if (n2 % divisore2 == 0)
        {
            sonoGemelli = false;
        }
    }
    if (sonoGemelli == true)
    {
        if (n1 + 2 == n2 || n1 - 2 == n2)
        {
            cout << "I numeri sono gemelli" << endl;
        }
        else
        {
            cout << "I numeri non sono gemelli" << endl;
        }
    }

    else
    {
        cout << "I numeri non sono gemelli" << endl;
    }
}