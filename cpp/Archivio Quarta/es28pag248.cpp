/*si dispone in un file risultati.txt in formato csv di un elenco di nomi di studenti completati dal numero di matricola, dall'età e dal voto di una verifica scritta . dopo aver definito una tabella di elementi aventi una struttura adeguata a contenere dati descritti, scrivere nel file risultati_ordinati.txt i dati degli studenti ordinati in senso decrescente rispetto al voto conseguito*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
struct studente{
    string cognome;
    string nome;
    int matricola;
    int eta;
    int voto;
};
void leggi(studente tabella[], int &n);
void ordina(studente tabella[], int n);
void scrivi(studente tabella[], int n);
int main(){
    studente tabella[100];
    int n;
    leggi(tabella, n);
    ordina(tabella, n);
    scrivi(tabella, n);
    return 0;
}
void leggi(studente tabella[], int &n){
    ifstream in("risultati.txt");
    
    n = 0;
    while(in >> tabella[n].cognome >> tabella[n].nome >> tabella[n].matricola >> tabella[n].eta >> tabella[n].voto)
        n++;
    in.close();
}
void ordina(studente tabella[], int n){
    int i, j;
    studente temp;
    for(i = 0; i < n - 1; i++)
        for(j = i + 1; j < n; j++)
            if(tabella[i].voto < tabella[j].voto){
                temp = tabella[i];
                tabella[i] = tabella[j];
                tabella[j] = temp;
            }
}
void scrivi(studente tabella[], int n){
    ofstream out("risultati_ordinati.txt");
    
    for(int i = 0; i < n; i++)
        out << tabella[i].cognome << " " << tabella[i].nome << " " << tabella[i].matricola << " " << tabella[i].eta << " " << tabella[i].voto << endl;
    out.close();
}
