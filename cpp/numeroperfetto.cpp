#include <iostream>

using namespace std;

int main()
{
    int n, somma_div = 0;
    cout << "Inserisci il numero da controllare\n";
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            somma_div += i;
        }
    }
    if (somma_div == n)
    {
        cout << "Il numero da te inserito (" << n << ") è un numero perfetto!\n";
        return 0;
    }
    else
    {
        cout << "Il numero da te inserito (" << n << ") NON è un numero perfetto!\n";
        return 0;
    }
}