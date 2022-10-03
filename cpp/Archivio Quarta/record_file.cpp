/*Supponiamo di aver scritto n record su un file binario. 
Vogliamo inserire un nuovo record in una certa posizione 
Usare un secondo file per memorizzare  n+1 record.
*/

#include <iostream>
#include <fstream>
using namespace std;

struct record {
    int id;
    char nome[20];
    char cognome[20];
    int eta;
};

int main() {
    record r;
    int pos;
    fstream f1, f2;
    f1.open("file1.dat", ios::in | ios::out | ios::binary);
    f2.open("file2.dat", ios::out | ios::binary);
    cout << "Inserire la posizione in cui inserire il record: ";
    cin >> pos;
    f1.seekg((pos - 1) * sizeof(record), ios::beg);
    f1.read((char *) &r, sizeof(record));
    cout << "Inserire il nuovo record: " << endl;
    cout << "ID: ";
    cin >> r.id;
    cout << "Nome: ";
    cin >> r.nome;
    cout << "Cognome: ";
    cin >> r.cognome;
    cout << "Età: ";
    cin >> r.eta;
    f1.seekg(0, ios::beg);
    for (int i = 0; i < pos - 1; i++) {
        f1.read((char *) &r, sizeof(record));
        f2.write((char *) &r, sizeof(record));
    }
    f2.write((char *) &r, sizeof(record));
    f1.seekg(pos * sizeof(record), ios::beg);
    while (f1.read((char *) &r, sizeof(record)))
        f2.write((char *) &r, sizeof(record));
    f1.close();
    f2.close();
    remove("file1.dat");
    rename("file2.dat", "file1.dat");
    return 0;
}
