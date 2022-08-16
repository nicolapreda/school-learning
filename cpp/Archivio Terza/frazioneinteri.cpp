#include <iostream>

using namespace std;

int main()
{
    int a, b, resto, mcd;
    cout << "Inserisci il primo numero:" << endl;
    cin >> a;

    cout << "Inserisci il secondo numero" << endl;
    cin >> b;

    while (resto != 0)
    {
        if (a >= b)
        {
            resto = a % b;
        }
        else
        {
            resto = b % a;
        }

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

    a = a / mcd;
    b = b / mcd;
    cout << "Frazione in forma semplificata: " << a << " / " << b << endl;
    return 0;
}
