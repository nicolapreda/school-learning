#include <iostream>

using namespace std;
struct rec_Studente
{
    char cognome[20];
    char nome[20];
    char sesso;
    int anno_nascita;
    int italiano;
    int inglese;
    int matematica;
};

int piuFacile(rec_Studente classe[], float media_voti[], int n)
{
    int maxMateria;
    for (int i = 0; i < n; i++)
    {
        media_voti[0] += classe[i].italiano;
        media_voti[1] += classe[i].inglese;
        media_voti[2] += classe[i].matematica;
    }
    for (int i = 0; i < 3; i++){
        media_voti[i] /= n;
    }

    maxMateria = 0;
    for (int i = 1; i < 3; i++)
    {
        if (media_voti[i] > media_voti[maxMateria])
        {
            maxMateria = i;
        }
    }

    return maxMateria;
}

int main()
{
    // dichiarazione variabili
    int nstudenti, matFacile;
    rec_Studente classe[30];
    // materie registrate
    char materie[3][15] = {"Italiano", "Inglese", "Matematica"};
    // vettore per calcolare il voto medio delle tre materie
    float media_voti[3] = {0.0};

    cout << "inserire numero studenti classe (max 30): ";
    cin >> nstudenti;

    // salva i dati dei studenti all'interno della struct
    for (int i = 0; i < nstudenti; i++)
    {
        cout << "-------studente " << (i + 1) << endl;
        cout << "cognome: ";
        cin >> classe[i].cognome;
        cout << "nome: ";
        cin >> classe[i].nome;
        cout << "sesso: ";
        cin >> classe[i].sesso;
        cout << "anno nascita: ";
        cin >> classe[i].anno_nascita;
        cout << "voto Italiano: ";
        cin >> classe[i].italiano;
        cout << "voto Inglese: ";
        cin >> classe[i].inglese;
        cout << "voto Matematica: ";
        cin >> classe[i].matematica;
    }
    matFacile = piuFacile(classe, media_voti, nstudenti);
    cout << "Materia piu' facile " << materie[matFacile] << " con media " << media_voti[matFacile] << endl;
}