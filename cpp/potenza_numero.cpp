#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int n, potenza = 0, esponente;
    cout<<"Inserisci un numero maggiore di 0"<<endl;
    cin>>n;

    for (int i = 0; potenza < n; i++)
    {
        potenza = pow(2, i);
        esponente = i;
        
    }
    if (potenza == n)
    {
        cout<<"Il numero "<<n<<" è una potenza di 2 e il suo esponente è "<<esponente<<endl;
    }
    else{
        cout<<"il numero "<<n<<" non è una potenza di 2"<<endl;
    }
    
    
}