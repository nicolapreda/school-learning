#include <iostream>

using namespace std;

int main()
{

    int valore1, valore2, n;
    cout << "Inserisci il primo valore:" << endl;
    cin >> valore1;

    cout << "Inserisci il secondo valore:" << endl;
    cin >> valore2;

    if (valore1 > valore2)
    {
        n = valore1 - valore2 - 1;
        cout << "I numeri interi compresi tra i due valori sono: " << n << endl;
    }
    else if (valore1 < valore2)
    {
        n = valore2 - valore1 - 1;
        cout << "I numeri interi compresi tra i due valori sono: " << n << endl;
    }
    else if (valore1 == valore2)
    {
        n = 0;
        cout << "I numeri interi compresi tra i due valori sono: " << n << endl;
    }
    return main();
}
