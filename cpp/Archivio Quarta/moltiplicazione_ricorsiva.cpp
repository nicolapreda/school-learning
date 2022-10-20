//moltiplicazione ricorsiva

#include <iostream>
using namespace std;

int moltiplicazione(int a[], int n)
{
    if (n == 0)
        return 1;
    else
        return a[n-1] * moltiplicazione(a, n-1);
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
    cout << "La moltiplicazione degli elementi e' " << moltiplicazione(a, n) << endl;
    return 0;
}
