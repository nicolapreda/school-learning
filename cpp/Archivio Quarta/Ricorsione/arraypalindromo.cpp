/*Sviluppare una funzione ricorsiva per calcolare se un array è palindromo.*/

#include <iostream>

using namespace std;

bool palindromo(int array[], int n);

int main()
{
    int array[100];
    int n;
    cout << "Inserisci la lunghezza dell'array: ";
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> array[i];
    if(palindromo(array, n))
        cout << "L'array è palindromo" << endl;
    else
        cout << "L'array non è palindromo" << endl;
    return 0;
}

bool palindromo(int array[], int n)
{
    if(n == 0 || n == 1)
        return true;
    if(array[0] == array[n - 1])
        return palindromo(array + 1, n - 2);
    return false;
}

