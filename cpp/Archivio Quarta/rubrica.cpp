/*gestire una rubrica che prende i dati da un file csv chiamato contatti.csv e li memorizza in una tabella di elementi aventi una struttura adeguata a contenere i dati descritti. il programma deve permettere di visualizzare i dati di tutti i contatti, di visualizzare i dati di un contatto cercato per nome, di aggiungere un nuovo contatto, di eliminare un contatto e di modificare i dati di un contatto. il programma deve scrivere i dati aggiornati nel file contatti.csv*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
struct contatto{
    string nome;
    string cognome;
    string telefono;
    string email;
};
void leggi(contatto tabella[], int &n);
void visualizza(contatto tabella[], int n);
void aggiungi(contatto tabella[], int &n);
void elimina(contatto tabella[], int &n);
void modifica(contatto tabella[], int n);
int main(){
    contatto tabella[100];
    int n;
    leggi(tabella, n);
    int scelta;
    do{
        cout << "1. Visualizza tutti i contatti" << endl;
        cout << "2. Visualizza un contatto" << endl;
        cout << "3. Aggiungi un contatto" << endl;
        cout << "4. Elimina un contatto" << endl;
        cout << "5. Modifica un contatto" << endl;
        cout << "6. Esci" << endl;
        cout << "Scelta: ";
        cin >> scelta;
        switch(scelta){
            case 1:
                visualizza(tabella, n);
                break;
            case 2:
                break;
            case 3:
                aggiungi(tabella, n);
                break;
            case 4:
                elimina(tabella, n);
                break;
            case 5:
                modifica(tabella, n);
                break;
            case 6:
                break;
            default:
                cout << "Scelta non valida" << endl;
        }
    }while(scelta != 6);
    return 0;
}
void leggi(contatto tabella[], int &n){
    ifstream in("contatti.csv");
    if(!in){
        cout << "Errore nell'apertura del file";
        exit(1);
    }
    n = 0;
    while(in >> tabella[n].nome >> tabella[n].cognome >> tabella[n].telefono >> tabella[n].email)
        n++;
    in.close();
}
void visualizza(contatto tabella[], int n){
    for(int i = 0; i < n; i++)
        cout << tabella[i].nome << " " << tabella[i].cognome << " " << tabella[i].telefono << " " << tabella[i].email << endl;
}
void aggiungi(contatto tabella[], int &n){
    cout << "Nome: ";
    cin >> tabella[n].nome;
    cout << "Cognome: ";
    cin >> tabella[n].cognome;
    cout << "Telefono: ";
    cin >> tabella[n].telefono;
    cout << "Email: ";
    cin >> tabella[n].email;
    n++;
}
void elimina(contatto tabella[], int &n){
    string nome;
    cout << "Nome: ";
    cin >> nome;
    int i = 0;
    while(i < n && tabella[i].nome != nome)
        i++;
    if(i == n)
        cout << "Contatto non trovato" << endl;
    else{
        for(int j = i; j < n - 1; j++)
            tabella[j] = tabella[j + 1];
        n--;
    }
}
void modifica(contatto tabella[], int n){
    string nome;
    cout << "Nome: ";
    cin >> nome;
    int i = 0;
    while(i < n && tabella[i].nome != nome)
        i++;
    if(i == n)
        cout << "Contatto non trovato" << endl;
    else{
        cout << "Nuovo nome: ";
        cin >> tabella[i].nome;
        cout << "Nuovo cognome: ";
        cin >> tabella[i].cognome;
        cout << "Nuovo telefono: ";
        cin >> tabella[i].telefono;
        cout << "Nuova email: ";
        cin >> tabella[i].email;
    }
}
