#include <iostream>

using namespace std;
bool isBisestile(int n){
    bool bisestile = false;

    if (n%4 == 0)
    {
        bisestile = true;
    }
    else if (n%1000 == 0)
    {
        bisestile = true;
    }
    else if (n%400 == 0)
    {
        bisestile = true;
    }
    return bisestile;
    
}


int main(){
    int n;

    cout<<"Inserisci l'anno interessato: \n";
    cin>>n;
    cout<<isBisestile(n)<<endl;
}