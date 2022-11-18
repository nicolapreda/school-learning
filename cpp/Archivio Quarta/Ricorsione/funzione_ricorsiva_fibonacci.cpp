
#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return 1;
    
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n;
    cout << "Inserisci un numero: ";
    cin >> n;
    cout << "Il numero di Fibonacci di " << n << " e' " << fibonacci(n) << endl;
    return 0;
}

