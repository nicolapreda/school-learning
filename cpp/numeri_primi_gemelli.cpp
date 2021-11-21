/*
    Autore: Nicola Preda
    Data: 18/11/21
    Classe: 3ID
    Funzionamento: Due numeri primi si dicono gemelli quando differiscono di due.
    Il programma calcola le coppie di numeri primi gemelli minori di 100.

*/

#include <iostream>

using namespace std;

int main()
{

    bool sonoGemelli;
    for (int n1 = 3, n2 = 5; n1 < 100, n2 < 100; n1++, n2++)
    {
        sonoGemelli = true;
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
                cout << "I numeri " << n1 << " e " << n2 << " sono gemelli" << endl;
            }
        }
    }
}