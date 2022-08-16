#include <iostream>

using namespace std;

int main(){
    int k,n,n1,n2, counter;
    counter = 0;

    cout<<"Inserisci il prodotto finale\n";
    cin>>k;
    cout<<"Inserisci il numero di coppie di valori che vuoi inserire\n";
    cin>>n;
    while (n > 0)
    {
        cout<<"\nInserisci il primo numero della coppia\n";
        cin>>n1;
        cout<<"Inserisci il secondo numero della coppia\n";
        cin>>n2;
        if (n1 * n2 == k)
        {
            counter = counter + 1;
        }
        n=n-1;   
    }

    cout<<"Il numero di coppie che danno come prodotto "<<k<<" sono "<<counter<<endl;
    
}