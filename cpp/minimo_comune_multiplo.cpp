#include <iostream>

using namespace std;

int main(){
    int n1, n2, max_divisore;
    cout<<"Inserisci il primo numero\n";
    cin>>n1;
    cout<<"Inserisci il secondo numero\n";
    cin>>n2;

    for(int i = 1; i<=n1; i++){
        if (n1%i == 0 && n2%i == 0)
        {
            max_divisore = i;
        }
        
    }
    cout<<"Il massimo comun divisore è: "<<max_divisore<<endl;
}