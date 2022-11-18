/*scrivi una funzione ricorsiva che verifichi se un array di interi non ordinato contiene un elemento. il metodo restituisce true se l'elemento è stato trovato altrimenti restituisce false*/

#include <iostream>
using namespace std;

bool cerca(int a[], int n, int x)
{
    if (n == 0)
        return false;
    if (a[n - 1] == x)
        return true;
    return cerca(a, n - 1, x);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int x = 5;
    cout << cerca(a, n, x);
    return 0;
}