#include <iostream>

using namespace std;
int isPrimo(int n){
    bool isPrimo = true;
    for (int divisore = 2; divisore < n; divisore++)
    {
        if (n % divisore == 0)
        {
           isPrimo = false; 
        }
        
    }
    return isPrimo;
}

int main(){
    int n;
    cout<<"Inserisci il numero (0 se il numero non è primo, 1 se è primo)\n";
    cin>>n;
    cout<<isPrimo(n);
    
    return 0;
}