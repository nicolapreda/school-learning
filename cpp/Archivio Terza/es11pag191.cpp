#include <iostream>

using namespace std;

// create struct called Auto
struct Auto
{
    char marca[20];
    int cilindrata;
    int anno;
    char cognome[20];
    char nome[20];
};

int main()
{
     int i, anno, tot_auto=0;

    Auto autosalone[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "--- Auto " << (i + 1) << endl;
        cout << "marca: ";
        cin >> autosalone[i].marca;
        cout << "cilindrata: ";
        cin >> autosalone[i].cilindrata;
        cout << "anno immatricolazione: ";
        cin >> autosalone[i].anno;
        cout << "cognome acquirente: ";
        cin >> autosalone[i].cognome;
        cout << "nome acquirente: ";
        cin >> autosalone[i].nome;
    }

    cout << endl
         << "Cognome proprietari auto di cilindrata maggiore di 1500 cc" << endl;
    for (i = 0; i < 10; i++)
        if (autosalone[i].cilindrata > 1500)
            cout << autosalone[i].cognome << endl;

    cout << endl
         << "Inserire anno immatricolazione: ";
    cin >> anno;
    for (i = 0; i < 10; i++)
        if (autosalone[i].anno == anno)
            tot_auto++;
    cout << "Nell'anno " << anno << " sono state immatricolate " << tot_auto << " auto" << endl;
}