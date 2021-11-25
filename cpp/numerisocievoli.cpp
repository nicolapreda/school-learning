/*
    Autore: Nicola Preda
    Data: 12/11/21
    Classe: 3 ID
    Funzionamento: programma che calcola se n numeri in input sono socievoli. 

*/

#include <iostream>

using namespace std;

int main()
{
    int valori, n, first, somma_precedente = 0;
    bool socievoli = true;
    do
    {
        cout << "Inserisci il numero di valori che vuoi inserire(minimo due): \n";
        cin >> valori;

    } while (valori < 2);

    for (int c = 0; c < valori; c++)
    {
        cout << "Inserisci un numero\n";
        cin >> n;

        if (c == 0)
        {
            first = n;
        }
        else
        {
            if (somma_precedente != n)
            {
                socievoli = false;
            }
        }
        somma_precedente = 0;

        for (int d = 1; d < n; d++)
        {
            if (n % d == 0)
            {
                somma_precedente += d;
            }
        }
    }
    if (somma_precedente == first)
    {
        socievoli = true;
    }

    if (socievoli == true)
    {
        cout << "I numeri da te inseriti sono socievoli!\n";
    }
    else
    {
        cout << "I numeri da te inseriti NON sono socievoli!\n";
    }
}