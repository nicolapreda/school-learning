#include <iostream>

using namespace std;

int main()
{
    int n_1, n_2, somma_1 = 0, somma_2 = 0;
    cout << "Inserisci il primo numero:\n";
    cin >> n_1;
    cout << "Inserisci il secondo numero:\n";
    cin >> n_2;

    for (int i = 1; i < n_1; i++)
    {
        if (n_1 % i == 0)
        {
            somma_1 +=i;
        }
    }
    for (int x = 1; x < n_2; x++)
    {
        if (n_2 % x == 0)
        {
            somma_2 +=x;
        }
    }
    
    if (somma_1 == n_2 && somma_2 == n_1)
    {
        cout<<"I numeri sono amici\n";
        return 0;
    }else{
        cout<<"I numeri non sono amici\n";
    }

}