// stampa array ricorsivamente

#include <iostream>

using namespace std;

void stampaArrayDecrescente(int a[100], int n);
void stampaArrayCrescente(int a[100], int n);

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    stampaArrayDecrescente(a, 10);

    cout << endl;

    stampaArrayCrescente(a, 10);
    return 0;
}

void stampaArrayDecrescente(int a[100], int n)
{
    if (n == 0)
        return;
    else
    {
        cout << a[n - 1] << endl;
        stampaArrayDecrescente(a, n - 1);
    }
}

// stampa array in modo crescente

void stampaArrayCrescente(int a[100], int n)
{
    if (n == 0)
        return;
    else
    {
        stampaArrayCrescente(a, n - 1);
        cout << a[n] << endl;
    }
}

