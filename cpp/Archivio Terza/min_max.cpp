
#include <iostream>

using namespace std;

int main()
{
    int n, min, max;

    for (int volte = 0;; volte++)
    {
        do
        {
            cout << "Inserisci un numero:" << endl;
            cin >> n;
        } while (n < 0);

        if (n == 0)
        {
            break;
        }

        if (volte == 0)
        {
            max = n;
            min = n;
        }
        else
        {
            if (n < min)
            {
                min = n;
            }

            else if (n > max)
            {
                max = n;
            }
        }
    }
    cout << "Numero minimo: " << min << endl;
    cout << "Numero massimo: " << max << endl;
}