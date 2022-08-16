#include <iostream>

using namespace std;

int lsequenza(int n) {
    int counter = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
        {
             n /= 2;
        }
        else{
            n = (n * 3)+1;
        }
        counter++;
    }
    return counter;
    
}

int main(){
    int n1, n2, ltotale;
    cout<<"Inserisci il primo numero\n";
    cin>>n1;
    cout<<"Inserisci il secondo numero\n";
    cin>>n2;

    if (n2 > n1)
    {
        swap(n2, n1);
    }
    
    for (int i = n2; i <= n1; i++)
    {
        cout<<"Lunghezza della sequenza del numero "<<i<<": "<<lsequenza(i)<<endl;
    }
    
      

    return 0;   
}