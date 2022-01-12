#include <iostream>

// Programma che data la misura dell'altezza disegna due triangolo rettangoli
//  IL primo pieno, il secondo vuoto
using namespace std;

int main()
{

    int h;

    cout << "Inserisci l'altezza" << endl;
    cin >> h;

    for (int r = 1; r <= h; r++)
    {

        for (int a = 1; a <= r; a++)
        {
            
            for (int s = 1; s < r; s++)
            {
                if (r == h)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }
            
        }

        cout << endl;
    }
}