/*data una sequenza di interi forniti dall'utente(il valore 0 interrompe la digitazione), memorizzare i  numeri
positivi nel file positivi.txt e quelli negativi nel file negativi.txt*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int n;
    ofstream file_positivi("positivi.txt");
    ofstream file_negativi("negativi.txt");
    cout << "Inserisci una sequenza di numeri interi (0 per terminare): ";
    cin >> n;
    while(n != 0)
    {
        if(n > 0)
            file_positivi << n << endl;
        else
            file_negativi << n << endl;
        cin >> n;
    }
    file_positivi.close();
    file_negativi.close();
    return 0;
}