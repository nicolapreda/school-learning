#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float n;
    cout<<"Inserisci un valore reale"<<endl;
    cin>>n;
    int n_int = (int)n;
    if (n>0)
    {
        cout<<"Il valore è positivo\n";
    }
    else{
        cout<<"Il valore è negativo\n";

    }
    cout<<"Parte intera: "<<abs(n_int)<<endl;
    cout<<"Parte decimale: "<<abs(n-n_int)<<endl;
}