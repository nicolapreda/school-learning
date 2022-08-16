/*
    Autore: Nicola Preda
    Data: 4/11/21
    Classe: 3ID
    Funzionamento:Dato N il programma scrive a video i divisori primi di n


*/

#include <iostream>

using namespace std;

int main()
{
    int n, isPrimo;
    cout<<"Inserisci n\n";
    cin>>n;

    for (int div_1 = 1; div_1 <= n; div_1++)
    {
        if (n % div_1 == 0)
        {
            for (int div_2 = 2; div_2 < div_1; div_2++)
            {
                if (div_1%div_2 != 0)
                {
                    isPrimo = 1;
                }
                else{
                    isPrimo = 0;
                }
                
            }
            if (isPrimo == 1)
            {
                cout<<div_1<<endl;
            }
            
            
            
        }
        
    }
    
}