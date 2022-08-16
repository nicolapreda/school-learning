#include <iostream>

using namespace std;

int main()
{
    int n1, n2, maxnumero, minnumero;
    cout << "Inserisci il primo numero\n";
    cin >> n1;
    cout << "Inserisci il secondo numero\n";
    cin >> n2;

    if (n1>=n2)
    {
        maxnumero = n1;
        minnumero = n2;
    }else{
        maxnumero = n2;
        minnumero = n1;
    }

    for (int i = minnumero; i <= maxnumero; i++)
    {
        for (int c = 1; c <= i; c++)
        {
            if (i % c == 0)
            {
                cout<<c<<" ";
            }
            
        }
        cout<<endl;
        
    }
    
}