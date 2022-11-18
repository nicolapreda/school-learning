/*•Scrivere un programma che utilizzi una funzione per leggere da input un certo numero di valori int e li inserisca in un array allocato dinamicamente dalla funzione stessa.
La funzione deve restituire al main() il puntatore all'array dinamico creato. Stampare poi l'array nel main()*/

#include <iostream>

using namespace std;

int * leggiArray(int &n);

int * leggiArray(int &n)
{
    cout << "Quanti elementi vuoi inserire? ";
    cin >> n;
    int *array = new int[n];
    for(int i=0; i<n; i++)
    {
        cout << "Inserisci elemento " << i+1 << ": ";
        cin >> array[i];
    }
    return array;
}

int main()
{
    int n;
    int *array = leggiArray(n);
    for(int i=0; i<n; i++)
        cout << array[i] << " ";
    delete [] array;
    return 0;
}



