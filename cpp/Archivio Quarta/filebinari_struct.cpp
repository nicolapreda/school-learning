/*
Sviluppare un programma che scriva un elenco di strutture su file binario. 
I dati sono letti da tastiera e memorizzati anche su un array.

Esempio di struttura:
struct studente {
    char matricola[5];
    char cognome[20];
    char nome[20];
    float media;
};

Tramite la funzione seekg() posizionarsi sullo studente cercato e visualizzare i suoi dati.

*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct studente {
    char matricola[5];
    char cognome[20];
    char nome[20];
    float media;
};

int main()
{
    studente s[20];
    ofstream out("studenti.bin", ios::binary);
    int n;

    cout << "quanti studenti vuoi inserire? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Matricola: ";
        cin >> s[i].matricola;
        cout << "Cognome: ";
        cin >> s[i].cognome;
        cout << "Nome: ";
        cin >> s[i].nome;
        cout << "Media: ";
        cin >> s[i].media;
        out.write((char *)&s[i], sizeof(s[i]));
    }
    out.close();
    
    ifstream in("studenti.bin", ios::binary);
    char matricola[5];
    cout << "Matricola da cercare: ";
    cin >> matricola;
    for (int i = 0; i < 3; i++) {
        in.seekg(i * sizeof(s[i]), ios::beg);
        in.read((char *)&s[i], sizeof(s[i]));
        if (strcmp(s[i].matricola, matricola) == 0) {
            cout << "Matricola: " << s[i].matricola << "\t";
            cout << "Cognome: " << s[i].cognome << "\t";
            cout << "Nome: " << s[i].nome << "\t";
            cout << "Media: " << s[i].media << endl;
        }
    }
    in.close();
    return 0;
}

