#include <iostream>
#include <stdlib.h>    
#include <time.h>      

using namespace std;

int main()
{
    srand (time(NULL));
    int n, somma = 0;
    cout<<"Inserisci il numero di valori che vuoi sommare\n";
    cin>>n;

    for (int i = 0; i < n; i++)
    {
        
        int v1 = rand() % 100;
        for (size_t i = v1; i % 3 != 0; i++)
        {
            v1++;
        }
        
        somma += v1;
        
    }
    cout<<somma<<endl;
    return 0;
    
    
}