/*programma legge in input tre numeri e stampa quello medio*/
#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cout << "Inserisci tre numeri: ";
    cin >> a >> b >> c;
    if (a > b)
    {
        if (b > c)
            cout << "Il numero medio e' " << b << endl;
        else
        {
            if (a > c)
                cout << "Il numero medio e' " << c << endl;
            else
                cout << "Il numero medio e' " << a << endl;
        }
    }
    else
    {
        if (a > c)
            cout << "Il numero medio e' " << a << endl;
        else
        {
            if (b > c)
                cout << "Il numero medio e' " << c << endl;
            else
                cout << "Il numero medio e' " << b << endl;
        }
    }
    return 0;
}
