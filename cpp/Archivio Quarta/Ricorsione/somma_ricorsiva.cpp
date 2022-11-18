#include <iostream>
using namespace std;

int somma(int a[], int n)
{
    if (n == 0)
        return 0;
    else
        return a[n-1] + somma(a, n-1);
}

int main()
{
    int n;
    cout << "Quanti elementi vuoi inserire? ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Inserisci l'elemento " << i+1 << ": ";
        cin >> a[i];
    }
    cout << "La somma degli elementi e' " << somma(a, n) << endl;
    return 0;
}
