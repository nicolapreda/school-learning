//scrivere una funzione ricorsiva che calcoli la potenza n-esima della sezione aurea (con n fornito come argomento)

#include <iostream>
using namespace std;

double sezione_aurea(int n)
{
    float phi = 1.618;
    if (n == 0)
        return 1;
    else
        return phi * sezione_aurea(n-1);
}


int main()
{
    int n;
    cout << "Inserisci un numero: ";
    cin >> n;
    cout << "La sezione aurea alla potenza " << n << " e' " << sezione_aurea(n) << endl;
    return 0;
}
