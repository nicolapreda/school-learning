#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int valori, n, somma_precedente = 0;
    bool socievoli = true;
    cout << "Inserisci il numero di valori che vuoi inserire: \n";
    cin >> valori;
    for (int c = 0; c < valori; c++)
    {
        cout << "Inserisci un numero\n";
        cin >> n;

        if (somma_precedente != n)
        {
            socievoli = false;
        }
        somma_precedente = 0;
        
        for (int d = 1; d <= n; d++)
        {
            if (n % d == 0)
            {
                somma_precedente += d;
            }
        }
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