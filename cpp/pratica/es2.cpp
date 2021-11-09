#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, somma = 0, valori = 0;
    float media;
    while (n != 0)
    {
        cout << "Inserisci n\n";
        cin >> n;

        somma += n;
        valori++;
    }

    media = somma / valori;

    cout<<"Somma: "<<somma<<endl;
    cout<<"Media: "<<media<<endl;
    return 0;
}