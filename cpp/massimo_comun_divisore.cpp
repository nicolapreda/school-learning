#include <iostream>

using namespace std;

int main(){
    int n1, n2, maxnumero, max_divisore;
    cout<<"Inserisci il primo numero\n";
    cin>>n1;
    cout<<"Inserisci il secondo numero\n";
    cin>>n2;
    
    if (n1>n2)
    {
        maxnumero = n1;
    }else{
        maxnumero = n2;
    }

    for (;maxnumero>=n1 || maxnumero>=n2; maxnumero++)
    {
        if(maxnumero % n1 == 0 && maxnumero% n2 == 0){
            max_divisore = maxnumero;
            break;
        }
    }
    cout<<max_divisore;
}