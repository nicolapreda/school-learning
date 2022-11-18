#include <iostream>

using namespace std;

int sommaInteri(int n, int m);


int main()
{
    int n, m;
    cout << "Inserisci n(minore di m): ";
    cin >> n;
    cout << "Inserisci m(maggiore di n): ";
    cin >> m;


    cout << "La somma dei numeri compresi tra n e m  e': " << sommaInteri(n, m) << endl;
    return 0;
}


int sommaInteri(int n, int m){
    
    if(n == m)
        return n;
    else
        return n + sommaInteri(n + 1, m);
}