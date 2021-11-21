/*
    Autore: Nicola Preda
    Data: 18/11/21
    Classe: 3ID
    Funzionamento: Disegna un rettangolo vuoto con n righe e m colonne.

*/
#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cout << "Inserisci il numero di righe\n";
    cin >> n;
    cout << "Inserisci il numero di colonne\n";
    cin >> m;
    //Devo fare la prima linea in base al numero di colonne
    for (int c_righe = 1; c_righe <= n; c_righe++)
    {
        for (int c_colonne = 1; c_colonne <= m; c_colonne++)
        {

            if (c_righe != 1 && c_righe != n)
            {
                if (c_colonne == 1 || c_colonne == m)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }
}