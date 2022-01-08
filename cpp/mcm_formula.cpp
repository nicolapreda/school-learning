#include <iostream>
using namespace std;

int main()
{

    int a, b, resto, mcd, mcm;
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
    cout<<b<<endl;
    mcm = (a * b) / mcd;
    cout << mcm;

    return 0;
}

