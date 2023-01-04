/*chiedi all'utente di inserire un numero intero A compreso tra 5 e 45 (estremi esclusi), con relativo controllo, e un numero reale B maggiore di A (con relativo controllo). Chiedere all'utente A numeri reali e visualizzare se la loro somma è maggiore del valore B*/

#include <iostream>

using namespace std;

int main()
{
    int A;
    float B;
    do
    {
        cout << "Inserisci un numero intero compreso tra 5 e 45 (estremi esclusi): ";
        cin >> A;
    } while(A <= 5 || A >= 45);
    do
    {
        cout << "Inserisci un numero reale maggiore di " << A << ": ";
        cin >> B;
    } while(B <= A);
    float somma = 0;
    for(int i = 0; i < A; i++)
    {
        float n;
        cout << "Inserisci un numero reale: ";
        cin >> n;
        somma += n;
    }
    if(somma > B)
        cout << "La somma dei numeri inseriti è maggiore di " << B << endl;
    else
        cout << "La somma dei numeri inseriti non è maggiore di " << B << endl;
    return 0;
}

