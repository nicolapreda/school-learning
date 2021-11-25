#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, i, primo = 0;
    do{
        cout<<"Inserisci un numero compreso tra 10 e 100"<<endl;
        cin>>n;
    }
    while (n < 10 | n > 100);
    
    i = n;
    while (primo != 1)
    {
        
        for (int divisore = 2; divisore < i; divisore++)
        {
            if (i % divisore != 0)
            {
                primo = 1;
                
            }
            else{
                i++;
            }
            
        }  
    }
    
    
    for (int counter = 1; counter <= n; counter++)
    {
        
        cout<<i * counter<<endl;
    }
    
    
    
}