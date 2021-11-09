#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n1, n2, somma = 0;
    cout<<"Inserisci il primo valore intero"<<endl;
    cin>>n1;
    cout<<"Inserisci il secondo valore intero"<<endl;
    cin>>n2;
    for (int c = 0; c < n2; c++)
    {
        somma+=n1;
        cout<<somma<<endl;
    }
    
}