/*
Crea un programma c++ che, letti da riga di comando 2 argomenti, generi 4 figli che svolgano e restituiscano il risultato delle operazioni di somma, differenza, prodotto e divisione.
Il processo padre scriverà a video il risultato.

*/

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    int pid = getpid();
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int somma = a + b;
    int differenza = a - b;
    int prodotto = a * b;
    int divisione = a / b;
    int status;
    int w;
    for (int i = 0; i < 4; i++)
    {
        if (getpid() == pid)
        {
            pid = fork();
        }
    
    if (pid == 0)
    {
        switch (i)
        {
        case 0:
            cout << "Somma: " << somma << endl;
            break;
        case 1:
            cout << "Differenza: " << differenza << endl;
            break;
        case 2:
            cout << "Prodotto: " << prodotto << endl;
            break;
        case 3:
            cout << "Divisione: " << divisione << endl;
            break;
        default:
            break;
        }
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            w = wait(&status);
            if (WIFEXITED(status))
            {
                cout << "Processo " << w << " terminato con stato " << WEXITSTATUS(status) << endl;
            }
        }
    }}

    return 0;
}