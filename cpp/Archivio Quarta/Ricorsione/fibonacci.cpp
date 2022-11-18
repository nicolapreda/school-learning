#include <iostream>
#include <fstream>
using namespace std;
long long int nChiamate = 0;

int fibonacci(int n)
{
    nChiamate++;
    if(n == 0 || n == 1)
        return 1;
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cout << "Inserisci la posizione del numero: ";
    cin >> n;
    fibonacci(n);
    cout << "Le chiamate ricorsive della funzione di fibonacci sono "  << nChiamate << endl;
    return 0;
}
